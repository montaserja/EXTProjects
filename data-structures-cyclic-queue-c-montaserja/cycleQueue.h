#ifndef __CYCLEQUEUE_H__
#define __CYCLEQUEUE_H__

#include<iostream>
#include<vector>

class CycleQueue{
	public:
		CycleQueue(int size):m_size(size),m_first_index(-1),m_last_index(-1){}
		~CycleQueue(){}
		int pop();
		void push(int x);
		bool isEmpty();
	private:
		std::vector<int> m_vector;
		int m_size;
		int m_first_index;
		int m_last_index;

};

inline bool CycleQueue::isEmpty()
{
	return m_vector.empty();
}

inline int CycleQueue::pop()
{
	int temp;
	if(m_first_index == -1)
	{
		std::cout << "there is no items" << std::endl;
		return -1;
	}
	
	temp = m_vector[m_first_index];
	if(m_first_index != m_last_index)
		m_first_index = (m_first_index+1) % m_size;
	else
	{
		m_last_index = -1;
		m_first_index = -1;
	}
	
	
	return temp;
	
}

inline void CycleQueue::push(int x)
{
	if(m_first_index == -1)
	{
		++m_first_index;
	}
	
	if((int)m_vector.size() < m_size)
	{
		m_vector.push_back(x);
		++m_last_index;
	}
	else
	{
		int temp = (m_last_index+1) % m_size;
		if(temp == m_first_index)
		{
			std::cout << "overflow queue" << std::endl;
			return;
		}
		else
		{
			m_last_index = temp;
			m_vector[m_last_index] = x;
		}
	}
		
}

#endif /* __CYCLEQUEUE_H__ */
