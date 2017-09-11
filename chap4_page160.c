
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
}*BinaryTree, BinaryTreeNode;


int is_symmetric_tree(BinaryTree root1, BinaryTree root2);
BinaryTree construct(char* preorder, char* inorder, int length);
BinaryTree construct_core(char* start_preorder, char* end_preorder,
		char* start_inorder, char* end_inorder);
void show_binary_tree(BinaryTree root);


int main(){

	char preorder_values[] = {'7', '7', '7', '7', '7', '7'};
	char inorder_values[] = {'7', '7', '7', '7', '7', '7'};
	int result;

	BinaryTree root = construct(preorder_values, inorder_values, 6);

	printf("Inorder show the binary tree:\n");
	show_binary_tree(root);
	puts("\n");


	result = is_symmetric_tree(root->left, root->right);
	if (result == 1){
		puts("It's a symmetric tree");
	}else {
		puts("It's NOT a symmetric tree");
	}

}


int is_symmetric_tree(BinaryTree root1, BinaryTree root2){
	if (root1 == NULL && root2 == NULL)
		return 1;
	else if ((root1 != NULL && root2 != NULL) && (
			root1->value == root2->value)){
		return (is_symmetric_tree(root1->left, root2->right) &&
				is_symmetric_tree(root1->right, root2->left));
	}
	return 0;
}


BinaryTree construct(char* preorder, char* inorder, int length){
	if(preorder == NULL || inorder == NULL || length <= 0){
		return NULL;
	}
	return construct_core(preorder, preorder+length-1,
						 inorder, inorder+length-1);
}

BinaryTree construct_core(char* start_preorder, char* end_preorder,
		char* start_inorder, char* end_inorder){
	int root_value = start_preorder[0];
	BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	root->value = root_value;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;

	if(start_preorder == end_preorder){
		if(start_inorder == end_inorder &&
		   *start_preorder == *start_inorder){
		   return root;
		}
		else {
			printf("invalid input\n");
			return NULL;
		}
	}

	char* root_inorder = start_inorder;
	while(root_inorder <= end_inorder &&
		  *root_inorder != root_value){
		root_inorder++;
	}
	if(root_inorder == end_inorder &&
       *root_inorder != root_value){
		printf("invalid input\n");
		return NULL;
	}
	int left_length = root_inorder - start_inorder;
	char *left_preorderend = start_preorder + left_length;
	if(left_length > 0){
		root->left = construct_core(start_preorder+1, left_preorderend,
				                    start_inorder, root_inorder-1);
		root->left->parent = root;
	}
	if(left_length < end_preorder-start_preorder){
		root->right = construct_core(left_preorderend+1, end_preorder,
				                     root_inorder+1, end_inorder);
		root->right->parent = root;
	}
	return root;
}


void show_binary_tree(BinaryTree root){
	if (root == NULL){
		return;
	}
	show_binary_tree(root->left);
	printf("%c\t", root->value);
	show_binary_tree(root->right);
}

/**
 *output

Inorder show the binary tree:
d	b	h	e	i	a	f	c	g

It's NOT a symmetric tree


Inorder show the binary tree:
5	6	7	8	7	6	5

It's a symmetric tree


Inorder show the binary tree:
7	7	7	7	7	7	

It's NOT a symmetric tree
 * */
