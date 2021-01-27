#ifndef CODEGEN_H
#define CODEGEN_H

	#include <stdio.h>
	#include "symbol.h"
	#include "expr.h"
	#include "stmt.h"
	#include "scratch.h"
	#include "label.h"
	#include "typechecker.h"

	const char* symbol_codegen(struct symbol* s);
	void expr_codegen(struct expr *e);
	void stmt_codegen(struct stmt *s);

#endif