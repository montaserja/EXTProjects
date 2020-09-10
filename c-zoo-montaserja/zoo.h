#ifndef __ZOO_H__
#define __ZOO_H__
#include <vector>
#include"mammals.h"
#include"fishes.h"
#include"birds.h"
#include"whale.h"
typedef std::vector<Animal*> AnimalVector;
typedef std::vector<Animal*>::iterator Iterator;
class Zoo
{
	public:
		//void createZoo();
		void printZoo();
		void add_element(Animal *a);
	private:
		AnimalVector vector;
};


#endif
