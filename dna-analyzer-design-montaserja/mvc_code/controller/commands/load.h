#ifndef __LOAD_H__
#define __LOAD_H__

#include"commandInterface.h"
#include"../../model/database/database.h"
#include"new.h"
#include<vector>
#include<sstream>
#include<string>
#include<iostream>
#include<fstream>

class Load: public CommandInterface{
	public:
		Load(database* database,vector<string> input,size_t *newDefault):m_database(database),input(input),newDefault(newDefault){};
		void execute();
	private:
		database* m_database;
		vector<string> input;
		size_t *newDefault;
		
};

inline void Load::execute(){
	string fileName =input[0];
	string name;
	if(input.size()==1)
	{
		size_t pos;
		if ((pos = fileName.find(".")) != std::string::npos) 
		{
			name = fileName.substr(0, pos);
		}
		else
		{
			std::cout<< "did not created" << std::endl;
			return ;
		}
		
		stringstream s;
		s << name;
		while(true)
		{
			try{
				m_database->getDna(name);
				s<<"_1";
				name=s.str();
				
			}
			catch(const std::out_of_range& e)
			{
				break;
			}
		}
		input.push_back(s.str());
	}
	else if(input.size()==2)
	{
		
		//nothing now
	}
	else{
		std::cout<< "did not created" << std::endl;
		return ;
		
	}
	
	std::ifstream nameFileout;
	
	nameFileout.open(fileName.c_str());
	string temp;
	stringstream s;
	while (std::getline(nameFileout, temp))
	{
		std::cout<<s<< std::endl;
		s << temp;
	}
	
	input[0]=s.str();
	
	New n(m_database,input,newDefault);
	n.execute();
	nameFileout.close();
}

#endif /* __LOAD_H__ */
