#include "symbol.h"
#include "hash_table.h"


int scope_enter(struct hash_table **stkPTR);

void scope_leave(struct hash_table **stkPTR);

int scope_bind(const char *name, struct symbol *s, struct hash_table *ht);

struct symbol* scope_lookup(const char *name, struct hash_table *ht);

int scope_level(struct hash_table *ht);