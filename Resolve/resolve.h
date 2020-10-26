#include "decl.h"
#include "hash_table.h"
#include "symbol.h"
#include "scope.h"
#include <stdlib.h>

int resolve_tree(struct decl* tree);

int decl_resolve(struct decl *d, struct hash_table *ht);

void expr_resolve(struct expr *e, struct hash_table* ht);

void stmt_resolve(struct stmt* s, struct hash_table* ht);

void param_list_resolve(struct param_list* pl, struct hash_table *ht);