#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
}*BinaryTree, BinaryTreeNode;


void image_tree(BinaryTree root);
BinaryTree construct(char* preorder, char* inorder, int length);
BinaryTree construct_core(char* start_preorder, char* end_preorder,
		char* start_inorder, char* end_inorder);
void show_binary_tree(BinaryTree root);


void image_tree(BinaryTree root){
	// DLR to traverse the tree
	if (root == NULL){
		return;
	}
	if(root->left == NULL && root->right == NULL){
		return;
	}
	// swap left and right tree
	BinaryTreeNode *p = root->left;
	root->left = root->right;
	root->right = p;

	image_tree(root->left);
	image_tree(root->right);
}


int main(){

	char preorder_values[] = {'a', 'b', 'd', 'e', 'h', 'i', 'c', 'f', 'g'};
	char inorder_values[] = {'d', 'b', 'h', 'e', 'i', 'a', 'f', 'c', 'g'};

	BinaryTree root = construct(preorder_values, inorder_values, 9);

	printf("Inorder show the binary tree:\n");
	show_binary_tree(root);

	image_tree(root);
	printf("\n\nImage show the binary tree:\n");
	show_binary_tree(root);

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

Image show the binary tree:
g	c	f	a	i	e	h	b	d
 * */
