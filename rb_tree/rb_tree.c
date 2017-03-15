#include <stdalign.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "rb_tree.h"

#define RED   false
#define BLACK true

typedef struct rb_tree_node RBTreeNode;

struct rb_tree_node
{
	RBTreeNode *parent;
	RBTreeNode *left;
	RBTreeNode *right;
	bool color;
	uint_least8_t data[];
};

struct rb_tree
{
	RBTreeNode *root;
	void (*destructor)(void *);
	int (*cmp)(const void *, const void *);
	size_t size;
	size_t count;
};

static RBTreeNode *sibling(const RBTreeNode *);
static RBTreeNode *sib(const RBTreeNode *, const RBTreeNode *);
static RBTreeNode *grandparent(const RBTreeNode *);
static RBTreeNode **link(const RBTreeNode *, RBTreeNode **);

static void rotate_left(RBTreeNode *, RBTreeNode **);
static void rotate_right(RBTreeNode *, RBTreeNode **);

static void rebalance_insert(RBTreeNode *, RBTreeNode **);
static void rebalance_delete(RBTreeNode *, RBTreeNode *, RBTreeNode **);

#define _RB_TREE_H_SAVE_

int rb_tree_create(RBTree ** restrict tree_ptr, size_t size, void (*destructor)(void *), int (*cmp)(const void *, const void *))
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree_ptr == NULL || !size || cmp == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	register RBTree *temp = aligned_alloc(alignof(RBTree), sizeof(RBTree));
	if (temp == NULL)
	{
		return RB_TREE_NO_MEMORY;
	}

	temp->root = NULL;
	temp->destructor = destructor;
	temp->cmp = cmp;
	temp->size = size;
	temp->count = 0u;

	*tree_ptr = temp;

	return RB_TREE_SUCCESS;
}

void rb_tree_destroy(RBTree * restrict tree)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	for (register RBTreeNode *node_ptr = tree->root; node_ptr != NULL;)
	{
		while (node_ptr->left != NULL || node_ptr->right != NULL)
		{
			if (node_ptr->left != NULL)
			{
				node_ptr = node_ptr->left;
			}
			else
			{
				node_ptr = node_ptr->right;
			}
		}

		if (node_ptr->parent != NULL)
		{
			if (node_ptr->parent->left == node_ptr)
			{
				node_ptr->parent->left = NULL;
			}
			else
			{
				node_ptr->parent->right = NULL;
			}
		}

		register RBTreeNode *temp = node_ptr;
		node_ptr = node_ptr->parent;
		if (tree->destructor != NULL)
		{
			tree->destructor(temp->data);
		}
		free(temp);
	}

	free(tree);
}

void rb_tree_clear(RBTree * restrict tree)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	for (register RBTreeNode *node_ptr = tree->root; node_ptr != NULL;)
	{
		while (node_ptr->left != NULL && node_ptr->right != NULL)
		{
			if (node_ptr->left != NULL)
			{
				node_ptr = node_ptr->left;
			}
			else
			{
				node_ptr = node_ptr->right;
			}
		}

		if (node_ptr->parent != NULL)
		{
			if (node_ptr->parent->left == node_ptr)
			{
				node_ptr->parent->left = NULL;
			}
			else
			{
				node_ptr->parent->right = NULL;
			}
		}

		register RBTreeNode *temp = node_ptr;
		node_ptr = node_ptr->parent;
		if (tree->destructor != NULL)
		{
			tree->destructor(temp->data);
		}
		free(temp);
	}

	tree->root = NULL;
	tree->size = 0u;
}

size_t rb_tree_sizeof(register const RBTree * restrict tree)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	return tree->size;
}

bool rb_tree_empty(register const RBTree * restrict tree)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	return !tree->count;
}

size_t rb_tree_size(register const RBTree * restrict tree)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	return tree->count;
}

