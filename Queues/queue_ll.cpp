#include <stdio.h>
#include <stdlib.h>
struct n{
	int data;
	n * next;
};
typedef n node;
node * root =NULL;
node * last = NULL;
void enqueue(int x){
	if(root==NULL){
		root = (node*)malloc(sizeof(node));
		root ->data = x;
		root -> next = NULL;
		last = root;
	}
	else{
		last -> next = (node*)malloc(sizeof(node));	
		last -> next -> data = x;
		last = last -> next;
		last -> next = NULL;
	}
}
int dequeue(){
	if(root==NULL){
		printf("linked list is empty.");
		return -1;
	}
	int rvalue = root->data;
	node *temp =root;
	root = root->next;	
	free(temp);
	return rvalue;
}
int main(){
 	for(int i = 0;i<20;i++){
                enqueue(i*10);
        }
        for(int i = 0;i<13;i++){
                printf("%d ",dequeue());
        }
        for(int i = 0;i<20;i++){
                enqueue(i*10);
        }
        for(int i = 0;i<30;i++){
                printf("%d ",dequeue());
        }
}
