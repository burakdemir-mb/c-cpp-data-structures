#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

int main(){
        //if you want to run code, please write compile code first, then output code on this file's integrated terminal:
	//compile code: gcc -o .\output_stack_ll.exe .\stack_ll.cpp .\test_stack_ll.cpp
	//output code: .\output_stack_ll.exe

        node * s=NULL;
        s = push(s,10);
        s = push(s, 20);
        printf("%d -> ",pop(s));
        s = push(s, 30);
        printf("%d -> ",pop(s));
        printf("%d -> ",pop(s));

}
