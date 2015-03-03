#include"directory.h"
struct directory_data;
struct directory;
void directory_data_print(const struct directory_data *data) {
	printf("- %s %s: %s\n", data->last_name, data->first_name, data->telephone);
}

void directory_data_random(struct directory_data *data) {
	srand(time(NULL));
	int lenght_last_name = (rand()%(NAME_LENGTH_MAX - NAME_LENGTH_MIN))+NAME_LENGTH_MIN+1;
	int lenght_first_name = (rand()%(NAME_LENGTH_MAX - NAME_LENGTH_MIN))+NAME_LENGTH_MIN+1;
	int index_char = 0;
	for(int i=0; i<lenght_last_name; ++i){
		if(i%2!=0) {
			index_char=rand()%5;
			switch(index_char) {
				case(0) :
					data->last_name[i]='A';
					break;
				case(1) :
                                        data->last_name[i]='E';
                                        break;
				case(2) :
                                        data->last_name[i]='I';
                                        break;
				case(3) :
                                        data->last_name[i]='O';
                                        break;
				case(4) :
                                        data->last_name[i]='U';
                                        break;
			}
		}else{
			index_char=rand()%15;
			switch(index_char) {
                                case(0) :
                                        data->last_name[i]='B';
                                        break;
                                case(1) :
                                        data->last_name[i]='C';
                                        break;
                                case(2) :
                                        data->last_name[i]='D';
                                        break;
                                case(3) :
                                        data->last_name[i]='F';
                                        break;
                                case(4) :
                                        data->last_name[i]='G';
                                        break;
				case(5) :
                                        data->last_name[i]='H';
                                        break;
                                case(6) :
                                        data->last_name[i]='J';
                                        break;
                                case(7) :
                                        data->last_name[i]='L';
                                        break;
                                case(8) :
                                        data->last_name[i]='M';
                                        break;
                                case(9) :
                                        data->last_name[i]='N';
                                        break;
				case(10) :
                                        data->last_name[i]='P';
                                        break;
                                case(11) :
                                        data->last_name[i]='R';
                                        break;
                                case(12) :
                                        data->last_name[i]='S';
                                        break;
                                case(13) :
                                        data->last_name[i]='T';
                                        break;
                                case(14) :
                                        data->last_name[i]='V';
                                        break;
			}
		}
	}
	for(int i=0; i<(lenght_first_name+1); ++i){
		if(i%2!=0) {
			index_char=rand()%5;
			switch(index_char) {
				case(0) :
					data->first_name[i]='A';
					break;
				case(1) :
                                        data->first_name[i]='E';
                                        break;
				case(2) :
                                        data->first_name[i]='I';
                                        break;
				case(3) :
                                        data->first_name[i]='O';
                                        break;
				case(4) :
                                        data->first_name[i]='U';
                                        break;
			}
		}else{
			index_char=rand()%15;
			switch(index_char) {
                                case(0) :
                                        data->first_name[i]='B';
                                        break;
                                case(1) :
                                        data->first_name[i]='C';
                                        break;
                                case(2) :
                                        data->first_name[i]='D';
                                        break;
                                case(3) :
                                        data->first_name[i]='F';
                                        break;
                                case(4) :
                                        data->first_name[i]='G';
                                        break;
				case(5) :
                                        data->first_name[i]='H';
                                        break;
                                case(6) :
                                        data->first_name[i]='J';
                                        break;
                                case(7) :
                                        data->first_name[i]='L';
                                        break;
                                case(8) :
                                        data->first_name[i]='M';
                                        break;
                                case(9) :
                                        data->first_name[i]='N';
                                        break;
				case(10) :
                                        data->first_name[i]='P';
                                        break;
                                case(11) :
                                        data->first_name[i]='R';
                                        break;
                                case(12) :
                                        data->first_name[i]='S';
                                        break;
                                case(13) :
                                        data->first_name[i]='T';
                                        break;
                                case(14) :
                                        data->first_name[i]='V';
                                        break;
			}
		}
	}
	for(int i=0;i<=TELEPHONE_LENGTH;++i){
		data->telephone[i]=rand()%10;
	}
}

void directory_create(struct directory *self) {
	self->data = NULL;
	self->size = 0;
	self->capacity = 0;
}

void directory_destroy(struct directory *self) {
	free(self);
}

void grow(struct directory *self){ 
	assert(self->size==self->capacity);
	size_t capacity = self-> capacity;
	if(capacity==0){
		capacity=10;
		self->data=calloc(capacity,sizeof(struct directory_data));
	}else{
		capacity*=2;
		struct directory_data *data=calloc(capacity,sizeof(struct directory_data));
		memcpy(data,self->data,self->size * sizeof(struct directory_data));
		free(self->data);
		self->data=data;
	}
	self->capacity=capacity;
}

void directory_add(struct directory *self, struct directory_data *data) {
	grow(self);	
	assert(self->size!=0);
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
