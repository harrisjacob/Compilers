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

void decl_print( struct decl *d, int indent){
	if(!d) return;
	int i;
	for(i=0;i<indent;i++,printf("\t"));
	printf("%s: ", d->name);
	type_print(d->type);
	if(d->value){
		printf(" = ");
		expr_print(d->value);
	} else if(d->code){
		if(d->code->kind!=STMT_LIST){
			printf(" = {\n");
			stmt_print(d->code, indent+1);
			
			printf("}\n");
		}else{
			printf(" = ");
			stmt_print(d->code, indent+1);
		}
	}

	if(!(d->code && d->code->kind!=STMT_LIST)){
		printf(";\n");
	}
	
	

	decl_print(d->next, indent);
}