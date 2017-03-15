#ifndef _RB_TREE_H_
#define _RB_TREE_H_

#include <stdbool.h>

#define RB_TREE_SUCCESS       0
#define RB_TREE_NO_MEMORY     (1 << 0)
#define RB_TREE_ALREADY_EXIST (1 << 1)
#define RB_TREE_NOT_EXIST     (1 << 2)

typedef struct rb_tree RBTree;

int rb_tree_create(RBTree **, size_t, void (*)(void *), int (*)(const void *, const void *));

void rb_tree_destroy(RBTree *);

void rb_tree_clear(RBTree *);

size_t rb_tree_sizeof(const RBTree *);

bool rb_tree_empty(const RBTree *);

size_t rb_tree_size(const RBTree *);

int rb_tree_insert(RBTree *, const void *);

int rb_tree_find(const RBTree *, const void *, void *);

const void *rb_tree_at(const RBTree *, const void *);

int rb_tree_erase(RBTree *, const void *);

#endif
