#include "decl.h"
#include "hash_table.h"
#include "symbol.h"
#include <stdlib.h>

int resolve_tree(struct decl* tree);

int resolve_function(struct decl* func, struct hash_table **stkPTR);