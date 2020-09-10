#ifndef __BSF_H__
#define __BSF_H__

#include<iostream>

enum{IN_ORDER,PRE_ORDER,POST_ORDER};
typedef struct node 
{ 
    int val; 
    struct node *left, *right; 
} node; 

class BST
{
	public:
		BST():root(NULL){}
		~BST();
		void insert(int val);
		void remove(int val);
		void print(int order);
	
	private:
		node *root;
		
		node* find_successor(node *root);
		void free_tree(node* root);
		void print_inorder(node *root);
		void print_preorder(node *root);
		void print_postorder(node *root);
		node* remove(node *root,int val);
		node* insert(node *root,int val);

};

inline BST::~BST()
{
	free_tree(root);
}


#endif /* __BSF_H__ */
