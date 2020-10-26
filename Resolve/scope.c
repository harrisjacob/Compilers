#include "scope.h"

int scope_enter(struct hash_table **stkPTR){

	struct hash_table* newHT;
	if(!(newHT = hash_table_create(0,0))){
		printf("Failed to create scope hash table");
		return 1;
	}

	if(*stkPTR){									//If a stack has been created
		newHT->prev = (*stkPTR);					//Parent new HT with top of stack
		(*stkPTR)->next = newHT;					//Child top of stack with new HT
		newHT->level = newHT->prev->level + 1;		//Set new HT level in stack
	}else{
		newHT->level = 0;							//Initialize stack level
	}
	(*stkPTR) = newHT;								//Move top of stack to new HT

	printf("Entering scope: %i\n", scope_level(*stkPTR));

	return 0;

}

void scope_leave(struct hash_table **stkPTR){
	printf("Exiting scope: %i\n", scope_level(*stkPTR));
	struct hash_table *newTop = (*stkPTR)->prev;
	if(newTop) newTop->next = NULL;
	free(*stkPTR);
	(*stkPTR) = newTop;
}

int scope_bind(const char *name, struct symbol *s, struct hash_table *ht){
	struct symbol* findSymbol;
	if(!(findSymbol = hash_table_lookup(ht, name))){

		if(!(hash_table_insert(ht, name, s))){
			printf("Failed to insert %s into hash table\n", name);
			return 1;
		}else{
			printf("%s declared as ", name);
			if(s->kind == SYMBOL_LOCAL){
				s->which = (ht->local_count)++;
				printf("local %i", s->which);
			}else if(s->kind == SYMBOL_PARAM){
				s->which = (ht->param_count)++;
				printf("param %i", s->which);
			}else{
				printf("global %s",name);
			}

			printf(" within scope %i\n", scope_level(ht));
		}

	}else{
		/* Functions can have as many declarations (prototypes) until they are defined.
		Testing d->code in scope will set the findSymbol->which field of functions.
		Anything that's not a function or is a function that is defined should throw error.
		*/
		if(!(findSymbol->type->kind==TYPE_FUNCTION) || (findSymbol->which == 1)){
			printf("Redeclaration of %s\n", name);
			return 1;
		}
	}

	return 0;
}

struct symbol* scope_lookup(const char *name, struct hash_table *ht){
	if(!ht) return NULL;
	struct symbol* lookupRet;
	if((lookupRet = (struct symbol*) hash_table_lookup(ht, name))){
		printf("%s resolves to ", name);
		switch(lookupRet->kind){
			case SYMBOL_LOCAL:
				printf("%s %i", "local", lookupRet->which);
				break;
			case SYMBOL_PARAM:
				printf("%s %i", "param", lookupRet->which);
				break;
			case SYMBOL_GLOBAL:
				printf("%s %s", "global", name);
				break;
			default:
				printf("variable of unknown scope.\n");
		}
		printf(" of scope %i\n", scope_level(ht));
		return lookupRet;
	}
	return scope_lookup(name, ht->prev); 
}

int scope_level(struct hash_table *ht){
	return ht->level;
}