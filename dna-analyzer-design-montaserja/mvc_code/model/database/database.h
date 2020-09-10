#ifndef __DATABASE_H__
#define __DATABASE_H__

#include"../dna/dna_sequence/Dna_N_ID.h"
#include<map>
#include<string>
#include"../label/label.h"
using std::string;
using std::map;

typedef map<size_t,Dna_N_ID*> idMap;
typedef map<string,Dna_N_ID*> nameMap;
typedef map<string,Label*> labelsMap;

class database
{
	public:
		Dna_N_ID& getDna(size_t) const;
		Dna_N_ID& getDna(string) const;
		void addDna(Dna_N_ID*);
		void addLabel(string name,Label*);
		labelsMap getAllLabels() const;
		//void remove(size_t);
		//void replace(size_t,Dna_N_ID*);
		static size_t getId() ;
		//void renum();
		~database();
	private:
		idMap idList;
		nameMap nameList;
		labelsMap labels;
		
};

inline size_t database::getId() 
{
	static size_t id=1;
	return id++;
}

inline void database::addLabel(string name,Label* label)
{
	labels[name] = label;
}

inline void database::addDna(Dna_N_ID* dna)
{
	dna->setID(getId());
	idList[dna->getID()] = dna;
	nameList[dna->getName()] = dna;
	std::cout << *idList[dna->getID()] << std::endl;
}

inline Dna_N_ID& database::getDna(size_t id) const
{
	//try{
		return 	*idList.at(id);
	//}catch(const std::out_of_range& e)
	//{
	//	std::cout << e.what() <<std::endl;
	//	return NULL;
	//}
}
inline Dna_N_ID& database::getDna(string name) const
{
	return *nameList.at(name);
}

inline database::~database()
{
	for (idMap::iterator it=idList.begin(); it!=idList.end(); ++it)
	{
		delete it->second->getDna();
    	delete it->second;
    }

}

inline labelsMap database::getAllLabels() const
{
	return labels;
}


#endif /* __DATABASE_H__ */

















