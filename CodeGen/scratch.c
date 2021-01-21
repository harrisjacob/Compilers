#include "scratch.h"

static struct sratchReg scratchList[] = {
	{"%rbx",0},
	{"%r10",0},
	{"%r11",0},
	{"%r12",0},
	{"%r13",0},
	{"%r14",0},
	{"%r15",0}
};


int scratch_alloc(){
	int numScrReg = sizeof(scratchList)/sizeof(scratchList[0]);
	int i;
	for(i=0;i<numScrReg;i++){
		if(!scratchList[i].inUse){
			scratchList[i].inUse = 1;
			return i;
		}
	}

	printf("Code Generator: There are no available scratch registers\n");
	return -1;
}

void scratch_free(int r){
	int numScrReg = sizeof(scratchList)/sizeof(scratchList[0]);
	if(r < 0 || r > numScrReg) return;
	scratchList[r].inUse = 0;
}

const char* scratch_name(int r){
	int numScrReg = sizeof(scratchList)/sizeof(scratchList[0]);
	if(r < 0 || r > numScrReg){
		printf("Code Generator: The requested scratch register name is unailable\n");
		printf("You requested scratch register %i. Scratch registers are numbered 0-%i.\n", r, numScrReg-1);
		return NULL;
	}

	return scratchList[r].name;
}