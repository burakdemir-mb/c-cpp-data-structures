#include <stdio.h>
#include <stdlib.h>
struct n{
	int x;
	n * next;
};
typedef n node;

void print(node * r){
	while(r!=NULL){
		printf("%d ",r->x);
		r= r->next;
	}
}
void add(node *r, int x){
	while(r->next!=NULL){
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}
node * addInOrder(node * r,int x){
	if(r==NULL){ // if the linked list is empty
		r=(node *)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	if(r->x > x){ // smaller than the first element situation
			// root is changing
			node * temp = (node*)malloc(sizeof(node));
			temp -> x = x;
			temp -> next =r;
			return temp;
	}
	node * iter = r;
	while(iter->next != NULL && iter->next->x < x){
		iter= iter->next;
	}
	node * temp = (node*)malloc(sizeof(node));
	temp->next = iter -> next;
	iter -> next = temp;
	temp -> x = x;
	return r;
}
int main(){
	node * root;
	root = NULL;
	root = addInOrder(root,400);
	root = addInOrder(root,40);
	root = addInOrder(root,4);
	root = addInOrder(root,450);
	root = addInOrder(root,50);
	print(root);
}









