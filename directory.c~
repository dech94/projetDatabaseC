#include"directory.h"
struct directory_data;
struct directory;
void directory_data_print(const struct directory_data *data) {
	printf("- %s %s : %s\n", data->last_name, data->first_name, data->telephone);
	//printf("%s\n", data->first_name);
}

void directory_data_random(struct directory_data *data) {
	int lenght_last_name = (rand()%(NAME_LENGTH_MAX - NAME_LENGTH_MIN))+NAME_LENGTH_MIN+1;
	int lenght_first_name = (rand()%(NAME_LENGTH_MAX - NAME_LENGTH_MIN))+NAME_LENGTH_MIN+1;
	int index_char = 0;
	char tabvoy[]={'A','E','I','O','U'};
	char tabcons[]={'B','C','D','F','G','H','J','L','M','N','P','R','S','T','V'};
	for(int i=0; i<lenght_last_name; ++i){
		if(i%2!=0) {
			index_char=rand()%5;
			data->last_name[i]=tabvoy[index_char];
		}else{
			index_char=rand()%15;
			data->last_name[i]=tabcons[index_char];
		}
	}
	for(int j=0; j<lenght_first_name; ++j){
		if(j%2!=0) {
			index_char=rand()%5;
			data->first_name[j]=tabvoy[index_char];
		}else{
			index_char=rand()%15;
			data->first_name[j]=tabcons[index_char];
		}
	}
	for(int k=0; k<TELEPHONE_LENGTH;++k){
		int index_int=rand()%10;
		data->telephone[k]='0'+index_int;
	}
}

void directory_create(struct directory *self) {
	self->data = NULL;
	self->size = 0;
	self->capacity = 0;
}

void directory_destroy(struct directory *self) {
	for(int i=0; i<self->size; ++i){
		free(self->data[i]);	
	}
	free(self);
}

void grow(struct directory *self){ 
	assert(self);
	size_t capacity = self-> capacity;
	if(capacity==0){
		capacity=10;
		self->data=calloc(capacity,sizeof(struct directory_data *));
	}else{
		capacity*=2;
		struct directory_data **temp=calloc(capacity,sizeof(struct directory_data *));
		memcpy(temp,self->data,self->capacity * sizeof(struct directory_data *));
		free(self->data);
		self->data=temp;
	}
	self->capacity=capacity;
	//self->data=realloc(self->data, capacity * sizeof(struct directory_data *));
}

void directory_add(struct directory *self, struct directory_data *data) {
	if(self->size==self->capacity){
		grow(self);
	}		
	self->size++;
	self->data[(self->size)-1]=data;
}

void directory_random(struct directory *self, size_t n) {
	directory_create(self);
	for(int i=0;i<n;++i){
		struct directory_data *newData = malloc(sizeof(struct directory_data));
		directory_data_random(newData);
		directory_add(self,newData);
	}
}
