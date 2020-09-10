#include"test.h"
#include"mammal.h"
#include"fish.h"
#include"bird.h"
#include<iostream>
#include"zoo.h"
#include"mammals.h"
#include"fishes.h"
#include"birds.h"
#include"whale.h"

using std::cout;
using std::endl;
/*
using std::cout;
using std::endl;


void test_mammal()
{
	
	Continents c;
	c.Africa=1;
	Mammal m1("Mofasa","Cats",20,c,CARNIVORES,40,1,1);
	m1.printDetails();
}

void testFish()
{

	Continents c;
	c.Africa=1;
	Fish f1("shark","fish",20,c,CARNIVORES,40,-1000);
	f1.printDetails();
}

void testBird()
{

	Continents c;
	c.Africa=1;
	Bird f1("soso","bird",20,c,CARNIVORES,40,1000,9.8f);
	f1.printDetails();
}
*/
void testZoo()
{
	Zoo zoo;
	
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
	
	
	zoo.add_element(&m1);
	zoo.add_element(&m2);
	zoo.add_element(&m3);
	zoo.add_element(&d);
	zoo.add_element(&b1);
	zoo.add_element(&b2);
	zoo.add_element(&b3);
	zoo.add_element(&f2);
	zoo.add_element(&f1);
	zoo.add_element(&w);
	
	//zoo.createZoo();
	zoo.printZoo();
}

void test_lion()
{
	Lion l1("Simba");
	cout << l1 <<endl;
	
}

void test_shark()
{
	Shark s1("nimoSh");
	cout << s1 <<endl;
	
}

void test_goose()
{
	Goose g1("gosese");
	cout << g1 <<endl;
	
}

void test_whale()
{
	Whale w1("willy");
	cout << w1 <<endl;
	
}











