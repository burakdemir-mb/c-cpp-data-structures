#include <stdio.h>
#include <stdlib.h>
struct n{
	int x;
	n * next;
	n * prev;
};
typedef n node;

void print(node * r){
	while(r!=NULL){
		printf("%d ",r->x);
		r= r->next;
	}
	printf("\n");
}
node * addInOrder(node * r,int x){
	if(r==NULL){ // if the linked list is empty
		r=(node *)malloc(sizeof(node));
		r->next = NULL;
		r->prev = NULL;
		r->x = x;
		return r;
	}
	if(r->x > x){ // smaller than the first element situation
			// root is changing
			node * temp = (node*)malloc(sizeof(node));
			temp -> x = x;
			temp -> next =r;
			r->prev = temp;
			temp->prev = NULL;
			return temp;
	}
	node * iter = r;
	while(iter->next != NULL && iter->next->x < x){
		iter= iter->next;
	}
	node * temp = (node*)malloc(sizeof(node));
	temp->next = iter -> next;
	iter -> next = temp;	
	temp->prev = iter;
	if(temp->next != NULL)
		temp->next->prev = temp ;
	temp -> x = x;
	return r;
}
node * remove(node *r,int x){
	node *temp;
	node *iter = r;
	if(r->x == x){
		temp = r;
		r = r->next;
		r -> prev = NULL;
		free(temp);
		return r;
	}
	while (iter->next != NULL && iter->next->x != x){
		iter = iter ->next;
	}
	if(iter->next == NULL){
		printf("number not found.");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free (temp);
	if(iter->next != NULL)
		iter->next->prev = iter;
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
	root = remove(root,50);
	print(root);
	root = remove(root,999);
	print(root);
	root = remove(root,4);
	print(root);
	root = remove(root,450);
	print(root);
}









