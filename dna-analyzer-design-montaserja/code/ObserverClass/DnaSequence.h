#ifndef __DNASEQUENCE_H__
#define __DNASEQUENCE_H__


#include<string>
using std::string;
#include"nucleotide.h"
#include<iostream>
#include <cstring>
#include <iterator> 
#include <map>
#include <list>

//static const char *sequenc="ACTG";
class DnaSequence
{
	public:
		DnaSequence(char* name,char*);
		DnaSequence(char* name,const string&);
		DnaSequence(const DnaSequence&);
		~DnaSequence();
		DnaSequence& operator=(const DnaSequence &);
		DnaSequence& operator=(const char*); 
		DnaSequence& operator=(const std::string&); 
		const char& operator[](size_t) const;
		DnaSequence slice(size_t,size_t);
		DnaSequence pair() ;
		friend std::ostream& operator<<(std::ostream &os, const DnaSequence  &);
		size_t find(DnaSequence &) const;
		
		std::map<char, char> pair_map;
		const size_t& getSize() const;
		size_t count(DnaSequence&);
		std::list<int> findAll(DnaSequence&);
		std::list<DnaSequence> FindConsensusSequences();
		char m_name[256];
		size_t m_id;
		
	private:
		Nucleotide** m_nuc_arr;
		size_t size;
		void setMap();
		void allocate_arr(char *);
		void free_arr();
		
		
		static size_t id;
		

};

inline void DnaSequence::setMap()
{
	pair_map['G']='C';
	pair_map['C']='G';
	pair_map['A']='T';
	pair_map['a']='t';
	pair_map['T']='A';
	pair_map['c']='g';
	pair_map['g']='c';
	pair_map['t']='a';
}

inline DnaSequence::DnaSequence(char* name,char * seq = NULL )
{
		allocate_arr(seq);
		strcpy(m_name,name);
		m_id=id++;
		
		
}

inline size_t DnaSequence::count(DnaSequence& dnaSeq)
{
	return findAll(dnaSeq).size();
}


inline DnaSequence::DnaSequence(char* name,const string& str)
{
	allocate_arr(const_cast<char*>(str.c_str()));
	strcpy(m_name,name);
	m_id=id++;
}


inline void DnaSequence::allocate_arr(char * seq)
{
	size=strlen(seq);
	m_nuc_arr= new Nucleotide*[size];
	for(size_t i=0;i<size;++i)
	{
		m_nuc_arr[i]=new Nucleotide(seq[i]);
		//std::cout << (*m_nuc_arr[i]).getNuc() << std::endl;
	}
}


inline DnaSequence::DnaSequence(const DnaSequence& other)
{
	
		char* temp = new char[other.size+1]; 
		size_t i=0 ;
		for ( ; i < other.size ; ++i ){
			temp[i] = other.m_nuc_arr[i]->getNuc();
		}
		temp[i]='\0';
		allocate_arr(temp);
		delete [] temp;
		
		strcpy(m_name,other.m_name);
		m_id=other.m_id;

	
}


inline const size_t& DnaSequence::getSize() const 
{
	return size;
}


inline DnaSequence& DnaSequence::operator =(const DnaSequence &other)
{

	free_arr();
	char* copy = new char[other.size+1]; 
	size_t i=0;
	for (  ; i < other.size ; ++i )
	{
		copy[i] = other.m_nuc_arr[i]->getNuc();
	}
	copy[i]='\0';
	allocate_arr(copy);
	delete [] copy;
	return *this;
}

inline DnaSequence& DnaSequence::operator =(const char* copy)
{
	free_arr();
	allocate_arr(const_cast<char*>(copy));
	return *this;
}
inline DnaSequence& DnaSequence::operator =(const std::string& copy)
{
	free_arr();
	allocate_arr(const_cast<char*>(copy.c_str()));
	return *this;
}
inline std::ostream& operator<<(std::ostream &os, const DnaSequence  & dnaSeq)
{
	size_t i=0;
	os <<   "["<< dnaSeq.m_id <<"] "<< "  name:" << dnaSeq.m_name << " seq: ";
	for(;i<dnaSeq.size;++i)
	{
		os << (*dnaSeq.m_nuc_arr[i]).getNuc();
	}
	return os;
}


inline const char& DnaSequence::operator[](size_t index) const
{
	return m_nuc_arr[index]->getNuc();

}





inline DnaSequence DnaSequence::pair() 
{
	size_t i=0;
	setMap();
	char *temp=new char[size];
	
	for(;i<size;++i)
	{
		temp[i]=pair_map[(*m_nuc_arr[size-i-1]).getNuc()];
	}
	DnaSequence dna(temp);
	delete [] temp;
	return dna;
	
}




inline void DnaSequence::free_arr()
{
	size_t i=0;
	for(;i<size;++i)
		delete m_nuc_arr[i];
	delete [] m_nuc_arr;
}


inline DnaSequence::~DnaSequence()
{
	free_arr();
}



#endif /* __DNASEQUENCE_H__ */
