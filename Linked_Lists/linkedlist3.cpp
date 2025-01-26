#include <stdio.h>
#include <stdlib.h>
#include "blibrary.h"
int main(){
	//if you want to run code, please write compile code first, then output code on this file's integrated terminal:
	//compile code: gcc -o .\output_linkedlist3.exe .\linkedlist3.cpp .\blibrary.cpp
	//output code: .\output_linkedlist3.exe

	node * root;
	root = NULL;
	root = addInOrder(root,400);
	root = addInOrder(root,40);
	root = addInOrder(root,4);
	root = addInOrder(root,450);
	root = addInOrder(root,50);
	print(root);
	root = remove(root,50);
	print(root);
	root = remove(root,999);
	print(root);
	root = remove(root,4);
	print(root);
	root = remove(root,450);
	print(root);
}









