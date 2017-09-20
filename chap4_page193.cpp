#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node{
	int value;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
}*BinaryTree, BinaryTreeNode;


BinaryTree convert_to_list(BinaryTree root);
void convert_node(BinaryTree root, BinaryTreeNode ** last_node_in_list);
BinaryTree construct(int* preorder, int* inorder, int length);
BinaryTree construct_core(int* start_preorder, int* end_preorder,
		int* start_inorder, int* end_inorder);
void show_binary_tree(BinaryTree root);


int main(){

	int preorder_values[] = {10, 5, 4, 7, 12};
	int inorder_values[] = {4, 5, 7, 10, 12};
	int n = 5;
	BinaryTree head_of_list;

	BinaryTree root = construct(preorder_values, inorder_values, n);

	printf("Inorder show the binary tree:\n");
	show_binary_tree(root);

	printf("\nTree converted to a list:\n");
	head_of_list = convert_to_list(root);
	while(head_of_list != NULL){
		printf("%d, ", head_of_list->value);
		head_of_list = head_of_list->right;
	}
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
	printf("%d\t", root->value);
	show_binary_tree(root->right);
}


void convert_node(BinaryTree root, BinaryTreeNode ** last_node_in_list){
	if(root == NULL)
		return;

	if(root->left != NULL){
		convert_node(root->left, last_node_in_list);
	}

	root->left = *last_node_in_list;
	if( *last_node_in_list != NULL){
		(*last_node_in_list)->right = root;
	}

	*last_node_in_list = root;
	if(root->right != NULL){
		convert_node(root->right, last_node_in_list);
	}
}


BinaryTree convert_to_list(BinaryTree root){
	BinaryTreeNode *last_node_in_list = NULL;
	BinaryTreeNode *head;

	convert_node(root, &last_node_in_list);

	// last_node_in_list point to tail of list
	head = last_node_in_list;
	// here head!=NULL is a must
	while(head != NULL && head->left != NULL){
		head = head->left;
	}
	return head;
}


/**
 *output

Inorder show the binary tree:
4	5	7	10	12	
Tree converted to a list:
4, 5, 7, 10, 12, 

 * */
