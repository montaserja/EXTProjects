#ifndef DNA_N_ID_H
#define DNA_N_ID_H

#include"DnaSequence.h"

#include<string>
#include<iostream>
using std::string;

class Dna_N_ID
{
	public:
		Dna_N_ID(DnaSequence*,string,size_t);
		size_t getID() const;
		DnaSequence* getDna() const;
		string getName() const;
		
		void setID(size_t);
		void setDna(DnaSequence*);
		void setName(string);
		friend std::ostream& operator<<(std::ostream &os, const Dna_N_ID  &);
		
		
	private:
		DnaSequence* m_dna;
		string m_name;
		size_t m_id;
		
		
		
};

inline Dna_N_ID::Dna_N_ID(DnaSequence* dna,string name,size_t id): m_dna(dna) , m_name(name) , m_id(id){}

inline size_t Dna_N_ID::getID() const
{
	return m_id;
}


inline DnaSequence* Dna_N_ID::getDna() const
{
	return m_dna;
}

inline string Dna_N_ID::getName() const
{
	return m_name;
}

inline void Dna_N_ID::setID(size_t id)
{
	m_id=id;
}

inline void Dna_N_ID::setDna(DnaSequence* dna)
{
	m_dna=dna;
}

inline void Dna_N_ID::setName(string name)
{
	m_name=name;
}

inline std::ostream& operator<<(std::ostream &os, const Dna_N_ID  & dnaSeq)
{
	os << "[" << dnaSeq.getID() << "] " << dnaSeq.getName() << ": " << *dnaSeq.getDna();
	return os;
}

#endif /* DNA_N_ID_H */




