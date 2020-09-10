#ifndef __NUCLEOTIDE_H__
#define __NUCLEOTIDE_H__

#include<string>
#include<iostream>
class Nucleotide
{

	public:
		Nucleotide(const char &);
		~Nucleotide();
		const char& getNuc();
		
	private:
		char m_nuc;
		static const std::string consist;
		bool check_nuc_valid(const char&);

};

inline Nucleotide::Nucleotide(const char & nuc):m_nuc(nuc)
{
	//std::cout<<nuc <<std::endl;
	if(!check_nuc_valid(nuc))
		throw std::invalid_argument("wrong dna nuc");
}

inline Nucleotide::~Nucleotide(){}

inline const char& Nucleotide::getNuc()
{
	return m_nuc;
}

inline bool Nucleotide::check_nuc_valid(const char& nuc)
{
	unsigned int i=0;
	for(;i<consist.length();++i)
	{
		if(nuc==consist[i])
			return true;		
	}
	return false;

}


#endif /* __NUCLEOTIDE_H__ */
