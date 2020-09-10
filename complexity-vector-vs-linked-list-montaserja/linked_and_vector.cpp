
#include<iostream>
#include<vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <ctime>

#define num 100000
using std::cout;
using std::endl;
using std::vector;
#include<string.h> 

struct node
{
	int data;
	node *next;
};
  
vector<int> insertToVec(int * const arr)
{
	
	vector<int> v;
	int temp = 0;
	v.push_back(arr[0]);
	
	for (int i=1;i<num ; ++i)
	{
		if(arr[i] > v[v.size()-1])
		{
			v.push_back(arr[i]);
		}
		else
		{
			std::time_t t1 = std::time(NULL);
			for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
			{
				
				if(*it > arr[i])
				{				
					v.insert(v.begin() + temp , arr[i]);
					break;
				}
				++temp;
			}
			std::time_t t2 = std::time(NULL);
			cout <<  "vector insert " << t2-t1 << endl;
		}
		temp=0;
	}
	
	
	
	// print the vector
	/*for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
		cout << *it << endl;*/
	return v;
}


node* addnode(node *head , int data)
{
	node *temp = head,*prev = NULL;
	
	while(temp)
	{
		//cout << data <<endl;
		if(temp->data > data)
		{
			node *next = new node();
			next->data = data;
			next->next = temp;
			if(prev){
				prev->next = next;
				return head;
			}else
				return next;
			
			
		}
		else if(!temp->next)
		{
			node *next = new node();
			next->data = data;
			next->next = NULL;
			temp->next = next;
			break;
		}
		else
		{
		prev = temp;
		temp = temp->next;
		}
	}

	return head;
}

node* insertToList(int * const arr)
{
	node *head = new node();
	head->data = arr[0];
	head->next = NULL;
	
	
	for (int i=1;i<num ; ++i)
	{
		std::time_t t1 = std::time(NULL);
		head = addnode(head,arr[i]);
		std::time_t t2 = std::time(NULL);
		cout <<  "list insert " << t2-t1 << endl;
	}
	/*node *temp = head;
	while(temp)
	{
		cout << temp->data <<endl;
		temp = temp->next;
	}*/
	return head;
}






void shuffle(int **arr){
	for (int i=num-1;i>0 ; --i)
	{
		
		int randi = rand() % i;
		if(randi < 0)
			continue;
		
		int temp = *(*arr+i);
		*(*arr+i) = *(*arr+randi);
		*(*arr+randi) = temp;
	}

}

int main()
{
	int *arr = new int[num];
	
	for (int i=0;i<num ; ++i)
	{
		arr[i] = i;		
	}
	
	shuffle(&arr);
	/*for (int i=0;i<num ; ++i)
	{
		cout << arr[i] << endl;
	}*/
	//insertToVec(arr);
	insertToList(arr);
	delete [] arr;
	
	return 0;
}










