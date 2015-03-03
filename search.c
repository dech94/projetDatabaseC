#include"search.h"
struct directory_data;
struct directory;
void directory_search(const struct directory *self, const char *last_name) {
	for(int i=0; i<(self->size); ++i){
		char *tmp=self->data[i]->last_name;
		if(strcmp(tmp, last_name)){
			directory_data_print(self->data[i]);
		}
	}
}

void directory_sort (struct directory *self) {
	//TODO
}

void directory_search_opt(const struct directory *self, const char *last_name) {
	directory_search(self,last_name);
}

