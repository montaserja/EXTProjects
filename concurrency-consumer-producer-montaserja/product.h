#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <stdlib.h> 
#include<iostream>
#define MAX_RANGE 1000000

class Product
{
	public:
		Product(){
			
			static int num =0;
			number = num++;
			//std::cout << "product init "<< number << std::endl;
		}
		unsigned int get_number(){
			return number;
		};
	private:
		unsigned int number;
		
};

#endif /* __PRODUCT_H__ */
