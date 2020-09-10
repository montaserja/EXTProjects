#ifndef __DUP_H__
#define __DUP_H__

#include"commandInterface.h"
#include"../../model/database/database.h"
#include"../../model/dna/dna_sequence/Dna_N_ID.h"
#include<vector>
#include<sstream>
#include<string>
#include<iostream>
using std::string;
using std::vector;
using std::stringstream;

class Dup: public CommandInterface{
	public:
		Dup(database* database,vector<string> input):m_database(database),input(input){};
		void execute();
	private:
		database* m_database;
		vector<string> input;

}; 

inline void Dup::execute(){
	string idStr =input[0];
	idStr.erase(0,1);
	std::stringstream sstream(idStr);
	size_t id;
	sstream >> id;
	std::cout << id << std::endl;
	
	
	string name;
	
	if(input.size()==1)
	{
		stringstream s;
		s << (m_database->getDna(id)).getName();
		while(true)
		{
			try{
				m_database->getDna(s.str());
				s<<"_1";
				name=s.str();
			}
			catch(const std::out_of_range& e)
			{
				break;
			}
		}
		name=s.str();
	}else
		name = input[1];
	
	DnaSequence* newdna=new DnaSequence(*((m_database->getDna(id)).getDna()));
	Dna_N_ID* dnaToAdd=new Dna_N_ID(newdna,name,-1);
	m_database->addDna(dnaToAdd);
}

#endif /* __DUP_H__ */
