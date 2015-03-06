#include"search.h"
struct directory_data;
struct directory;
void directory_search(const struct directory *self, const char *last_name) {
	for(int i=0; i<(self->size); ++i){
		if(strcmp(self->data[i]->last_name, last_name)){
			directory_data_print(self->data[i]);
		}
	}
}

void directory_sort (struct directory *self) {
	//TODO
	assert(self);
	assert(self->size >= 0);
	if( self->size != 0 ){
		if( self->size - 1 == 0 ){
			return;
		}
		for(size_t i = 1; i <= self->size - 1; i++) {
			struct directory_data* tmp = self->data[i];
			size_t j = i;
			while(j > 0 && strcmp( self->data[j-1]->last_name, tmp->last_name ) > 0 ){
				self->data[j]= self->data[j-1];
				--j;
			}
			self->data[j] = tmp;
		}
	}
}

void directory_search_opt(const struct directory *self, const char *last_name) {
	directory_search(self,last_name);
}

