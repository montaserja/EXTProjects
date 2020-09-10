#include"allSequences.h"
#include <sstream>
#include <fstream> 
#include<iostream>
void allSequences::newseq(char* seq,char* name)
{

	if(!name)
	{
		std::stringstream ss;
		ss << "seq" << default_name_id++;
		name = const_cast<char*>(ss.str().c_str());
		//default
	}
	
	DnaSequence dna(name,seq);
	sequences.push_back(dna);
	std::cout << dna << std::endl;
	m_size++;
	
}

void allSequences::loadseq(char* file_name,char* name)
{
	std::ifstream myReadFile;
 	myReadFile.open(file_name);
 	char seq[256];
	 if (myReadFile.is_open()) {
		 while (!myReadFile.eof()) {
			myReadFile >> seq;
		 }
	}
	seq[strlen(seq)+1]='\0';
	
	
	if(!name)
	{
		char* my_temp_name=strtok(file_name,".");
		std::stringstream default_name;
		default_name << my_temp_name;
		int count=0;
		 for (seqVector::iterator it = sequences.begin() ; it != sequences.end(); ++it)
		 {
		 	if(it->m_name == default_name.str())
		 		count++;
		 }
		 if(count > 0)
		 	default_name << "_" << count;
		 //std::cout << default_name.str() << std::endl;
		 name=(char*)default_name.str().c_str();
	}
	
	newseq(seq,name);
}











