#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node{
	int value;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
}*BinaryTree, BinaryTreeNode;


void print_path_for_sum(BinaryTree root, int sum, int path[], int k);
BinaryTree construct(int* preorder, int* inorder, int length);
BinaryTree construct_core(int* start_preorder, int* end_preorder,
		int* start_inorder, int* end_inorder);
void show_binary_tree(BinaryTree root);


int main(){

	int preorder_values[] = {10, 5, 4, 7, 12};
	int inorder_values[] = {4, 5, 7, 10, 12};
	int *path;
	int n = 5;
	int sum = 22;

	BinaryTree root = construct(preorder_values, inorder_values, n);
	path = (int *)malloc(sizeof(char)*n);

	printf("Inorder show the binary tree:\n");
	show_binary_tree(root);
	printf("\n\nPrint the path for sum %d:\n", sum);
	print_path_for_sum(root, sum, path, 0);
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


void print_path_for_sum(BinaryTree root, int sum, int path[], int k){
	if(root == NULL){
		return;
	}

	if(root->value == sum && root->left == NULL && root->right == NULL){
		path[k++] = root->value;
		for(int i=0; i<k; i++){
			printf("%d ", path[i]);
		}
		puts("");
	} else if (root->value <= sum) { // later p->value can be 0
		sum -= root->value;
		path[k++] = root->value;

		if(root->left != NULL) {
			print_path_for_sum(root->left, sum, path, k);
		}
		if(root->right != NULL){
			print_path_for_sum(root->right, sum, path, k);
		}
	}
}

/**
 *output

Inorder show the binary tree:
4	5	7	10	12

Print the path for sum 22:
10 5 7
10 12

Inorder show the binary tree:
4	5	7	10	12

Print the path for sum 19:
10 5 4

Inorder show the binary tree:
4	5	0	10	12

Print the path for sum 15:
10 5 0

 * */
