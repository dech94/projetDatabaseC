#include"index.h"
struct index_bucket;
struct index;
struct index_bucket *index_bucket_add(struct index_bucket *self, const struct directory_data *data){
	 /* On crée un nouvel élément */
    index_bucket* newBucket = malloc(sizeof(index_bucket));
    /* On assigne la valeur au nouvel élément */
    nouvelElement->val = valeur;
    /* On ajoute en fin, donc aucun élément ne va suivre */
    nouvelElement->nxt = NULL;
    if(liste == NULL){
        /* Si la liste est videé il suffit de renvoyer l'élément créé */
        return nouvelElement;
    }else{
        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        element* temp=liste;
        while(temp->nxt != NULL){
            temp = temp->nxt;
        }
        temp->nxt = nouvelElement;
        return liste;
    }
}

void index_bucket_destroy(struct index_bucket *self){

}

typedef size_t (*index_hash_func_t)(const struct directory_data *data);

size_t fnv_hash(const char *key){
return 0;
}

size_t index_first_name_hash(const struct directory_data *data){
return 0;
}

size_t index_telephone_hash(const struct directory_data *data){
return 0;
}

void index_create(struct index *self, index_hash_func_t func){

}

void index_destroy(struct index *self){

}

void index_rehash(struct index *self){

}

void index_add(struct index *self, const struct directory_data *data){

}

void index_fill_with_directory(struct index *self, const struct directory *dir){

}

void index_search_by_first_name(const struct index *self, const char *first_name){

}

void index_search_by_telephone(const struct index *self, const char *telephone){

}

