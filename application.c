#include"application.h"
struct directory;
struct directory_data;
void clean_newline(char *buf, size_t size){
	
}

void print_menu(){
	printf("What do you want to do?\n	1: Search by last name (not optimised)\n	2: Search by last name (optimised)\n	3: Search by first name\n 	4: Search by telephone\n	q: Quit\nYour choice:\n");	
}

int main() {
	srand(time(NULL));
	struct directory *dir = malloc(sizeof(struct directory));
	directory_create(dir);
	directory_random(dir,SIZE_OF_TAB);
	for(int i=0; i<SIZE_OF_TAB; ++i){
		directory_data_print(dir->data[i]);
	}
	print_menu();
	directory_destroy(dir);
	return 0;
}
