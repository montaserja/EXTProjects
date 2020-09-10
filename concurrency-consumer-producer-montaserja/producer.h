#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include<iostream>
#include"product.h"
#include"box.h"
#include<unistd.h>

class Producer
{
	public:
		Producer(unsigned char amount,Box* const  box):amount(amount),box(box),m_id(id++),m_produced(0){};
		bool produce();
		unsigned char get_amount(){return amount;};
	private:
		unsigned char amount;
		Box* const box;
		int m_id;
		static int id ;
		unsigned char m_produced;
		
};

inline bool Producer::produce()
{
	
	if(m_produced < amount){
		
		Product* product = new Product();
		while(!box->add_product(product)){
			usleep(1);	
		}
		
		std::cout << "Producer " << m_id <<",created product number : " << product->get_number() << std::endl;
		++m_produced;
		
		return true;
	}

	return false;
}

#endif /* __PRODUCER_H__ */
