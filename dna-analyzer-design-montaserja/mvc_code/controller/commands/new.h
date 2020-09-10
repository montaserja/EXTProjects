#ifndef __NEW_H__
#define __NEW_H__

#include"commandInterface.h"
#include"../../model/database/database.h"
#include<vector>
#include<sstream>
#include<string>
#include<iostream>
using std::string;
using std::vector;
using std::stringstream;

class New: public CommandInterface{
	public:
		New(database* database,vector<string> input,size_t *newDefault):m_database(database),input(input),newDefault(newDefault){};
		void execute();
	private:
		database* m_database;
		vector<string> input;
		size_t *newDefault;
};

inline void New::execute(){
	
	string seq =input[0];
	string name;
	if(input.size()==1)
	{
		stringstream s;
		s << "seq";
		s << *newDefault++;
		name=s.str();
	}
	else if(input.size()==2)
	{
		
		name=input[1];
	}
	else{
		std::cout<< "did not created" << std::endl;
		return ;
		
	}
	DnaSequence* newdna=new DnaSequence(seq);
	Dna_N_ID* dnaToAdd=new Dna_N_ID(newdna,name,-1);
	m_database->addDna(dnaToAdd);
}

#endif /* __NEW_H__ */
