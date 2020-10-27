#include "decl.h"
#include "hash_table.h"
#include "symbol.h"
#include "scope.h"
#include <stdlib.h>

int resolve_tree(struct decl* tree);

int decl_resolve(struct decl *d, struct hash_table *ht);

int expr_resolve(struct expr *e, struct hash_table* ht);

int stmt_resolve(struct stmt* s, struct hash_table* ht);

int param_list_resolve(struct param_list* pl, struct hash_table *ht);

void undeclared(const char* name);