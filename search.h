#ifndef SEARCH_DATA_H
#define SEARCH_DATA_H
#include"directory.h"
void directory_search(const struct directory *self, const char *last_name);
void directory_sort (struct directory *self);
void directory_search_opt(const struct directory *self, const char *last_name);
#endif
