#include "label.h"

int label_create(){ return labelCtr++; }

const char* label_name(int label){

	char* labelName = (char*) malloc(16);

	//This value must be freed later

	sprintf(labelName, ".L%i", label);
	return labelName;
}

