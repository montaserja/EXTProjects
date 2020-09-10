#ifndef __SHOWLABELS_H__
#define __SHOWLABELS_H__

#include"commandInterface.h"
#include"../../model/database/database.h"
#include"../../model/label/label.h"


//typedef map<string,Label*> labelsMap;

class showLabels : public CommandInterface{
	public:
		showLabels(database* database): m_database(database){}
		void execute();
	private:
		database* m_database;

};

inline void showLabels::execute()
{
	labelsMap labels = m_database->getAllLabels();

	for (labelsMap::iterator it = labels.begin(); it!=labels.end();it++)
	{
		
		it->second->print();
	}
}

#endif /* __SHOWLABELS_H__ */
