#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct node {
	// typedef is the keyword
	int value;
	struct node *left;
	struct node *right;
}Node, *Tree;


void image_tree(Tree T);


int main(){

 	Tree T=NULL;
 	image_tree(T);

 	return 0;
}

void image_tree(Tree T){
	// DLR to traverse the tree
	if (T == NULL){
		return;
	}
	if(T->left == NULL && T->right == NULL){
		return;
	}
	image_tree(T->left);
	image_tree(T->right);
}
