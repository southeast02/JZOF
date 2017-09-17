#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
}*BinaryTree, BinaryTreeNode;


void print_binary_tree_by_layer_and_line(BinaryTree root);
BinaryTree construct(char* preorder, char* inorder, int length);
BinaryTree construct_core(char* start_preorder, char* end_preorder,
		char* start_inorder, char* end_inorder);
void show_binary_tree(BinaryTree root);


int main(){

	char preorder_values[] = {'8', '6', '5', '7', '2', '9', '0'};
	char inorder_values[] = {'5', '6', '7', '8', '9', '2', '0'};

	BinaryTree root = construct(preorder_values, inorder_values, 7);

	printf("Inorder show the binary tree:\n");
	show_binary_tree(root);
	puts("\n\nPrint the tree by layer and line:\n");
	print_binary_tree_by_layer_and_line(root);
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


void print_binary_tree_by_layer_and_line(BinaryTree root){
	queue<BinaryTreeNode*> queue1, queue2;
	int flag = 1;
	BinaryTreeNode* p;

	if(root == NULL){
		return;
	}

	queue1.push(root);
	while(!queue1.empty() || !queue2.empty()){
		if ( (flag & 1) == 1){
			while(!queue1.empty()){
				p = queue1.front();
				queue1.pop();
				if(p->left != NULL){
					queue2.push(p->left);
				}

				if (p->right != NULL){
					queue2.push(p->right);
				}
				printf("%c ", p->value);
			}
			flag = 2;
			puts("");
		} else {
			while(!queue2.empty()){
				p = queue2.front();
				queue2.pop();
				if(p->left != NULL){
					queue1.push(p->left);
				}

				if (p->right != NULL){
					queue1.push(p->right);
				}
				printf("%c ", p->value);
			}
			flag = 1;
			puts("");
		}
	}
}

/**
 *output
Inorder show the binary tree:
5	6	7	8	9	2	0	

Print the tree by layer and line:

8 
6 2 
5 7 9 0 

 * */
