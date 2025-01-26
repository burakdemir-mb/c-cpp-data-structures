#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

int main(){
	//if you want to run code, please write compile code first, then output code on this file's integrated terminal:
	//compile code: gcc -o .\output_stack_arr.exe .\stack_arr.cpp .\test_stack.cpp
	//output code: .\output_stack_arr.exe

	stack *s1 = definition();
	stack *s2 = definition();	
	for(int i = 0;i<10;i++){
		push(i*10,s1);
	}	
	print(s1);
	for(int i = 0;i<10;i++){
		push(pop(s1),s2);
	}
	print(s1);
	print(s2);
}
