#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
}*BinaryTree, BinaryTreeNode;

BinaryTree construct(char* preorder, char* inorder, int length);
BinaryTree construct_core(char* start_preorder, char* end_preorder,
		char* start_inorder, char* end_inorder);
void show_binary_tree(BinaryTree root);
void inorder_next_node(BinaryTree root, char value, BinaryTreeNode** next);
BinaryTreeNode* get_next_node(BinaryTreeNode* node);

int main(){

	char preorder_values[] = {'a', 'b', 'd', 'e', 'h', 'i', 'c', 'f', 'g'};
	char inorder_values[] = {'d', 'b', 'h', 'e', 'i', 'a', 'f', 'c', 'g'};
	char ch;
	BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));

	BinaryTree root = construct(preorder_values, inorder_values, 9);

	printf("inorder show the binary tree:\n");
	show_binary_tree(root);

	printf("\n\nprint next node:\n");

	ch = 'g';
	inorder_next_node(root, ch, &node);
	if(node != NULL){
		printf("next node for '%c' is '%c'\n", ch, node->value);
	} else {
		printf("'%c' has no next node\n", ch);
	}

	ch = 'i';
	inorder_next_node(root, ch, &node);
	if(node != NULL){
		printf("'%c' has next node '%c'\n", ch, node->value);
	} else {
		printf("'%c' has no next node\n", ch);
	}
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

void inorder_next_node(BinaryTree root, char value, BinaryTreeNode** next){
	if(root == NULL){
		return;
	}
	if(root->left != NULL){
		inorder_next_node(root->left, value, next);
	}
	if(root->value == value){
		*next = get_next_node(root);
		return;
	}
	if(root->right){
		inorder_next_node(root->right, value, next);
	}

}

BinaryTreeNode* get_next_node(BinaryTreeNode* node){

	if(node == NULL){
		return NULL;
	}

	if(node->right != NULL) {
		BinaryTreeNode *next = node->right;
		while(next->left != NULL){
			next = next->left;
		}
		return next;
	}
	else {
		BinaryTreeNode *child= node;
		BinaryTreeNode *parent = node->parent;
		while(parent != NULL && child == parent->right){
			child = parent;
			parent = parent->parent;
		}
		return parent;
	}
}

/**
 * output:
 *
inorder show the binary tree:
d	b	h	e	i	a	f	c	g

print next node:
'g' has no next node
'i' has next node 'a'
 *
 * */
