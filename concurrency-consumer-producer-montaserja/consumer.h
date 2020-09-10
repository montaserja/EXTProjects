#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include"box.h"
#include<iostream>
#include"product.h"

class Consumer
{
	public:
		Consumer(unsigned char amount,Box* const  box):amount(amount),box(box),m_id(consumers_id++),m_consumed(0){};
		bool consume();
		unsigned char get_amount(){return amount;};
	private:
		unsigned char amount;
		Box* const box;
		int m_id;
		static int consumers_id ;
		unsigned char m_consumed;
};

inline bool Consumer::consume()
{
	//std::cout << (int)m_consumed << "   "<< (int)amount <<std::endl;
	if(m_consumed < amount){
		Product *product = box->remove_product();
		if(product !=NULL){
			std::cout << "Consumer " << m_id <<",consumed product number : " << product->get_number() << std::endl;
			++m_consumed;
			delete(product);
		}
		
		return true;
	}
	return false;
}

#endif /* __CONSUMER_H__ */
