#ifndef _B_SEARCH_H_SAVE_
#define _B_SEARCH_H_SAVE_

#define _B_SEARCH_H_SAVE_

void *b_search(const void *key, const void *base, size_t num, size_t size, int (compar)(const void *, const void *));

void *lower_bound(const void *key, const void *base, size_t num, size_t size, int (compar)(const void *, const void *));

void *upper_bound(const void *key, const void *base, size_t num, size_t size, int (compar)(const void *, const void *));

#endif
