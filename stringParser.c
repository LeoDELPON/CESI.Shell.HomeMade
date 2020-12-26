#include "fwd.h"
#include "stringManager.h"

char* StrGetter(Array_t* buffer) {
	size_t length = buffer->used;
	char* charBuffer = NULL;

	charBuffer = (char*)malloc(sizeof(char) * length);

	for (unsigned i = 0; i < length; ++i) {
		charBuffer[i] = buffer->array[i];
	}

	return charBuffer;
}


void StrParser(Array_t* buffer) {
	char* finalStr = NULL;
	Array_t buf;
	SyntaxTree* tree = NULL;
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

void InitSyntaxTree(SyntaxTree* st, char* first) {
	st->structureElement = (SyntaxTree*)malloc(sizeof(first));
	st->nextElement = NULL;
}

SyntaxTree AddToSyntaxTree(SyntaxTree* st, char* element) {
	SyntaxTree newTree;
	newTree.structureElement = (SyntaxTree*)malloc(sizeof(element));
	newTree.nextElement = st;
	return newTree;
}