#ifndef _DATA_BASE_H_
#define _DATA_BASE_H_

#include "ItemWeapon.h"
#include "EntityDrop.h"
#include "EntityMinion.h"
#include "EntityBoss.h"
#include "BuildingBase.h"


//Weapons 
#include "ItemBattleAxe.cpp"
#include "ItemGreatSword.cpp"
#include "ItemChestPlate.cpp"
#include "ItemChickenGun.cpp"
#include "ItemDagger.cpp"
#include "ItemGiggsGun.cpp"
#include "ItemHammer.cpp"
#include "ItemKunai.cpp"
#include "ItemLaserGun.cpp"
#include "ItemLucille.cpp"
#include "ItemM4A4.cpp"
#include "ItemMinigun.cpp"
#include "Itemshotgun.cpp"
#include "ItemShuriken.cpp"
#include "ItemSpear.cpp"
#include "ItemSword.cpp"
#include "itemWoodenSword.cpp"



//non weapons but still here for I dont know what reason lel
#include "ItemKiteShield.cpp"
#include "ItemRoundShield.cpp"



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
	DataBase()
	{
			/*COMMON,
			UNCOMMON,
			RARE,
			LEGENDARY*/

		rarity_color_[0] = Color(1, 1, 1);
		rarity_color_[1] = Color(0.137255, 0.556863, 0.419608);
		rarity_color_[2] = Color(0.35, 0.35, 0.67);
		rarity_color_[3] = Color(0.81, 0.71, 0.23);
	
	}

	unsigned item_starting_ = 0;  //STORES THE ITEM STARTING POSITION FOR THE ITEM DATA BASE
	map<unsigned, ItemBase *> item_base_;  //STORES ALL THE ITEMS INTO THE DATABASE
	map<unsigned, vector<EntityDrop *>> drop_base_;  //STORES ALL ENTITY DROPS IN THE WORLD
	map<unsigned, vector<BuildingBase *>> building_base_;  //STORES ALL BUILDINGS IN THE WORLD
	map<unsigned, vector<EntityBase *>> minion_base_;  //STORES ALL ENTITY MINION IN THE WORLD
	map<unsigned, vector<EntityBase *>> boss_base_;  //STORES ALL ENTITY BOSS IN THE WORLD
	Color rarity_color_[4];

public:
	static DataBase *instance()  //GETTING THE INSTANCE OF THE CLASS
	{
		if (!s_instance)
			s_instance = new DataBase;  //CREATE A NEW INSTANCE IF THERE IS NONE AVAILABLE

		return s_instance;  //RETURNS THE INSTANCE IF THERE IS ONE AVAILABLE
	}

	void registerItems();  //REGISTER ALL ITEMS ONLY ONCE
	ItemBase* getItem(unsigned itemID);  //RETURN ITEM THROUGH ITEMID
	ItemBase* getRandomItem(bool normal_item, bool weapon_item, unsigned rarity = 100);  //GET RANDOM ITEM THROUGH RARITY AND IF IT IS A NORMAL ITEM OR A WEAPON ITEM

	BuildingBase* getBuilding(unsigned dimensionID, int positionInVector);
	EntityDrop* getEntityDrop(unsigned dimensionID, int positionInVector);
	EntityBase* getEntityMinion(unsigned dimensionID, int positionInVector);
	EntityBase* getEntityBoss(unsigned dimensionID, int positionInVector);

	int sizeOfDataBase(unsigned base, unsigned dimensionID = 0);
	void setEntity(bool isBoss, bool isMinion, unsigned dimensionID, EntityBase* entity);
	void setEntity(unsigned dimensionID, EntityDrop* entity);
	void increaseItemStarting()
	{
		++item_starting_;
	}

	unsigned getItemStarting()
	{
		return item_starting_;
	}

	Color getRarityColor(unsigned rarity);

	void destroyEntityDrop(unsigned dimensionID, int positionInVector);
	void destroyEntityMinion(unsigned dimensionID, int positionInVector);
	void destroyEntityBoss(unsigned dimensionID, int positionInVector);
	
};

#endif