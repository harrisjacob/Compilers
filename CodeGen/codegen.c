#include "codegen.h"

static const char* argRegList[] = {"%rdi","%rsi","%rdx","%rcx","%r8","%r9"};
static int valsOnStack = 0;
//This keeps track of the variables of the current scope that have been put on the stack
const char* symbol_codegen(struct symbol* s){
	if(!s) return NULL;

	switch(s->kind){
		case SYMBOL_GLOBAL:
			return s->name;
		case SYMBOL_PARAM:
			if(s->defined < 6){
				if(!(s->defined)) valsOnStack = 0; //If this is the first param reset the counter
				
				return argRegList[(s->defined)-1]; //Use a reserved register
			}

			//Params greater than 6 should fall through to a stack assignment

		case SYMBOL_LOCAL:
			if(!(s->defined)) valsOnStack = 0; //If this is the first local variable reset the valOnStack counter
			
			char* stackRef = (char*) malloc(16);
			sprintf(stackRef, "-%i(%%rbp)", (++valsOnStack)*8); //Offset the stack pointer by the number of values on the stack already
			return stackRef;

		default:
			printf("CodeGen: Unknown symbol type detected.\n");
			return NULL;
	}
}


void expr_codegen(struct expr *e){

	if(!e) return;

	int true_label, done_label;

	switch(e->kind){

		case EXPR_ASSIGN:
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("MOVQ %s, %s\n", symbol_codegen(e->right->symbol), scratch_name(e->left->reg));
			

			e->reg = e->left->reg;
			scratch_free(e->right->reg);


			//Is this the correct register copy?
			//Should be copying the src register
			//Free the RHS register (src)?
			//The register assignment doesn't matter as long as you free the other register?

			return;
		case EXPR_OR:
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("ORQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			e->reg = e->right->reg;
			scratch_free(e->left->reg);
			return;

		case EXPR_AND:
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("ANDQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			e->reg = e->right->reg;
			scratch_free(e->left->reg);
			return;
		case EXPR_LT:
			true_label = label_create();
			done_label = label_create();
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("CMP %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			scratch_free(e->right->reg);
			printf("JLT %s\n", label_name(true_label));
			printf("MOV $0, %s\n", scratch_name(e->left->reg));
			printf("JMP %s\n", label_name(done_label));
			printf("%s:\n",label_name(true_label));
			printf("MOV $1, %s\n", scratch_name(e->left->reg));
			printf("%s:\n", label_name(done_label));
			return;
		case EXPR_LE:
			true_label = label_create();
			done_label = label_create();
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("CMP %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			scratch_free(e->right->reg);
			printf("JLE %s\n", label_name(true_label));
			printf("MOV $0, %s\n", scratch_name(e->left->reg));
			printf("JMP %s\n", label_name(done_label));
			printf("%s:\n",label_name(true_label));
			printf("MOV $1, %s\n", scratch_name(e->left->reg));
			printf("%s:\n", label_name(done_label));
			return;
		case EXPR_GT:
			true_label = label_create();
			done_label = label_create();
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("CMP %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			scratch_free(e->right->reg);
			printf("JGT %s\n", label_name(true_label));
			printf("MOV $0, %s\n", scratch_name(e->left->reg));
			printf("JMP %s\n", label_name(done_label));
			printf("%s:\n",label_name(true_label));
			printf("MOV $1, %s\n", scratch_name(e->left->reg));
			printf("%s:\n", label_name(done_label));
			return;
		case EXPR_GE:
			true_label = label_create();
			done_label = label_create();
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("CMP %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			scratch_free(e->right->reg);
			printf("JGE %s\n", label_name(true_label));
			printf("MOV $0, %s\n", scratch_name(e->left->reg));
			printf("JMP %s\n", label_name(done_label));
			printf("%s:\n",label_name(true_label));
			printf("MOV $1, %s\n", scratch_name(e->left->reg));
			printf("%s:\n", label_name(done_label));
			return;
		case EXPR_EQ:
			true_label = label_create();
			done_label = label_create();
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("CMP %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			scratch_free(e->right->reg);
			printf("JE %s\n", label_name(true_label));
			printf("MOV $0, %s\n", scratch_name(e->left->reg));
			printf("JMP %s\n", label_name(done_label));
			printf("%s:\n",label_name(true_label));
			printf("MOV $1, %s\n", scratch_name(e->left->reg));
			printf("%s:\n", label_name(done_label));
			return;
		case EXPR_NEQ:
			true_label = label_create();
			done_label = label_create();
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("CMP %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			scratch_free(e->right->reg);
			printf("JNE %s\n", label_name(true_label));
			printf("MOV $0, %s\n", scratch_name(e->left->reg));
			printf("JMP %s\n", label_name(done_label));
			printf("%s:\n",label_name(true_label));
			printf("MOV $1, %s\n", scratch_name(e->left->reg));
			printf("%s:\n", label_name(done_label));
			return;
		case EXPR_ADD:
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("ADDQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			e->reg = e->right->reg;
			scratch_free(e->left->reg);
			return;
		case EXPR_SUB:
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("SUBQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
			e->reg = e->right->reg;
			scratch_free(e->left->reg);
			return;
			/*
		case EXPR_MOD:
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
			printf("CQO\n"); //Sign extend the register
			printf("IDIVQ %s\n", scratch_name(e->right->reg));
			printf("MOVQ %%rdx, %s\n", scratch_name(e->right->reg)) //Move the remainder into the correct register
			e->reg = e->right->reg;
			scratch_free(e->left->reg);
			return;*/

		case EXPR_MUL:
			expr_codegen(e->left);
			expr_codegen(e->right);
			printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
			printf("IMULQ %s\n", scratch_name(e->right->reg));
			printf("MOVQ %%rax, %s\n", scratch_name(e->right->reg));
			e->reg = e->right->reg;
			scratch_free(e->left->reg);
			return;
		case EXPR_EXP:
			printf("Need to implement EXPR_EXP\n");
			return;
		case EXPR_NEG:
			expr_codegen(e->right);
			printf("NEGQ %s\n", scratch_name(e->right->reg));
			e->reg = e->right->reg;
			return;
		case EXPR_NOT:
			expr_codegen(e->right);
			printf("CMPQ $0, %s\n", scratch_name(e->right->reg));
			printf("NEED TO COMPLETE EXPR_NOT LOGIC\n");

			e->reg = e->right->reg;
			return;
		default:
			printf("Unhandled expr codegen\n");
			return;
	}


	/*
	EXPR_ASSIGN,
	EXPR_OR,
	EXPR_AND,
	EXPR_LT,
	EXPR_LE,
	EXPR_GT,
	EXPR_GE,
	EXPR_EQ,
	EXPR_NEQ,
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MOD,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_EXP,
	EXPR_NEG,
	EXPR_NOT,
	EXPR_POST_INC,
	EXPR_POST_DEC,
	EXPR_INDEX,
	EXPR_FUNC,
	EXPR_PAREN,
	EXPR_ID,
	EXPR_INT_LIT,
	EXPR_BOOL_LIT,
	EXPR_CHAR_LIT,
	EXPR_STRING_LIT,
	EXPR_ARRAY_LIT
	*/

}

void stmt_codegen(struct stmt *s){

	if(!s) return;

	int else_label, done_label, loopStart_label;
	struct expr* printItem;
	struct type* printType;


	switch(s->kind){
		case STMT_DECL:
			decl_codegen(s->decl);
			break;
		case STMT_EXPR:
			expr_codegen(s->expr);
			scratch_free(s->expr->reg);
			break;
		
		case STMT_IF_ELSE:
			else_label = label_create();
			done_label = label_create();
			expr_codegen(s->expr);
			printf("CMP $0, %s\n", scratch_name(s->expr->reg));
			scratch_free(s->expr->reg);
			printf("JE %s\n", label_name(else_label));
			stmt_codegen(s->body);
			printf("JMP %s\n", label_name(done_label));
			printf("%s:\n", label_name(else_label));
			stmt_codegen(s->else_body);//stmt codegen will handle null values
			printf("%s:\n",label_name(done_label));
			break;
		
		case STMT_FOR:
			loopStart_label = label_create();
			done_label = label_create();
			//Loop initialize
			expr_codegen(s->init_expr);
			if(s->init_expr) scratch_free(s->init_expr->reg);

			//Loop start
			printf("%s:\n", label_name(loopStart_label));
			expr_codegen(s->expr);
			
			//Ommitted end loop condition defaults to true
			if(s->expr){
				printf("CMP $0, %s\n", scratch_name(s->expr->reg));
				scratch_free(s->expr->reg);
				printf("JE %s\n", label_name(done_label));
			}

			stmt_codegen(s->body);
			expr_codegen(s->next_expr);
			if(s->next_expr) scratch_free(s->next_expr->reg);
			printf("JMP %s\n", scratch_name(loopStart_label));

			//end of loop body
			printf("%s:\n", label_name(done_label));
			break;
			
		case STMT_PRINT:
			printItem = s->expr;
			printf("PUSH %%rdi\n");
			while(printItem){

				expr_codegen(printItem); //Generate the assembly instructions for an expression
				printType = expr_typecheck(printItem); //Determine the type of the expression
				
				printf("MOV %s, %%rdi\n", scratch_name(printItem->reg));
				printf("PUSH %%r10\n");
				printf("PUSH %%r11\n");
				printf("CALL print_%s\n", getType(printType->kind)); //Call the appropriate print function from runtime library
				printf("POP %%r11\n");
				printf("POP %%r10\n");
				scratch_free(printItem->reg);

				printItem = printItem->next;
			}
			printf("POP %%rdi\n");
			break;

		case STMT_RETURN:
			expr_codegen(s->expr);
			printf("MOV %s, %%rax\n", scratch_name(s->expr->reg));
			//Need to pass down function_name (see 189)
			printf("JMP .%s_epilogue\n", function_name);
			scratch_free(s->expr->reg);
			break;

		case STMT_BLOCK:
			stmt_codegen(s->body);
			break;

		default:
			printf("CodeGen: Unkown statement encountered\n");
			break;
	}

	stmt_codegen(s->next);
}
