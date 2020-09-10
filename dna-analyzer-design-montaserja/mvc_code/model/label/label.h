#ifndef __LABEL_H__
#define __LABEL_H__

#include<vector>
#include<iostream>
#include<string>
class Label
{
	public:
		Label(string name):m_name(name){};
		void addNum(size_t num){
			m_label.push_back(num);
		}	
		
		void print(){
			std::cout << m_name << ": [";
			for(std::vector<size_t>::iterator it = m_label.begin(); it!=m_label.end();it++)
				std::cout << *it;
			
			std::cout << "]" << std::endl;
		}
		
		std::vector<size_t> get_label() const{
			return m_label;
		}
		
	private:
		std::vector<size_t> m_label;
		string m_name;
};

#endif /* __LABEL_H__ */
