#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

#define QUEUE_SUCCESS 0
#define QUEUE_NOMEM 1
#define QUEUE_EMPTY 2

typedef struct queue Queue;

int queue_create(Queue ** restrict, size_t);

void queue_destroy(Queue * restrict);

void queue_clear(Queue * restrict);

size_t queue_sizeof(const Queue * restrict);

bool queue_empty(const Queue * restrict);

size_t queue_size(const Queue * restrict);

int queue_push(Queue * restrict, const void *);

int queue_top(const Queue * restrict, void *);

void *queue_data(const Queue * restrict);

int queue_pop(Queue * restrict);

#endif
