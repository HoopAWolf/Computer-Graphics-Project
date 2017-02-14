#ifndef _ITEM_BASE_H_
#define _ITEM_BASE_H_

#include <string>
#include "DetectMemoryLeak.h"

using std::string;

class ItemBase abstract
{

protected:
	unsigned itemID_;

	string texture_string_;
	string item_name_;


public:
	virtual ~ItemBase(){};

	//------------------GETTERS------------------
	virtual string getTextureString()
	{
		return texture_string_;
	}

	virtual string getItemName()
	{
		return item_name_;
	}

	virtual unsigned getItemID()
	{
		return itemID_;
	}

	//------------------USES------------------
	virtual void onItemUse() = 0;


};

#endif