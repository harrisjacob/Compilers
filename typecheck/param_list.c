#include "param_list.h"

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){

	struct param_list* newParam;
	if(!(newParam = malloc(sizeof(struct param_list)))) return NULL;

	newParam->name = strdup(name);
	newParam->type = type;
	newParam->next = next;

	return newParam;

}

void param_list_print( struct param_list *a ){
	if(!a) return;
	printf(" %s: ", a->name);
	type_print(a->type);
	if(a->next){
		printf(",");
		param_list_print(a->next);
	}

}

struct param_list* param_list_copy(struct param_list *p){
	if(!p) return NULL;
	struct param_list* param_listCopy;
	return (!(param_listCopy = param_list_create(p->name, type_copy(p->type), param_list_copy(p->next)))) ? NULL : param_listCopy;
}

void param_list_delete(struct param_list *p){
	if(!p) return;
	param_list_delete(p->next); //Free the end of the list first
	free(p->name);
	type_delete(p->type);
	symbol_delete(p->symbol);
	free(p);
}