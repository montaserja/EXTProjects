#ifndef __STACK_H__
#define __STACK_H__

#include<iostream>
  
class Stack { 

  
	public: 
		Stack(int size):top(-1),size(size),a(new int[size]) {} 
		~Stack(){
			delete [] a;
		}
		bool push(int x); 
		int pop(); 
		int peek(); 
		bool isEmpty();
		
		
	private:
		int top;
		int size; 
		int *a;
}; 
 
inline bool Stack::push(int x) 
{ 
    if (top >= (size - 1)) { 
    	std::cout << "stack over flow " << std::endl;
        return false; 
    }  
    
	a[++top] = x; 
	return true; 
} 
  
inline int Stack::pop() 
{ 
    if (isEmpty()) { 
    	std::cout << "stack is empty " << std::endl;
        return -1; 
    } 
	int x = a[top--]; 
	return x; 
     
} 
inline int Stack::peek() 
{ 
    if (top < 0) { 
        return -1; 
    } 
    
    int x = a[top]; 
    return x; 
} 
  
inline bool Stack::isEmpty() 
{ 
	if(top < 0)
	{
		return true;
	}
    return false; 
} 

#endif /* __STACK_H__ */


