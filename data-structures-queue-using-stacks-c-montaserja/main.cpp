#include"queue.h"

#include<iostream>

using std::cout;
using std::endl;

int main()
{
	/*Stack s(2); 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack" <<endl; 
    cout << s.pop() << " Popped from stack" <<endl; 
    cout << s.pop() << " Popped from stack" <<endl; */
    
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout << q.pop() << " Popped from queue" <<endl;
    cout << q.pop() << " Popped from queue" <<endl;
    cout << q.pop() << " Popped from queue" <<endl;
    cout << q.pop() << " Popped from queue" <<endl;
    
	return 0;
}
