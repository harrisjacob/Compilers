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

	printf("Entering scope level: %i\n", scope_level(*stkPTR));

	return 0;

}

void scope_leave(struct hash_table **stkPTR){
	printf("Exiting scope level: %i\n", scope_level(*stkPTR));
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
				s->which = (ht->localParam_count)++;
				printf("local %i", s->which);
			}else if(s->kind == SYMBOL_PARAM){
				s->which = (ht->localParam_count)++;
				printf("param %i", s->which);
			}else{
				printf("global %s",name);
			}

			printf(" within scope level %i\n", scope_level(ht));
		}

	}else{
		 //Functions are a bit of an exception that is handled by scope_defined later
		if(!(findSymbol->type->kind==TYPE_FUNCTION)){
			scope_redeclared(name, findSymbol, s);
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

void scope_redeclared(const char* name, struct symbol* first, struct symbol* next){
	printf("Declaration error: %s was declared as ",name);
	scope_get_type(next->type);
	printf(" after previously being defined as ");
	scope_get_type(first->type);
	printf("\n");
}

void scope_get_type(struct type* t){
	if(!t){
		printf("unknown type");
		return;
	}
	
	switch(t->kind){
		case TYPE_VOID:
			printf("void");
			return;
		case TYPE_BOOLEAN:
			printf("boolean");
			return;
		case TYPE_CHARACTER:
			printf("char");
			return;
		case TYPE_INTEGER:
			printf("integer");
			return;
		case TYPE_STRING:
			printf("string");
			return;
		case TYPE_ARRAY:
			printf("array");
			return;
		case TYPE_FUNCTION:
			printf("function");
			return;
		default:
			printf("unknown type");
			return;
	}
}

int scope_defined(const char* name, struct symbol* s, struct hash_table* ht){
	struct symbol* findSymbol;
	if((findSymbol = hash_table_lookup(ht, name))){
		if(!findSymbol->defined){		//If it is not defined set it as defined
			findSymbol->defined = 1;
		}else{							//If it is defined throw error message
			scope_redeclared(name, findSymbol, s);
			return 1;
		}
	}
	return 0;
}