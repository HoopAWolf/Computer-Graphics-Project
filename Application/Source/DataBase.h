#ifndef _DATA_BASE_H_
#define _DATA_BASE_H_

#include "ItemWeapon.h"
#include "ItemLightSword.cpp"
#include "EntityDrop.h"
#include <vector>
#include <map>
#include <string>
#include <time.h>

using std::vector;
using std::string;
using std::map;

class DataBase
{
private:
	static DataBase *s_instance;
	DataBase(){};

	unsigned item_starting_ = 2;
	map<unsigned, ItemBase *> item_base_;
	vector<EntityDrop *> drop_base_;


public:
	static DataBase *instance()
	{
		if (!s_instance)
			s_instance = new DataBase;

		return s_instance;
	}

	void registerWeapons();
	ItemBase* getItem(unsigned itemID);
	ItemBase* getRandomItem(bool normal_item, bool weapon_item, unsigned rarity);


};

#endif