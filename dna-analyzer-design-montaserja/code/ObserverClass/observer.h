#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class abstractObserver
{
	public:
		virtual void update() =0;
};



#endif /* __OBSERVER_H__ */

/*#ifndef __OBSERVER_A_H__
#define __OBSERVER_A_H__

#include<iostream>

class ObserverA : public abstractObserver
{
	public:
		void update()
		{
			std::cout << "I am notified" << std::endl;
		}
};

#endif*/ /* __OBSERVER_A_H__ */
