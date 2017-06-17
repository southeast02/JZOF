#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int value;
	struct Node *left;
	struct Node *right;
}*BinaryTree, BinaryTreeNode;

BinaryTree construct(int* preorder, int* inorder, int length);
BinaryTree construct_core(int* start_preorder, int* end_preorder,
					      int* start_inorder, int* end_inorder);
void show_binary_tree(BinaryTree root);

int main(){

	int preorder_values[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder_values[] = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTree root = construct(preorder_values, inorder_values, 8);


	printf("preorder show the binary tree:\n");
	show_binary_tree(root);
}

BinaryTree construct(int* preorder, int* inorder, int length){
	if(preorder == NULL || inorder == NULL || length <= 0){
		return NULL;
	}
	return construct_core(preorder, preorder+length-1,
						 inorder, inorder+length-1);
}

BinaryTree construct_core(int* start_preorder, int* end_preorder,
					      int* start_inorder, int* end_inorder){
	int root_value = start_preorder[0];
	BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	root->value = root_value;
	root->left = NULL;
	root->right = NULL;

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

	int* root_inorder = start_inorder;
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
	int *left_preorderend = start_preorder + left_length;
	if(left_length > 0){
		root->left = construct_core(start_preorder+1, left_preorderend,
				                    start_inorder, root_inorder-1);
	}
	if(left_length < end_preorder-start_preorder){
		root->right = construct_core(left_preorderend+1, end_preorder,
				                     root_inorder+1, end_inorder);
	}
	return root;
}

void show_binary_tree(BinaryTree root){
	if (root == NULL){
		return;
	}
	printf("%d\t", root->value);
	show_binary_tree(root->left);
	show_binary_tree(root->right);
}
