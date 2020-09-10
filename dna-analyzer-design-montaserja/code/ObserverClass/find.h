#ifndef __FIND_H__
#define __FIND_H__

#include"observer.h"
#include"DnaSequence.h"
#include <unistd.h>
using std::cout;
using std::endl;
class Find
{
		
	private:
		abstractObserver* observer;
	public:
		Find(){}
		void Register(abstractObserver *observer)
		{
			this->observer = observer;
		}
		void UnRegister(abstractObserver *observer)
		{
			observer = NULL;
		}
		void findDna(/*DnaSequence& dna*/)
		{
			cout << "begin find dna" << endl;
			for(int i=0; i<100 ; ++i)
			{
			
				sleep(1);
				if(observer)
					observer->update();
				else
					cout << "NULL" << endl;
			}
			cout << "end find dna" << endl;
		}


};

#endif /* __FIND_H__ */

