#include <stdio.h>
#include <stdlib.h>
struct n{
	int x;
	n * next;
};
typedef n node;

void print(node * r){
	node *iter = r;
	printf("%d ",iter->x);
	iter= iter->next;
	while(iter != r){
		printf("%d ",iter->x);
		iter= iter->next;
	}
	printf("\n");
}
void add(node *r, int x){
	node * iter =r;
	while(iter->next!=r){
		iter = iter -> next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = r;
}
node * addInOrder(node * r,int x){
	if(r==NULL){ // if the linked list is empty
		r=(node *)malloc(sizeof(node));
		r->next = r;
		r->x = x;
		return r;
	}
	if(r->x > x){ // smaller than the first element situation
			// root changing
			node * temp = (node*)malloc(sizeof(node));
			temp -> x = x;
			temp -> next =r;
			node *iter = r;
			while (iter->next!= r)
				iter = iter ->next;	
			iter->next = temp;
			return temp;
	}
	node * iter = r;
	while(iter->next != r && iter->next->x < x){
		iter= iter->next;
	}
	node * temp = (node*)malloc(sizeof(node));
	temp->next = iter -> next;
	iter -> next = temp;
	temp -> x = x;
	return r;
}
node * remove(node *r,int x){
	node *temp;
	node *iter = r;
	if(r->x == x){
		while(iter->next != r){
			iter = iter -> next;
		}
		iter -> next = r->next;
		free(r);
		return iter->next;
	}
	while (iter->next != r && iter->next->x != x){
		iter = iter ->next;
	}
	if(iter->next == r){
		printf("number not found.");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free (temp);
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









