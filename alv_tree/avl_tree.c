#include <stdalign.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "avl_tree.h"

typedef struct avl_tree_node AvlTreeNode;

struct avl_tree_node
{
	AvlTreeNode *parent;
	AvlTreeNode *left;
	AvlTreeNode *right;
	int_least8_t balance;
	uint_least8_t data[];
};

struct avl_tree
{
	AvlTreeNode *root;
	void (*destructor)(void *);
	int (*cmp)(const void *, const void *);
	size_t size;
	size_t count;
};

static AvlTreeNode *rotate_left(AvlTreeNode *, const AvlTreeNode **);
static AvlTreeNode *rotate_right(AvlTreeNode *, const AvlTreeNode **);
static AvlTreeNode *rotate_right_left(AvlTreeNode *, const AvlTreeNode **);
static AvlTreeNode *rotate_left_right(AvlTreeNode *, const AvlTreeNode **);

static AvlTreeNode *rebalance(AvlTreeNode *, const AvlTreeNode **);

#define _AVL_TREE_H_SAVE_

int avl_tree_create(AvlTree ** restrict tree_ptr, size_t size, void (*destructor)(void *), int (*cmp)(const void *, const void *))
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree_ptr == NULL || !size || cmp == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	register AvlTree *temp = aligned_alloc(alignof(AvlTree), sizeof(AvlTree));
	if (temp == NULL)
	{
		return AVL_TREE_NO_MEMORY;
	}

	temp->root = NULL;
	temp->destructor = destructor;
	temp->cmp = cmp;
	temp->size = size;
	temp->count = 0u;

	*tree_ptr = temp;

	return AVL_TREE_SUCCESS;
}

void avl_tree_destroy(AvlTree * restrict tree)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	for (register AvlTreeNode *node_ptr = tree->root; node_ptr != NULL;)
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

		register AvlTreeNode *temp = node_ptr;
		node_ptr = node_ptr->parent;
		if (tree->destructor != NULL)
		{
			tree->destructor(temp->data);
		}
		free(temp);
	}

	free(tree);
}

void avl_tree_clear(AvlTree * restrict tree)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	for (register AvlTreeNode *node_ptr = tree->root; node_ptr != NULL;)
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

		register AvlTreeNode *temp = node_ptr;
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

size_t avl_tree_sizeof(register const AvlTree * restrict tree)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	return tree->size;
}

bool avl_tree_empty(register const AvlTree * restrict tree)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	return !tree->count;
}

size_t avl_tree_size(register const AvlTree * restrict tree)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	return tree->count;
}

int avl_tree_insert(AvlTree * restrict tree, const void * restrict value)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL || value == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	register AvlTreeNode *node_ptr = tree->root, **link_ptr = &tree->root, *parent_ptr = NULL;
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
			return AVL_TREE_ALREADY_EXIST;
		}
	}

	node_ptr = aligned_alloc(alignof(AvlTreeNode), sizeof(AvlTreeNode) + tree->size);
	if (node_ptr == NULL)
	{
		return AVL_TREE_NO_MEMORY;
	}

	node_ptr->parent = parent_ptr;
	node_ptr->left = node_ptr->right = NULL;
	node_ptr->balance = 0;
	memcpy(node_ptr->data, value, tree->size);

	*link_ptr = node_ptr;

	++tree->count;

	for (; parent_ptr != NULL; node_ptr = parent_ptr, parent_ptr = node_ptr->parent)
	{
		if (node_ptr == parent_ptr->left)
		{
			--parent_ptr->balance;
		}
		else
		{
			++parent_ptr->balance;
		}
		if (parent_ptr->balance < -1 || parent_ptr->balance > 1)
		{
			if (parent_ptr->parent != NULL)
			{
				if (parent_ptr == parent_ptr->parent->left)
				{
					link_ptr = &parent_ptr->parent->left;
				}
				else
				{
					link_ptr = &parent_ptr->parent->right;
				}
			}
			else
			{
				link_ptr = &tree->root;
			}
			parent_ptr = rebalance(parent_ptr, (const AvlTreeNode **) link_ptr);
		}
		if (!parent_ptr->balance)
		{
			break;
		}
	}

	return AVL_TREE_SUCCESS;
}

int avl_tree_find(const AvlTree * restrict tree, const void *value, void *buffer)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL || value == NULL || buffer == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	for (register const AvlTreeNode *node_ptr = tree->root; node_ptr != NULL;)
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

			return AVL_TREE_SUCCESS;
		}
	}

	return AVL_TREE_NOT_EXIST;
}

const void *avl_tree_at(const AvlTree * restrict tree, const void * restrict value)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL || value == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	for (register const AvlTreeNode *node_ptr = tree->root; node_ptr != NULL;)
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

