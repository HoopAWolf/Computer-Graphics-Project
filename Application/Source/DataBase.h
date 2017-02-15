#ifndef _DATA_BASE_H_
#define _DATA_BASE_H_

#include "ItemWeapon.h"
#include "ItemLightSword.cpp"
#include "EntityDrop.h"
#include "EntityMinion.h"
#include "EntityBoss.h"

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
	static DataBase *s_instance;  //CREATE AN INSTANCE OF THE CLASS OBJECT
	DataBase(){};

	unsigned item_starting_ = 2;  //STORES THE ITEM STARTING POSITION FOR THE ITEM DATA BASE
	map<unsigned, ItemBase *> item_base_;  //STORES ALL THE ITEMS INTO THE DATABASE
	vector<EntityDrop *> drop_base_;  //STORES ALL ENTITY DROPS IN THE WORLD
	vector<EntityMinion *> minion_base_;  //STORES ALL ENTITY MINION IN THE WORLD
	vector<EntityBoss *> boss_base_;  //STORES ALL ENTITY BOSS IN THE WORLD


public:
	static DataBase *instance()  //GETTING THE INSTANCE OF THE CLASS
	{
		if (!s_instance)
			s_instance = new DataBase;  //CREATE A NEW INSTANCE IF THERE IS NONE AVAILABLE

		return s_instance;  //RETURNS THE INSTANCE IF THERE IS ONE AVAILABLE
	}

	void registerItems();  //REGISTER ALL ITEMS ONLY ONCE
	ItemBase* getItem(unsigned itemID);  //RETURN ITEM THROUGH ITEMID
	ItemBase* getRandomItem(bool normal_item, bool weapon_item, unsigned rarity);  //GET RANDOM ITEM THROUGH RARITY AND IF IT IS A NORMAL ITEM OR A WEAPON ITEM


};

#endif