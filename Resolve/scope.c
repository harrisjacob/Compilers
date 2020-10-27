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
				s->which = (ht->local_count)++;
				printf("local %i", s->which);
			}else if(s->kind == SYMBOL_PARAM){
				s->which = (ht->param_count)++;
				printf("param %i", s->which);
			}else{
				printf("global %s",name);
			}

			printf(" within scope level %i\n", scope_level(ht));
		}

	}else{
		 //Functions are a bit of an exception that is handled by scope_defined later
		if(!(findSymbol->type->kind==TYPE_FUNCTION)){
			scope_redeclared(findSymbol, s);
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

void scope_redeclared(struct symbol* first, struct symbol* next){
	
	if(first->type->kind == next->type->kind){
		printf("\nMy dear, sweet, innocent friend,\n\n");
		printf("If you are seeing this message you have found an easter egg in\n");
		printf("the compiler that only occurs when you redeclare a variable such as\n");
		printf("you did with %s. While other compilers might be so bold to assume you\n", first->name);
		printf("made some form of mistake, I think you meant to redeclare %s. Why you\n", first->name);
		printf("chose to redeclare %s, I do not know. It is not my job to know these\n", first->name);
		printf("kind of things. While this was a fun one sided conversation, I think you\n");
		printf("should take another look at your declarations of %s.\n\n", first->name);
		printf("Sincerely,\n\tThe Name Resolver\n\n");
	}else{
		printf("\nMy dear, sweet, innocent friend,\n\n");
		printf("You may not have realized it, but you actually already declared %s as\ntype ", first->name);
		scope_get_type(first->type);
		printf(".  It's nothing to be embarrassed about, we all do it from time\n");
		printf("to time, but you can't make %s type ", first->name);
		scope_get_type(next->type);
		printf(" after saying it was a ");
		scope_get_type(first->type);
		printf(". You'll\nhave to pick one type or maybe change one of the names. Until");
		printf(" then, I just\ndon't know which type of %s you want to use.\n\n", first->name);
		printf("Sincerely,\n\tThe Name Resolver\n\n");
	}
}

void scope_get_type(struct type* t){
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
		}else{							//If it is defined through error message
			scope_redeclared(findSymbol, s);
			return 1;
		}
	}
	return 0;
}