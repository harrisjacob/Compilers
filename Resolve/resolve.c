#include "resolve.h"


int resolve_tree(struct decl* tree){
	struct hash_table* basePTR, *stkPTR;

	int error_state = 0;

	if(!(basePTR = hash_table_create(0,0))){
		printf("Failed to create global scope hash table");
		return 1;
	}

	printf("Global hash table created!\n");

	stkPTR = basePTR;
	struct symbol* newSym;

	while(tree){

		if(!(newSym = symbol_create(SYMBOL_GLOBAL, tree->type, tree->name))){
			printf("Symbol create failed!\n");
			return 1;
		}

		if(!(hash_table_lookup(stkPTR, tree->name))){

			if(!(hash_table_insert(stkPTR,tree->name, newSym))){
				printf("Insert symbol into global scope failed\n");
			}else{
				printf("%s was inserted into global scope!\n", tree->name);
			}
	
			if(tree->type && (tree->type->kind == TYPE_FUNCTION)){
				printf("Going into function!\n");
			}

		}else{
			printf("Redeclaration of %s\n", tree->name);
			error_state = 1;
		}


		// if(tree->type==TYPE_FUNCTION){
		// 	if(resolve_function(tree, &stkPTR)){
		// 		printf("Something went wrong!\n");
		// 	}
		// }else{
		// 	symbol_create(SYMBOL_GLOBAL, tree->type, tree->name);
		// }

		tree=tree->next;
	}

	return error_state;

}

int resolve_function(struct decl* func, struct hash_table **stkPTR){


	struct hash_table *funcScope;
	if(!(funcScope = hash_table_create(0,0))){
		printf("Failed to create function scope hash table");
		return 1;
	}

	printf("Function hash table created!\n");
	//Move new hashtable to top of stack
	/*
	(*stkPTR)->next = funcScope;
	(*stkPTR) = funcScope;
	*/
	return 0;
}