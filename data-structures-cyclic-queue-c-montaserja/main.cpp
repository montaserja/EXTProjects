#include"cycleQueue.h"

using std::cout;
using std::endl;

int main()
{
	int i=0;
	CycleQueue q(5);
	for(;i<6;++i)
	{
		q.push(i);
	}
	
	cout << q.pop() <<endl;
	q.push(41);
	cout << q.pop() <<endl;
	q.push(42);
	q.push(43);
	cout << q.pop() <<endl;
	cout << q.pop() <<endl;
	cout << q.pop() <<endl;
	cout << q.pop() <<endl;
	cout << q.pop() <<endl;
	
	
	
	
	return 0;
}
