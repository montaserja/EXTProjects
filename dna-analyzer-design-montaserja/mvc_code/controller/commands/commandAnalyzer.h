#ifndef __COMMANDANALYZER_H__
#define __COMMANDANALYZER_H__

#include"../../model/database/database.h"
#include"../../model/dna/dna_sequence/Dna_N_ID.h"
#include"../../model/label/label.h"
#include"new.h"
#include"load.h"
#include"dup.h"
#include"len.h"
#include<vector>
#include<sstream>
#include<fstream>
#include"showLabels.h"

#include<string>
#include<iostream>

using std::string;
using std::vector;
using std::stringstream;

class commandAnalyzer
{
	public:
		commandAnalyzer(database*);
		void newDna(vector<string>);
		void loadDna(vector<string>);
		void dupDna(vector<string>);
		void lenDna(vector<string>);
		void findDna(vector<string>);
		void findAllDna(vector<string>);
		string getLabelName(vector<string>);
		Dna_N_ID* getDnaFromInput(string input) const;
		void showLabel();
	private:
		database* m_database;
		size_t newDefault;
};

inline commandAnalyzer::commandAnalyzer(database* database): m_database(database) , newDefault(1){}

inline void commandAnalyzer::newDna(vector<string> input)
{
	New n(m_database,input,&newDefault);
	n.execute();
}

inline void commandAnalyzer::loadDna(vector<string> input)
{
	Load n(m_database,input,&newDefault);
	n.execute();
}


inline void commandAnalyzer::dupDna(vector<string> input)
{
	Dup n(m_database,input);
	n.execute();
}


inline void commandAnalyzer::lenDna(vector<string> input)
{
	Len n(m_database,input);
	n.execute();
}

inline Dna_N_ID* commandAnalyzer::getDnaFromInput(string input) const
{
	if(input[0] == '#'){
		std::stringstream sstream(input.erase(0,1));
		size_t id;
		sstream >> id;
		return &(m_database->getDna(id));
	}
	else if(input[0] == '@'){
		return &(m_database->getDna(input.erase(0,1)));
	}else
	{
		return NULL;
	}
}

inline string commandAnalyzer::getLabelName(vector<string> input){
	string label_name = input[input.size()-1];
	if(input.size() < 2 || input[input.size()-2] != ":" || label_name.length() <= 1 || label_name[0] != '@')
		return "";
	return label_name.erase(0,1);
}

inline void commandAnalyzer::findDna(vector<string> input)
{
	if(input.size() == 0)
		return ;
	
	string label_name = getLabelName(input);
	Dna_N_ID *dna = getDnaFromInput(input[0]);
	
	if(!dna)
		return ;
	
	DnaSequence d(input[1]);
	size_t result = dna->getDna()->find(d);
	std::cout  << result <<  std::endl;
	if(label_name != "")
	{
		Label *label = new Label(label_name);
		label->addNum(result);
		m_database->addLabel(label_name,label);
	}
}

inline void commandAnalyzer::findAllDna(vector<string> input)
{
	if(input.size() == 0)
		return ;
	Dna_N_ID *dna = getDnaFromInput(input[0]);
	DnaSequence d(input[1]);
	std::list<int> lis = dna->getDna()->findAll(d);
	
	for(std::list<int>::iterator it = lis.begin() ; it !=lis.end() ; it++)
	{
		std::cout  << *it <<std::endl;
	}
}

inline void commandAnalyzer::showLabel()
{
	
	showLabels show(m_database);
	show.execute();
	
	
}

#endif /* __COMMANDANALYZER_H__ */











