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

//tri quick sort

void directory_swap(struct directory *self, size_t i, size_t j) {
/*	assert(self);*/
/*	assert(self->data[i]);*/
/*	assert(self->data[j]);*/

  struct directory_data *tmp = self->data[i];
	self->data[i] = self->data[j];
	self->data[j] = tmp;
}

size_t directory_partition(struct directory *self, size_t i, size_t j) {
/*	assert(i);*/
/*	assert(j);*/
/*	assert(i <= j);*/
/*	assert(i >= 0);*/
/*	assert(j<= self->size);*/
  size_t pivot_index = i;
  const char *pivot = self->data[pivot_index]->last_name;
  directory_swap(self, pivot_index, j);
  size_t l = i;
  for (size_t k = i; k < j; ++k) {
    if (strcmp(self->data[k]->last_name, pivot) < 0) {
      directory_swap(self, k, l);
      l++;
    }
  }
  directory_swap(self, l, j);
  return l;
}

void directory_quick_sort_partial(struct directory *self, size_t i, size_t j) {
  if (i < j) {
    size_t p = directory_partition(self, i, j);
    if (p>i) {
    	directory_quick_sort_partial(self, i, p - 1);
    }
    if (p<j) {
    	directory_quick_sort_partial(self, p + 1, j);
    }
  }
}

void directory_sort (struct directory *self) {
	assert(self);
	assert(self->size >= 0);
	if( self->size != 0 ) {
		if( self->size - 1 == 0 ){
			return;
		}
		directory_quick_sort_partial(self,0,self->size-1);
	}
}

void directory_search_opt(const struct directory *self, const char *last_name) {
	assert(self);
	assert(self->size > 0);
	int stop = 0;
	int res = 0;
	size_t start = 0;
	size_t end = self->size-1;
	size_t mid;
	char *pivot;
	while (stop != 1) {
		if (start > end) {
			stop = 1;
		} else {
			mid = (start+end)/2;
			pivot = self->data[mid]->last_name;
			if (strcmp(pivot, last_name) == 0) {
				directory_data_print(self->data[mid]);
				stop = 1;
				res = 1;
			} else {
				if (strcmp(pivot, last_name) < 0) {
					end = mid-1;
				} else {
					start = mid+1;
				}
			}
		}
	}
	if (res == 0) {
		printf("Il n'y a aucun résultat.\n");
	}
}


