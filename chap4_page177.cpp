#include <deque>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
}*BinaryTree, BinaryTreeNode;


void print_binary_tree_by_layer_with_reverse(BinaryTree root);
BinaryTree construct(char* preorder, char* inorder, int length);
BinaryTree construct_core(char* start_preorder, char* end_preorder,
		char* start_inorder, char* end_inorder);
void show_binary_tree(BinaryTree root);


int main(){

	char preorder_values[] = {'1', '2', '4', '5', '3', '6', '7'};
	char inorder_values[] = {'4', '2', '5', '1', '6', '3', '7'};

	BinaryTree root = construct(preorder_values, inorder_values, 7);

	printf("Inorder show the binary tree:\n");
	show_binary_tree(root);
	puts("\n\nPrint the tree by layer and line:\n");
	print_binary_tree_by_layer_with_reverse(root);
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


void print_binary_tree_by_layer_with_reverse(BinaryTree root){
	deque<BinaryTreeNode*> deque1;
	stack<BinaryTreeNode*> s1;

	int flag = 1;
	BinaryTreeNode* p;

	if(root == NULL){
		return;
	}

	deque1.push_back(root);
	while(!deque1.empty() || !s1.empty()){
		if ( (flag & 1) == 1){
			while(!deque1.empty()){
				p = deque1.front();
				deque1.pop_front();
				if(p->left != NULL){
					s1.push(p->left);
				}

				if (p->right != NULL){
					s1.push(p->right);
				}
				printf("%c ", p->value);
			}
			flag = 2;
			puts("");
		} else {
			while(!s1.empty()){
				p = s1.top();
				s1.pop();
				// pay attention to the enqueue order
				if (p->right != NULL){
					deque1.push_front(p->right);
				}
				if(p->left != NULL){
					deque1.push_front(p->left);
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
4	2	5	1	6	3	7	

Print the tree by layer and line:

1 
3 2 
4 5 6 7 

 * */