int rb_tree_insert(RBTree * restrict tree, const void * restrict value)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL || value == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	register RBTreeNode *node_ptr = tree->root, **link_ptr = &tree->root, *parent_ptr = NULL;
	while (node_ptr != NULL)
	{
		register int cmp_result = tree->cmp(value, node_ptr->data);
		parent_ptr = node_ptr;
		if (cmp_result < 0)
		{
			link_ptr = &node_ptr->left;
			node_ptr = node_ptr->left;
		}
		else if (cmp_result > 0)
		{
			link_ptr = &node_ptr->right;
			node_ptr = node_ptr->right;
		}
		else
		{
			return RB_TREE_ALREADY_EXIST;
		}
	}

	node_ptr = aligned_alloc(alignof(RBTreeNode), sizeof(RBTreeNode) + tree->size);
	if (node_ptr == NULL)
	{
		return RB_TREE_NO_MEMORY;
	}

	node_ptr->parent = parent_ptr;
	node_ptr->left = node_ptr->right = NULL;
	node_ptr->color = RED;
	memcpy(node_ptr->data, value, tree->size);

	*link_ptr = node_ptr;

	++tree->count;

	rebalance_insert(node_ptr, &tree->root);

	return RB_TREE_SUCCESS;
}

int rb_tree_find(const RBTree * restrict tree, const void *value, void *buffer)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL || value == NULL || buffer == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	for (register const RBTreeNode *node_ptr = tree->root; node_ptr != NULL;)
	{
		register int cmp_result = tree->cmp(value, node_ptr->data);
		if (cmp_result < 0)
		{
			node_ptr = node_ptr->left;
		}
		else if (cmp_result > 0)
		{
			node_ptr = node_ptr->right;
		}
		else
		{
			memcpy(buffer, node_ptr->data, tree->size);

			return RB_TREE_SUCCESS;
		}
	}

	return RB_TREE_NOT_EXIST;
}

const void *rb_tree_at(const RBTree * restrict tree, const void * restrict value)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL || value == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	for (register const RBTreeNode *node_ptr = tree->root; node_ptr != NULL;)
	{
		register int cmp_result = tree->cmp(value, node_ptr->data);
		if (cmp_result < 0)
		{
			node_ptr = node_ptr->left;
		}
		else if (cmp_result > 0)
		{
			node_ptr = node_ptr->right;
		}
		else
		{
			return node_ptr->data;
		}
	}

	return NULL;
}

