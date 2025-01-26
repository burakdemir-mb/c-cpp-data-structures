#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"
stack * definition(){
	stack *s = (stack * ) malloc(sizeof (stack));
	s->array = NULL;
	s->size = 2;
	s->top = 0;
	return s;
}
int pop(stack *s){
	if(s->top <= 0||s->array==NULL){
		printf("array is empty.");
		return -1;
	}
	if(s->top<=s->size/4&&s->size>2){
		int *array2 = (int*)malloc(sizeof(int)*s->size/2);
                for(int i = 0;i<s->top ; i++)
                        array2[i] = s->array[i];
                free(s->array);
                s->array = array2;
                s->size /= 2;

	}
	return s->array[--s->top];
}
void push(int a,stack *s ){
	if(s->array == NULL){
		s->array = (int*)malloc(sizeof(int)*2);
	}
	if(s->top>=s->size-1){
		int *array2 = (int*)malloc(sizeof(int)*s->size*2);
		for(int i = 0;i<s->size ; i++)
			array2[i] = s->array[i];
		int * temp = s->array;
		s->array = array2;
		free(temp);
		s->size *= 2;
	}
	s->array[s->top++] = a;
}
void print(stack *s){
	printf("size : %d ",s->size);
	for(int i = 0;i<s->top;i++){
		printf("%d ",s->array[i]);
	}
}
