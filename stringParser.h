#include "fwd.h";

char* StrGetter(Array_t* buffer);
void StrParser(Array_t* buffer, SyntaxTree* tree);
void InitSyntaxTree(SyntaxTree* st, char* first);
SyntaxTree AddToSyntaxTree(SyntaxTree* st, char* element);