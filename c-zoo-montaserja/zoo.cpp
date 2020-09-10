#include"zoo.h"


/*void Zoo::createZoo()
{

	Lion m1("Simba");
	Lion m2("Mufasa");
	Monkey m3("Rafiki");
	Dog d("Toto");
	Goose b1("Akka");
	Goose b2("Morten");
	Snowyowl b3("Hedwig");
	ClownFish f2("Nemo");
	Shark f1("Jaws ");
	Whale w("Willy");
	
	vector.push_back(&m1);
	vector.push_back(&m2);
	vector.push_back(&m3);
	vector.push_back(&d);
	vector.push_back(&b1);
	vector.push_back(&b2);
	vector.push_back(&b3);
	vector.push_back(&f1);
	vector.push_back(&f2);
	vector.push_back(&w);
	
		//std::cout << *vector[3] << std::endl;
		printZoo();
}*/


void Zoo::add_element(Animal *a)
{
	vector.push_back(a);
}

void Zoo::printZoo()
{
	size_t i=0;
	
	for(;i<vector.size();i++)
	{
		std::cout << *vector[i]  << "\n"<< std::endl;
	}

}