int rb_tree_erase(RBTree * restrict tree, const void * restrict value)
{
#	ifdef _RB_TREE_H_SAVE_
	if (tree == NULL || value == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	register RBTreeNode *node_ptr = tree->root, *parent_ptr = NULL, **link_ptr = &tree->root;
	while (node_ptr != NULL)
	{
		register int cmp_result = tree->cmp(value, node_ptr->data);
		if (cmp_result < 0)
		{
			parent_ptr = node_ptr;
			link_ptr = &node_ptr->left;
			node_ptr = node_ptr->left;
		}
		else if (cmp_result > 0)
		{
			parent_ptr = node_ptr;
			link_ptr = &node_ptr->right;
			node_ptr = node_ptr->right;
		}
		else
		{
			break;
		}
	}

	if (node_ptr == NULL)
	{
		return RB_TREE_NOT_EXIST;
	}

	if (tree->destructor != NULL)
	{
		tree->destructor(node_ptr->data);
	}
	if (node_ptr->left != NULL && node_ptr->right != NULL)
	{
		void *data = node_ptr->data;

		parent_ptr = node_ptr;
		link_ptr = &node_ptr->right;
		node_ptr = node_ptr->right;
		while (node_ptr->left != NULL)
		{
			parent_ptr = node_ptr;
			link_ptr = &node_ptr->left;
			node_ptr = node_ptr->left;
		}

		*link_ptr = node_ptr->right;
		if (node_ptr->right != NULL)
		{
			node_ptr->right->parent = parent_ptr;
		}
		memcpy(data, node_ptr->data, tree->size);
	}
	else
	{
		if (node_ptr->left != NULL)
		{
			*link_ptr = node_ptr->left;
			node_ptr->left->parent = parent_ptr;
		}
		else if (node_ptr->right != NULL)
		{
			*link_ptr = node_ptr->right;
			node_ptr->right->parent = parent_ptr;
		}
		else
		{
			*link_ptr = NULL;
		}
	}
	bool color = node_ptr->color;

	free(node_ptr);

	--tree->count;

	if (color == BLACK)
	{
		rebalance_delete(*link_ptr, parent_ptr, &tree->root);
	}

	return RB_TREE_SUCCESS;
}

inline static RBTreeNode *sib(register const RBTreeNode * restrict node_ptr, register const RBTreeNode * restrict parent_ptr)
{
	if (node_ptr == parent_ptr->left)
	{
		return parent_ptr->right;
	}
	else
	{
		return parent_ptr->left;
	}
}

inline static RBTreeNode *sibling(register const RBTreeNode * restrict node_ptr)
{
	if (node_ptr == node_ptr->parent->left)
	{
		return node_ptr->parent->right;
	}
	else
	{
		return node_ptr->parent->left;
	}
}

inline static RBTreeNode *grandparent(register const RBTreeNode * restrict node_ptr)
{
	return node_ptr->parent->parent;
}

inline static RBTreeNode **link(register const RBTreeNode * restrict node_ptr, register RBTreeNode ** restrict root)
{
	if (node_ptr->parent == NULL)
	{
		return root;
	}

	if (node_ptr == node_ptr->parent->left)
	{
		return &node_ptr->parent->left;
	}
	else
	{
		return &node_ptr->parent->right;
	}
}

inline static void rotate_left(register RBTreeNode * restrict node_ptr, register RBTreeNode ** restrict link_ptr)
{
	register RBTreeNode *temp = node_ptr->right;

	node_ptr->right = temp->left;
	if (temp->left != NULL)
	{
		temp->left->parent = node_ptr;
	}

	*link_ptr = temp;
	temp->parent = node_ptr->parent;

	node_ptr->parent = temp;
	temp->left = node_ptr;
}

inline static void rotate_right(register RBTreeNode * restrict node_ptr, register RBTreeNode ** restrict link_ptr)
{
	register RBTreeNode *temp = node_ptr->left;

	node_ptr->left = temp->right;
	if (temp->right != NULL)
	{
		temp->right->parent = node_ptr;
	}

	*link_ptr = temp;
	temp->parent = node_ptr->parent;

	node_ptr->parent = temp;
	temp->right = node_ptr;
}

inline static void rebalance_insert(register RBTreeNode * restrict node_ptr, register RBTreeNode ** restrict root)
{
	while (node_ptr->parent != NULL && node_ptr->parent->color == RED)
	{
		register RBTreeNode *parent_ptr = node_ptr->parent, *uncle = sibling(node_ptr->parent), *grand = grandparent(node_ptr);
		if (uncle != NULL && uncle->color == RED)
		{
			parent_ptr->color = uncle->color = BLACK;
			grand->color = RED;
			node_ptr = grand;
		}
		else
		{
			if (node_ptr == parent_ptr->right && parent_ptr == grand->left)
			{
				rotate_left(parent_ptr, &grand->left);
				node_ptr = parent_ptr;
				parent_ptr = node_ptr->parent;
			}
			else if (node_ptr == parent_ptr->left && parent_ptr == grand->right)
			{
				rotate_right(parent_ptr, &grand->right);
				node_ptr = parent_ptr;
				parent_ptr = node_ptr->parent;
			}

			parent_ptr->color = BLACK;
			grand->color = RED;
			register RBTreeNode **link_ptr = link(grand, root);
			if (node_ptr == parent_ptr->right && parent_ptr == grand->right)
			{
				rotate_left(grand, link_ptr);
			}
			else
			{
				rotate_right(grand, link_ptr);
			}
		}
	}
	(*root)->color = BLACK;
}

inline static void rebalance_delete(register RBTreeNode * restrict node_ptr, register RBTreeNode * restrict parent_ptr, register RBTreeNode ** restrict root)
{
	if (node_ptr != NULL && node_ptr->color == RED)
	{
		node_ptr->color = BLACK;
		return;
	}

	while (node_ptr != *root && (node_ptr == NULL || node_ptr->color == BLACK))
	{
		register RBTreeNode *s = sib(node_ptr, parent_ptr);
		if (s->color == RED)
		{
			parent_ptr->color = RED;
			s->color = BLACK;
			register RBTreeNode **link_ptr = link(parent_ptr, root);
			if (node_ptr == parent_ptr->left)
			{
				rotate_left(parent_ptr, link_ptr);
			}
			else
			{
				rotate_right(parent_ptr, link_ptr);
			}
		}
		s = sib(node_ptr, parent_ptr);
		if (parent_ptr->color == BLACK && s->color == BLACK && (s->left == NULL || s->left->color == BLACK) && (s->right == NULL || s->right->color == BLACK))
		{
			s->color = RED;
			node_ptr = parent_ptr;
			parent_ptr = node_ptr->parent;
			continue;
		}
		else if (parent_ptr->color == RED && s->color == BLACK && (s->left == NULL || s->left->color == BLACK) && (s->right == NULL || s->right->color == BLACK))
		{
			s->color = RED;
			parent_ptr->color = BLACK;
		}
		else
		{
			if (s->color == BLACK)
			{
				register RBTreeNode **link_ptr = link(s, root);
				if (node_ptr == parent_ptr->right && (s->left == NULL || s->left->color == BLACK) && (s->right != NULL && s->right->color == RED))
				{
					s->color = RED;
					s->right->color = BLACK;
					rotate_left(s, link_ptr);
				}
				else if (node_ptr == parent_ptr->left && (s->left != NULL && s->left->color == RED) && (s->right == NULL || s->right->color == BLACK))
				{
					s->color = RED;
					s->left->color = BLACK;
					rotate_right(s, link_ptr);
				}
			}

			s = sib(node_ptr, parent_ptr);
			s->color = parent_ptr->color;
			parent_ptr->color = BLACK;
			register RBTreeNode **link_ptr = link(parent_ptr, root);
			if (node_ptr == parent_ptr->left)
			{
				s->right->color = BLACK;
				rotate_left(parent_ptr, link_ptr);
			}
			else
			{
				s->left->color = BLACK;
				rotate_right(parent_ptr, link_ptr);
			}
		}
		break;
	}
}
#include <stdio.h>

size_t rb_tree_node_check(const RBTreeNode *);

size_t rb_tree_check(register const RBTree * restrict tree)
{
	if (tree->root != NULL && tree->root->color == RED)
	{
		printf("tree->root != NULL && tree->root->color == RED\n");
		exit(EXIT_FAILURE);
	}
	return rb_tree_node_check(tree->root);
}

size_t rb_tree_node_check(register const RBTreeNode * restrict node_ptr)
{
	if (node_ptr == NULL)
	{
		return 0u;
	}

	int *int_ptr = (int *) node_ptr->data;
	size_t delta = 0u;
	if (node_ptr->color == RED)
	{
		if ((node_ptr->left != NULL && node_ptr->left->color != BLACK) || (node_ptr->right != NULL && node_ptr->right->color != BLACK))
		{
			printf("node_ptr->left->color != BLACK || node_ptr->right->color != BLACK\n");
			printf("*(int *) node_ptr->data = %d\n", *int_ptr);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		delta = 1u;
	}

	size_t left = rb_tree_node_check(node_ptr->left), right = rb_tree_node_check(node_ptr->right);
	if (left != right)
	{
		printf("left != right\n");
		printf("*(int *) node_ptr->data = %d\n", *int_ptr);
		exit(EXIT_FAILURE);
	}

	return left + delta;
}
