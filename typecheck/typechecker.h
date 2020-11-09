#include "stmt.h"
#include "library.h"

struct type * expr_typecheck(struct expr *e);

//void operands_typecheck(struct expr* op, type_t lt_exp, type_t lt, type_t rt_exp, type_t rt);

//void operands_typecheck_util(struct expr* op, type_t exp, type_t act, int argCount);

void decl_typecheck(struct decl *d);

void stmt_typecheck(struct stmt *s);

int catchArray(struct expr* e);