#ifndef _ITEM_BASE_H_
#define _ITEM_BASE_H_

#include <string>
#include "DetectMemoryLeak.h"
#include "vertex.h"

using std::string;

class ItemBase abstract
{

protected:
	enum RARITY
	{
		COMMON,
		UNCOMMON,
		RARE,
		LEGENDARY
	};
	unsigned itemID_;

	string texture_string_;
	string item_name_;
	RARITY rarity_;

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
	
	virtual RARITY getRarity()
	{
		return rarity_;
	}

	//------------------USES------------------
	virtual void onItemUse(float timer) = 0;


};

#endif