#include "expr.h"
#include "library.h"

struct type * expr_typecheck(struct expr *e);

void operands_typecheck(expr_t op, expr_t lt_exp, expr_t lt, expr_t rt_exp, expr_t rt);

void operands_typecheck_util(expr_t op, expr_t exp, expr_t act, int argCount);