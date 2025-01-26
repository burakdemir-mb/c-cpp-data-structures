#include <stdio.h>
#include <stdlib.h>
struct n{
	int data;
	n * left;
	n * right;
};
typedef n node;
node * add(node *tree,int x){
	if(tree == NULL){
		node *root= (node *)malloc(sizeof(node));
		root -> left = NULL;
		root -> right = NULL;
		root -> data = x;
		return root;
	}
	
	if(tree->data < x){
		tree->right = add(tree->right,x);
		return tree;
	}
	tree->left = add(tree->left,x);
	return tree;
}
void wander(node *tree){
	if(tree == NULL)
		return;
	printf("%d ",tree->data);
	wander(tree->right);
	wander(tree->left);
}
int find(node * tree,int needed){
	if(tree == NULL)
		return -1;
	if(tree->data == needed)
		return 1;
	if(find(tree->right,needed)==1)
		return 1;
	if(find(tree->left,needed)==1)
		return 1;
	return -1;
}
int max(node *tree){

	while(tree->right!=NULL)
		tree=tree->right;
	return tree->data;
}
int min(node *tree){
	while(tree->left!=NULL)
		tree=tree->left;
	return tree->data;
}
node * remove(node *tree,int x){
	if(tree==NULL)
		return NULL;
	if(tree->data == x){
		if(tree->left==NULL && tree->right==NULL)
			return NULL;
		if(tree->right!=NULL){
			tree->data = min(tree->right);
			tree->right = remove(tree->right, min(tree->right));
			return tree;
		}
		tree->data = max(tree->left);
		tree->left = remove(tree->left,max(tree->left));
		return tree;
	}	
	if(tree->data < x){
		tree->right = remove(tree->right,x);
		return tree;
	}
	tree->left= remove(tree->left,x);
	return tree;
	

}
int main(){
	node * tree=NULL;
	tree=add(tree,56);
	tree=add(tree,200);
	tree=add(tree,26);
	tree=add(tree,190);
	tree=add(tree,213);
	tree=add(tree,18);
	tree=add(tree,28);
	tree=add(tree,12);
	tree=add(tree,24);
	tree=add(tree,27);
	wander(tree);
	printf("search result: %d \n",find(tree,24));
	printf("max = %d min = %d \n",max(tree),min(tree));
	tree= remove(tree,56);
	wander(tree);
}

