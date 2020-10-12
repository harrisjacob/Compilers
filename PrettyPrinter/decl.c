#include "decl.h"

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ){
	struct decl* newDecl;
	if(!(newDecl = malloc(sizeof(struct decl)))){
		printf("AST: Failed to allocate decl structure");
		return NULL;
	}

	newDecl->name = strdup(name);
	newDecl->type = type;
	newDecl->value = value;
	newDecl->code = code;
	newDecl->next = next;

	return newDecl;

}

void decl_print( struct decl *d, int indent ){
	if(!d) return;
	printf("%s: ", d->name);
	type_print(d->type);
	if(d->value){
		printf("=");
		expr_print(d->value);
	}
	if(d->code){
		printf("= {");
		stmt_print(d->code, indent);
		printf("}");
	}
	decl_print(d->next, indent);
}