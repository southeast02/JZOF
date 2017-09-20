#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node{
	int value;
	struct Node *left;
	struct Node *right;
}*BinaryTree, BinaryTreeNode;

void show_binary_tree(BinaryTree root);
void deserialize_tree(BinaryTree *root, int arr[], int N, int *k);
void serialize_tree(BinaryTree root);


int main(){
	int arr[] = {1, 2, 4, '$', '$', '$', 3, 5, '$', '$', 6, '$', '$'};
	int N = 13;
	int k = 0;
	BinaryTree root;
	deserialize_tree(&root, arr, N, &k);
	puts("Inorder print a tree:");
	show_binary_tree(root);
	puts("\n\nAfter serialized tree:");
	serialize_tree(root);
}

void show_binary_tree(BinaryTree root){
	if (root == NULL){
		return;
	}
	show_binary_tree(root->left);
	printf("%d\t", root->value);
	show_binary_tree(root->right);
}


void serialize_tree(BinaryTree root){
	if(root == NULL){
		printf("%c,", '$');
		return;
	}
	printf("%d,", root->value);
	serialize_tree(root->left);
	serialize_tree(root->right);
}


void deserialize_tree(BinaryTree *root, int arr[], int N, int *k){
	if(*k < N && arr[*k] != '$'){
		*root = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
		(*root)->value = arr[*k];
		(*root)->left = NULL;
		(*root)->right = NULL;
		*k  = *k + 1;
		deserialize_tree(&((*root)->left), arr, N, k);
		*k  = *k + 1;
		deserialize_tree(&((*root)->right), arr, N, k);
	}
}


/**
 *output

Inorder print a tree:
4	2	1	5	3	6	

After serialized tree:
1,2,4,$,$,$,3,5,$,$,6,$,$,

 * */
