#ifndef _ITEM_BASE_H_
#define _ITEM_BASE_H_

#include <string>
#include "DetectMemoryLeak.h"

using std::string;

class ItemBase abstract
{

protected:
	int itemID_;

	string texture_string_;
	string item_name_;


public:
	virtual ~ItemBase(){};

	//------------------GETTERS------------------
	virtual string getTextureString() = 0;
	virtual string getItemName() = 0;
	virtual int getItemID() = 0;

	//------------------USES------------------
	virtual void onItemUse() = 0;


};

#endif