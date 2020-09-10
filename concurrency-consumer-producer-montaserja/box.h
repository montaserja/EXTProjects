#ifndef __BOX_H__
#define __BOX_H__

#include<vector>
#include"product.h"
#include<iostream>
#include<pthread.h>



class Box
{
	public:
		Box(unsigned char size=6):m_size(size)
		{
			pthread_mutex_init(&producers_mutex,NULL);
		}
		bool add_product(Product*);
		Product* remove_product();
	private:
		unsigned char m_size;
		std::vector<Product*> m_box;
		pthread_mutex_t producers_mutex;
};

inline bool Box::add_product(Product* product)
{
	pthread_mutex_lock( &producers_mutex );
	if(m_box.size() >= m_size)
	{
		pthread_mutex_unlock( &producers_mutex );
		return false;
	}

	m_box.push_back(product);
	pthread_mutex_unlock( &producers_mutex );
	return true;
}

inline Product* Box::remove_product()
{
pthread_mutex_lock( &producers_mutex );
	if(m_box.size() <= 0)
	{
		pthread_mutex_unlock( &producers_mutex );
		return NULL;
	}
	
	Product *product = *m_box.begin();
	m_box.erase(m_box.begin());
	pthread_mutex_unlock( &producers_mutex );
	return product;
	
}

#endif /* __BOX_H__ */









