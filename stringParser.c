#include "fwd.h"
#include "stringManager.h"

char* StrGetter(Array_t* buffer) {
	int length = buffer->used;
	char* charBuffer = NULL;
	char* tmpCharBuffer = NULL;
	if(!charBuffer)
		charBuffer = (char*)malloc(sizeof(char) * length + 1);
	strncpy_s(charBuffer, length + 1, buffer->array, length);
	printf("%s\n", charBuffer);
	return charBuffer;
}

void InitSyntaxTree(SyntaxTree* st, char* first) {
	st->structureElement = NULL;
	if (!st->structureElement)
		st->structureElement = (SyntaxTree*)malloc(sizeof(first));
	st->structureElement = first;
	st->nextElement = NULL;
}

SyntaxTree AddToSyntaxTree(SyntaxTree* st, char* element) {
	SyntaxTree newTree;
	newTree.structureElement = NULL;
	if (!newTree.structureElement)
		newTree.structureElement = (SyntaxTree*)malloc(sizeof(element));
	newTree.structureElement = element;
	newTree.nextElement = st;
	return newTree;
}


void StrParser(Array_t* buffer, SyntaxTree* tree) {
	char* finalStr = NULL;
	Array_t buf;
	SyntaxTree newT;
	CustomArrayInit(&buf, 5);
	for (unsigned i = 0; i < buffer->used; ++i) {
		if (buffer->array[i] != 32) {
			CustomArrayAddElement(&buf, buffer->array[i], 0);
		}
		else {
			finalStr = StrGetter(&buf); 
			if (!tree) {
				InitSyntaxTree(tree, finalStr);
			}
			else {
				newT = AddToSyntaxTree(tree, finalStr);
			}
		}
	}
}