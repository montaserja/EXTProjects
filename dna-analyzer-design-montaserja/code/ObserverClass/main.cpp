
#include<string>
#include<iostream>
#include"find.h"

using std::cout;
using std::endl;


class ObserverA : public abstractObserver
{
	public:
		void update()
		{
			std::cout << "I am notified" << std::endl;
		}
};

int main()
{
	Find f;
	ObserverA a;
	f.Register(&a);
	f.findDna();
	return 0;
}

