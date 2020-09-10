#include"bst.h"

using std::cout;
using std::endl;

void BST::insert(int val)
{
	root = insert(root,val);
	
}

node* BST::insert(node *root,int val)
{
	if(!root)
	{
		root = new node();
		root->val =val;
		root->left = root->right = NULL;
		return root;
	}
	
	if(root->val > val)
		root->left = insert(root->left,val);
	else if(root->val < val)
		root->right = insert(root->right,val);
		
	return root;
		
}

void BST::print(int order)
{
	if(order == IN_ORDER)
		print_inorder(root);
	else if(order == PRE_ORDER)
		print_preorder(root);
	else
		print_postorder(root);
}

void BST::print_inorder(node *root)
{
	if (root != NULL) 
    { 
        print_inorder(root->left); 
        cout << root->val << endl;
        print_inorder(root->right); 
    } 
}

void BST::print_preorder(node *root)
{
	if (root != NULL) 
    { 
    	cout << root->val << endl;
        print_preorder(root->left); 
        print_preorder(root->right); 
    } 
}

void BST::print_postorder(node *root)
{
	if (root != NULL) 
    { 
    	
        print_postorder(root->left); 
        print_postorder(root->right); 
        cout << root->val << endl;
    } 
}

void BST::free_tree(node* root)
{
	if(root)
	{
		free_tree(root->left);
		free_tree(root->right);
		delete root;
	}	
}

void BST::remove(int val)
{
	root = remove(root,val);
}

node* BST::find_successor(node *root)
{
	node *temp;
	if(!root->left)
	{
		return root;
	}
	temp = find_successor(root->left);
	return temp;
}

node* BST::remove(node *root,int val)
{
	node *temp;
	int v;
	if(!root)
		return NULL;
	
	if(root->val == val)
	{
		if(root->left && root->right)
		{
			temp = find_successor(root->right);
			v = temp->val;
			remove(root,temp->val);
			root->val = v;
			return root;
		}
		else if(root->left)
		{
			temp = root->left;
		}
		else
		{
			temp = root->right;
		}
		delete root;
		return temp;
	}
	else if(root->val > val)
		root->left = remove(root->left,val);
	else
		root->right = remove(root->right,val);
	
	return root;
}