int avl_tree_erase(AvlTree * restrict tree, const void * restrict value)
{
#	ifdef _AVL_TREE_H_SAVE_
	if (tree == NULL || value == NULL)
	{
		exit(EXIT_FAILURE);
	}
#	endif

	register AvlTreeNode *node_ptr = tree->root, *parent_ptr = NULL, **link_ptr = &tree->root;
	while (node_ptr != NULL)
	{
		int cmp_result = tree->cmp(value, node_ptr->data);
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
		return AVL_TREE_NOT_EXIST;
	}

	if (tree->destructor != NULL)
	{
		tree->destructor(node_ptr->data);
	}
	if (node_ptr->left != NULL && node_ptr->right != NULL)
	{
		void *data = node_ptr->data;

		parent_ptr = node_ptr;
		if (node_ptr->balance >= 0)
		{
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
		}
		else
		{
			link_ptr = &node_ptr->left;
			node_ptr = node_ptr->left;
			while (node_ptr->right != NULL)
			{
				parent_ptr = node_ptr;
				link_ptr = &node_ptr->right;
				node_ptr = node_ptr->right;
			}

			*link_ptr = node_ptr->left;
			if (node_ptr->left != NULL)
			{
				node_ptr->left->parent = parent_ptr;
			}
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
	free(node_ptr);

	--tree->count;

	if (parent_ptr->left == NULL && parent_ptr->right == NULL)
	{
		parent_ptr->balance = 0;
		node_ptr = parent_ptr;
		parent_ptr = parent_ptr->parent;
	}
	else
	{
		node_ptr = *link_ptr;
	}
	for (; parent_ptr != NULL; node_ptr = parent_ptr, parent_ptr = node_ptr->parent)
	{
		if (node_ptr == parent_ptr->left)
		{
			++parent_ptr->balance;
		}
		else
		{
			--parent_ptr->balance;
		}
		if (parent_ptr->balance < -1 || parent_ptr->balance > 1)
		{
			if (parent_ptr->parent != NULL)
			{
				if (parent_ptr == parent_ptr->parent->left)
				{
					link_ptr = &parent_ptr->parent->left;
				}
				else
				{
					link_ptr = &parent_ptr->parent->right;
				}
			}
			else
			{
				link_ptr = &tree->root;
			}
			parent_ptr = rebalance(parent_ptr, (const AvlTreeNode **) link_ptr);
		}
		if (parent_ptr->balance)
		{
			break;
		}
	}

	return AVL_TREE_SUCCESS;
}

inline static AvlTreeNode *rotate_left(register AvlTreeNode * restrict node_ptr, register const AvlTreeNode ** restrict link_ptr)
{
	register AvlTreeNode *temp = node_ptr->right;

	node_ptr->right = temp->left;
	if (temp->left != NULL)
	{
		temp->left->parent = node_ptr;
	}

	*link_ptr = temp;
	temp->parent = node_ptr->parent;

	node_ptr->parent = temp;
	temp->left = node_ptr;

	if (!temp->balance)
	{
		node_ptr->balance = 1;
		temp->balance = -1;
	}
	else
	{
		node_ptr->balance = 0;
		temp->balance = 0;
	}

	return temp;
}

inline static AvlTreeNode *rotate_right(register AvlTreeNode * restrict node_ptr, register const AvlTreeNode ** restrict link_ptr)
{
	register AvlTreeNode *temp = node_ptr->left;

	node_ptr->left = temp->right;
	if (temp->right != NULL)
	{
		temp->right->parent = node_ptr;
	}

	*link_ptr = temp;
	temp->parent = node_ptr->parent;

	node_ptr->parent = temp;
	temp->right = node_ptr;

	if (!temp->balance)
	{
		node_ptr->balance = -1;
		temp->balance = 1;
	}
	else
	{
		node_ptr->balance = 0;
		temp->balance = 0;
	}

	return temp;
}

inline static AvlTreeNode *rotate_right_left(register AvlTreeNode * restrict node_ptr, register const AvlTreeNode ** restrict link_ptr)
{
	register AvlTreeNode *temp = node_ptr->right, *local_temp = node_ptr->right->left;

	node_ptr->right = local_temp->left;
	if (local_temp->left != NULL)
	{
		local_temp->left->parent = node_ptr;
	}

	temp->left = local_temp->right;
	if (local_temp->right != NULL)
	{
		local_temp->right->parent = temp;
	}

	*link_ptr = local_temp;
	local_temp->parent = node_ptr->parent;

	node_ptr->parent = local_temp;
	local_temp->left = node_ptr;

	temp->parent = local_temp;
	local_temp->right = temp;

	if (local_temp->balance < 0)
	{
		node_ptr->balance = 0;
		temp->balance = 1;
	}
	else if (local_temp->balance > 0)
	{
		node_ptr->balance = -1;
		temp->balance = 0;
	}
	else
	{
		node_ptr->balance = 0;
		temp->balance = 0;
	}
	local_temp->balance = 0;

	return local_temp;
}

inline static AvlTreeNode *rotate_left_right(register AvlTreeNode * restrict node_ptr, register const AvlTreeNode ** restrict link_ptr)
{
	register AvlTreeNode *temp = node_ptr->left, *local_temp = node_ptr->left->right;

	node_ptr->left = local_temp->right;
	if (local_temp->right != NULL)
	{
		local_temp->right->parent = node_ptr;
	}

	temp->right = local_temp->left;
	if (local_temp->left != NULL)
	{
		local_temp->left->parent = temp;
	}

	*link_ptr = local_temp;
	local_temp->parent = node_ptr->parent;

	node_ptr->parent = local_temp;
	local_temp->right = node_ptr;

	temp->parent = local_temp;
	local_temp->left = temp;

	if (local_temp->balance < 0)
	{
		node_ptr->balance = 1;
		temp->balance = 0;
	}
	else if (local_temp->balance > 0)
	{
		node_ptr->balance = 0;
		temp->balance = -1;
	}
	else
	{
		node_ptr->balance = 0;
		temp->balance = 0;
	}
	local_temp->balance = 0;

	return local_temp;
}

inline static AvlTreeNode *rebalance(register AvlTreeNode * restrict node_ptr, register const AvlTreeNode ** restrict link_ptr)
{
	register AvlTreeNode *result;
	if (node_ptr->balance < -1)
	{
		if (node_ptr->left->balance > 0)
		{
			result = rotate_left_right(node_ptr, link_ptr);
		}
		else
		{
			result = rotate_right(node_ptr, link_ptr);
		}
	}
	else
	{
		if (node_ptr->right->balance < 0)
		{
			result = rotate_right_left(node_ptr, link_ptr);
		}
		else
		{
			result = rotate_left(node_ptr, link_ptr);
		}
	}

	return result;
}
