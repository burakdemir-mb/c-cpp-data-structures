#include <stdio.h>
#include <stdlib.h>
int * array=NULL;
int line = 0, headofline = 0, size = 2;
int deque(){
	if(line==headofline){
		printf("line is empty.");
		return -1;
	}
	//printf(" size = %d, line= %d , gap=%d\n",size,line,line-headofline);
	if(line-headofline<=size/4){
		int * array2 = (int*)malloc(sizeof(int)*size/2);
		for(int i = 0;i<line-headofline;i++){
			array2[i]=array[headofline+i];
		}
		line-=headofline;
		headofline=0;
		free(array);
		size /=2;
		array = array2;
	}
	return array[headofline++];
}
void rearrange(){
	if(headofline==0)
		return ;
	for(int i = 0;i<size;i++){
		array[i] = array[i+headofline];
	}
	line -= headofline;
	headofline = 0;
}
void enque(int a){
	if(array==NULL){
		array = (int*)malloc(sizeof(int)*2);
	}
	if(line >= size){
		size *= 2;
		int *array2 = (int *) malloc(sizeof(int)*size);
		for(int i = 0;i<size/2;i++)
			array2[i] = array[i];
		free (array);
		array = array2;
	}
	array[line++]=a;
}
int main(){
	for(int i = 0;i<20;i++){
		enque(i*10);
	}
	printf(" status: size : %d line %d headofline %d \n",size,line,headofline);
	for(int i = 0;i<13;i++){
		printf("%d ",deque());
	}
	printf(" status: size : %d line %d headofline %d \n",size,line,headofline);
	for(int i = 0;i<20;i++){
		enque(i*10);
	}
	printf(" status: size : %d line %d headofline %d \n",size,line,headofline);
	for(int i = 0;i<30;i++){
		printf("%d ",deque());
	}
	printf(" status: size : %d line %d headofline %d \n",size,line,headofline);

}
