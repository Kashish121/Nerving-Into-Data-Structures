#include <iostream> 
using namespace std; 

class node { 
public: 
	int data; 
	node *left, *right; 
}; 
 
node* newNode(int item) //create binary tree node
{ 
	node* temp = new node(); 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void leftViewUtil(node* root, int level, int* max_level) //function to create left view of binary tree
{ 
	if (root == NULL) //when we reach the base
		return; 

	if (*max_level < level) //first node of a level
    { 
		cout << root->data << "\t"; 
		*max_level = level; 
	} 
 
	leftViewUtil(root->left, level + 1, max_level); //recursive call for left and right subtree
	leftViewUtil(root->right, level + 1, max_level); 
} 

void leftView(node* root) //leftview function
{ 
	int max = 0; 
	leftViewUtil(root, 1, &max); 
} 

 
int main() //tree declaration
{ 
	node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->right->left = newNode(4); 
	root->right->right = newNode(5); 

	leftView(root); 

	return 0; 
}