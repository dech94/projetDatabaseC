#include"index.h"
struct index_bucket;
struct index;
struct directory_data;
struct directory;
struct index_bucket *index_bucket_add(struct index_bucket *self, const struct directory_data *data){
	assert(data);
	if( self == NULL ){
		struct index_bucket *newBucket = malloc(sizeof(struct index_bucket));
		newBucket->data=NULL;
		newBucket->next=NULL;
		newBucket->data = data;
		return newBucket;
	}else if( self->data == NULL ){
		self->data = data;
		self->next = NULL;
		return self;
	}else{
		struct index_bucket *newBucket = malloc(sizeof(struct index_bucket));
		newBucket->data=NULL;
		newBucket->next=NULL;
		newBucket->data = data;
		if( self->next == NULL ){
			newBucket->next = NULL;
			self->next = newBucket;
		}else{
			newBucket->next = self->next;
			self->next = newBucket;
		}
		return newBucket;
		}
}

void index_bucket_destroy(struct index_bucket *self){
	if( self != NULL )
	{
		index_bucket_destroy(self->next);
		free(self);
	}
}

typedef size_t (*index_hash_func_t)(const struct directory_data *data);

size_t fnv_hash(const char *key){
	const size_t FNV_OFFSET_BASIS = 2166136261;
	const size_t FNV_PRIME = 16777619;
	const size_t BYTES = strlen(key);
	size_t hash = FNV_OFFSET_BASIS;
	for(size_t i=0; i < BYTES; i++) {
		hash |= key[i];
		hash = hash * FNV_PRIME;
	}
	return hash;
}

size_t index_first_name_hash(const struct directory_data *data){
	return(fnv_hash(data->first_name));
}

size_t index_telephone_hash(const struct directory_data *data){
	return(fnv_hash(data->telephone));
}

void index_create(struct index *self, index_hash_func_t func){
	self->count = 0;
	self->size = 0;
	self->func = func;
	self->buckets = NULL;
}

void index_destroy(struct index *self){
	for(size_t i=0; i < self->size; i++){
		if( self->buckets[i] ){
			index_bucket_destroy(self->buckets[i]);
		}
	}
	free(self->buckets);
}

void index_bucket_rehash(struct index_bucket* self,struct index* target ){
	if( self != NULL ){
	index_bucket_rehash(self->next, target);
	index_add(target, self->data);
	free(self);
	}
}

void index_rehash(struct index *self){
	size_t size = self->size;
	if( self->buckets == NULL ){
		size = 10;
		self->buckets = calloc(size, sizeof(struct index_bucket *));
		for(size_t i=0; i < size; i++){
			self->buckets[i] = NULL;
		}
	}else{
		size *= 2;
		/* create tmp */
		struct index *tmp = calloc(size, sizeof(struct index));
		index_create(tmp, self->func);
		/* create tmp->buckets*/
		tmp->buckets = calloc(size, sizeof(struct index_bucket *));
		tmp->size = size;
		for( size_t i = 0; i < size; i++ ){
			tmp->buckets[i] = NULL;
		}
		/* add */
		for(size_t i = 0; i<self->size; i++){
			if( self->buckets[i] != NULL ){
				index_bucket_rehash(self->buckets[i],tmp);
			}
		}
		free(self->buckets);
		self->buckets = tmp->buckets;
		free(tmp);
	}
	self->size = size;
}

void index_add(struct index *self, const struct directory_data *data){
	assert(self);
	assert(data);
	if(self->buckets == NULL || ((float)self->count/(float)self->size) >= 0.5){
		index_rehash(self);
	}
	size_t i = self->func(data) % self->size;
	if( self->buckets[i] == NULL){
		self->buckets[i] = malloc(sizeof(struct index_bucket));
		self->buckets[i] -> data = NULL;
		self->buckets[i] -> next = NULL;
	}
	index_bucket_add( self->buckets[i], data );
	self->count++;
}

void index_fill_with_directory(struct index *self, const struct directory *dir){
	assert(self);
	assert(dir);
	for(size_t i = 0; i < dir->size; i++){
		index_add(self, dir->data[i]);
	}
}

void index_search_by_first_name(const struct index *self, const char *first_name){
	size_t i = fnv_hash(first_name)%self->size;
	struct index_bucket* it = self->buckets[i];
	int found = 0;
	while(it != NULL) {
		if(strcmp(it->data->first_name, first_name) == 0){
			directory_data_print(it->data);
			found++;
		}
		it = it->next;
	}
	if(found==0){
	printf("%s not found\n", first_name);
	}
}

void index_search_by_telephone(const struct index *self, const char *telephone){
	size_t i = fnv_hash(telephone)%self->size;
	struct index_bucket* it = self->buckets[i];
	int found = 0;
	while(it != NULL){
		if(strcmp(it->data->telephone, telephone) == 0){
			directory_data_print(it->data);
			found++;
		}
		it = it->next;
	}
	if(found==0){
		printf("%s not found\n", telephone);
	}
}


