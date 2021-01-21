#ifndef SCRATCH_H
#define SCRATCH_H

#include <stdio.h>

	struct sratchReg{
		const char* name;
		int inUse;
	};

	int scratch_alloc();
	void scratch_free(int r);
	const char* scratch_name(int r);

#endif