#ifndef INDEX_DATA_H
#define INDEX_DATA_H
#include"search.h"
struct index_bucket {
const struct directory_data *data;
struct index_bucket *next;
};
typedef size_t (*index_hash_func_t)(const struct directory_data *data);
struct index {
	struct index_bucket **buckets;
	size_t count;
	size_t size;
	index_hash_func_t func;
};
struct index_bucket *index_bucket_add(struct index_bucket *self, const struct directory_data *data);
void index_bucket_destroy(struct index_bucket *self);
size_t fnv_hash(const char *key);
size_t index_first_name_hash(const struct directory_data *data);
size_t index_telephone_hash(const struct directory_data *data);
void index_create(struct index *self, index_hash_func_t func);
void index_destroy(struct index *self);
void index_rehash(struct index *self);
void index_add(struct index *self, const struct directory_data *data);
void index_fill_with_directory(struct index *self, const struct directory *dir);
void index_search_by_first_name(const struct index *self, const char *first_name);
void index_search_by_telephone(const struct index *self, const char *telephone);
#endif
