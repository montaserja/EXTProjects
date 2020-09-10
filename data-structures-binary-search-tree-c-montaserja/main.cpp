#include"bst.h"

int main()
{
	BST tree;
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(3);
	tree.insert(1);
	tree.insert(0);
	tree.insert(2);
	std::cout << "In Order" <<std::endl;
	tree.print(IN_ORDER);
	std::cout << "Pre Order" <<std::endl;
	tree.print(PRE_ORDER);
	std::cout << "Post Order" <<std::endl;
	tree.print(POST_ORDER);
	tree.remove(4);
	std::cout << "In Order after removing 4" <<std::endl;
	tree.print(IN_ORDER);
	return 0;
}

/*  	4
	1      5
   0  2   3  6
*/
