#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#define AVL_TREE_SUCCESS       0
#define AVL_TREE_NO_MEMORY     (1 << 0)
#define AVL_TREE_ALREADY_EXIST (1 << 1)
#define AVL_TREE_NOT_EXIST     (1 << 2)

#include <stdbool.h>

typedef struct avl_tree AvlTree;

int avl_tree_create(AvlTree **, size_t, void (*)(void *), int (*)(const void *, const void *));

void avl_tree_destroy(AvlTree *);

void avl_tree_clear(AvlTree *);

size_t avl_tree_sizeof(const AvlTree *);

bool avl_tree_empty(const AvlTree *);

size_t avl_tree_size(const AvlTree *);

int avl_tree_insert(AvlTree *, const void *);

int avl_tree_find(const AvlTree *, const void *, void *);

const void *avl_tree_at(const AvlTree *, const void *);

int avl_tree_erase(AvlTree *, const void *);

#endif
