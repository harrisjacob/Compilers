#include "label.h"

int label_create(){ return labelCtr++; }

const char* label_name(int label){
	char* labelName;
	sprintf(labelName, ".L%i", label);
	return labelName;
}

