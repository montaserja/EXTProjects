#ifndef __LEN_H__
#define __LEN_H__

#include"commandInterface.h"
#include"../../model/database/database.h"
#include<vector>
#include<sstream>
#include<string>
#include<iostream>
using std::string;
using std::vector;
using std::stringstream;

class Len: public CommandInterface{
	public:
		Len(database* database,vector<string> input):m_database(database),input(input){};
		void execute();
	private:
		database* m_database;
		vector<string> input;
};

inline void Len::execute(){
	size_t id;
	std::stringstream sstream(input[0]);
	sstream >> id;
	if (id != 0)
	{
		std::cout << (m_database->getDna(id)).getDna()->getSize() << std::endl;
	}
	else
	{
		std::cout << "invalid id" << std::endl;
	}
}

#endif /* __LEN_H__ */
