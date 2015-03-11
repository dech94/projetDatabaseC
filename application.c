#include"application.h"

struct directory_data;
void clean_newline(char *buf, size_t size){
  
	char *p = strchr(buf,'\n');
	if (p) {
		*p='\0';
		printf("OK\n");
	}else printf("KO\n");
buf[size]='\0';
}

void print_menu(){
	printf("What do you want to do?\n	1: Search by last name (not optimised)\n	2: Search by last name (optimised)\n	3: Search by first name\n 	4: Search by telephone\n	q: Quit\nYour choice:\n");	
}

int calc_time_interval(struct timeval begin, struct timeval end) {
	int t = end.tv_usec - begin.tv_usec;
	return t;
}

int main() {
	srand(time(NULL));
	struct timeval begin, end;
	gettimeofday(&begin, NULL);
	struct directory *dir = malloc(sizeof(struct directory));
	directory_create(dir);
	directory_random(dir,SIZE_OF_TAB);
	gettimeofday(&end, NULL);
	int time_exe = calc_time_interval(begin, end);
	printf("initialisation du repertoire en %d microsecondes\n", time_exe);
	gettimeofday(&begin, NULL);
	directory_sort (dir);
	gettimeofday(&end, NULL);
	time_exe = calc_time_interval(begin, end);
	printf("Tri du repertoire en %d microsecondes\n", time_exe);
	struct index* index_first_name = malloc(sizeof(struct index));
	index_create(index_first_name,index_first_name_hash);
	index_fill_with_directory(index_first_name, dir);
	struct index* index_telephone = malloc(sizeof(struct index));
	index_create(index_telephone,index_telephone_hash);
	index_fill_with_directory(index_telephone, dir);

	for(int i=0; i<SIZE_OF_TAB; ++i){
		directory_data_print(dir->data[i]);
	}
	char buf[BUFSIZE];
	for (;;) {
		print_menu();
		printf("> ");
		char *ret = fgets(buf, BUFSIZE, stdin);
		assert(ret && ret == buf);
		clean_newline(buf, BUFSIZE);
		char *search=malloc(BUFSIZE);
		char *searchbis=malloc(BUFSIZE);
		//char *search="BOBY
			//clean_newline(search, NAME_LENGTH_MAX);
		switch(buf[0]){
			case ('q'):
				exit(0);
				free(search);
				break;
			case ('1'):
				printf("entrer un nom\n");
				fgets(search, NAME_LENGTH_MAX+2, stdin);
				clean_newline(search, NAME_LENGTH_MAX);
				directory_search(dir, search);
				free(search);
				break;
			case ('2'):
				fgets(search, NAME_LENGTH_MAX+2, stdin);
				clean_newline(search, NAME_LENGTH_MAX);
				directory_search_opt(dir, search);
				free(search);
				break;
			case ('3'):
				fgets(search, NAME_LENGTH_MAX+2, stdin);
				clean_newline(search, NAME_LENGTH_MAX);
				index_search_by_first_name(index_first_name, search);
				free(search);
				break;
			case ('4'):
				fgets(searchbis, TELEPHONE_LENGTH+2, stdin);
printf("1 : %s \n", searchbis);
				clean_newline(searchbis, TELEPHONE_LENGTH);
printf("2 : %s \n", searchbis);
				index_search_by_telephone(index_telephone, searchbis);
printf("3 : %s \n", searchbis);
				free(searchbis);
				break;
			default : 
				printf("La valeur saisie est invalide (%c,%i,%c).\n", buf[0], (int) buf[0], ret[0]);
				printf("%i\n", ret==NULL);
				break;
		}
	}
	directory_destroy(dir);
	return 0;
}
