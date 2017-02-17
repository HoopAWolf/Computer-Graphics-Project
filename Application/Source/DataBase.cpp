#include "DataBase.h"

void DataBase::registerItems()
{
	if (item_base_.size() == 0)  //CHECKING IF THE ITEM BASE SIZE IS 0, TO MAKE SURE IT ONLY REGISTER ONCE
	{
		ItemBase *temp_obj;  //TEMP OBJ TO STORE ITEM ID

		//-----------------------------------COMMON-----------------------------------
		//Shields
		temp_obj = new ItemKiteShield;
		item_base_[temp_obj->getItemID()] = new ItemKiteShield; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemRoundShield;
		item_base_[temp_obj->getItemID()] = new ItemRoundShield; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemDagger;
		item_base_[temp_obj->getItemID()] = new ItemDagger; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new Itemshotgun;
		item_base_[temp_obj->getItemID()] = new Itemshotgun; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemShuriken;
		item_base_[temp_obj->getItemID()] = new ItemShuriken; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemSpear;
		item_base_[temp_obj->getItemID()] = new ItemSpear; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemSword;
		item_base_[temp_obj->getItemID()] = new ItemSword; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemWoodenSword;
		item_base_[temp_obj->getItemID()] = new ItemWoodenSword; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		//-----------------------------------UNCOMMON-----------------------------------
		//Weapons
		temp_obj = new ItemBattleAxe;
		item_base_[temp_obj->getItemID()] = new ItemBattleAxe; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemGreatSword;
		item_base_[temp_obj->getItemID()] = new ItemGreatSword; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemLaserGun;
		item_base_[temp_obj->getItemID()] = new ItemLaserGun; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemM4A4;
		item_base_[temp_obj->getItemID()] = new ItemM4A4; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		//-----------------------------------RARE-----------------------------------
		temp_obj = new ItemHammer;
		item_base_[temp_obj->getItemID()] = new ItemHammer; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemKunai;
		item_base_[temp_obj->getItemID()] = new ItemKunai; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemLucille;
		item_base_[temp_obj->getItemID()] = new ItemLucille; //Register Weapon
		delete temp_obj;
		increaseItemStarting();;

		//-----------------------------------LEGENDARY-----------------------------------
		temp_obj = new ItemGiggsGun;
		item_base_[temp_obj->getItemID()] = new ItemGiggsGun; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemChickenGun;
		item_base_[temp_obj->getItemID()] = new ItemChickenGun; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

		temp_obj = new ItemMinigun;
		item_base_[temp_obj->getItemID()] = new ItemMinigun; //Register Weapon
		delete temp_obj;
		increaseItemStarting();

	}
}



ItemBase* DataBase::getItem(unsigned itemID)
{
	if (itemID < item_base_.size())  //CHECK IF ITEMID IS IN THE ITEM BASE
	{
		return item_base_[itemID];  //RETURN ITEM FROM ITEM BASE VIA ITEMID
	}

	return nullptr;  //RETURN NULL IF THERE IS NO ITME
}

//THE RARITY FOR ITEMS IS 1 = CONFIRMED DROP, 100 = ALMOST IMPOSSIBLE FOR A DROP
//THE RARITY FOR WEAPONS IS ALWAYS 100, MUST BE 100
ItemBase* DataBase::getRandomItem(bool normal_item, bool weapon_item, unsigned rarity)
{
	unsigned randNumber;
	srand(time(nullptr));

	if (normal_item)
	{
		if (rand() % (rarity + 1) == 1)
		{
			return getItem((rand() % item_starting_) + item_starting_);
		}
	}
	else if (weapon_item)
	{
		//0 - COMMON, 1 - UNCOMMON, 2 - RARE, 3 - LEGENDARY
		randNumber = rand() % rarity;

		if (randNumber > 0 && randNumber <= 50)
		{
			while (1)
			{
				randNumber = rand() % rarity;

				if (getItem(randNumber)->getRarity() == 0)
				{
					return getItem(randNumber);
				}
			}
		}
		else if (randNumber > 50 && randNumber <= 80)
		{
			while (1)
			{
				randNumber = rand() % rarity;

				if (getItem(randNumber)->getRarity() == 1)
				{
					return getItem(randNumber);
				}
			}
		}
		else if (randNumber > 80 && randNumber <= 95)
		{
			while (1)
			{
				randNumber = rand() % rarity;

				if (getItem(randNumber)->getRarity() == 2)
				{
					return getItem(randNumber);
				}
			}
		}
		else if (randNumber > 95 && randNumber <= 100)
		{
			while (1)
			{
				randNumber = rand() % rarity;

				if (getItem(randNumber)->getRarity() == 3)
				{
					return getItem(randNumber);
				}
			}
		}
	}

	return nullptr;
}

BuildingBase* DataBase::getBuilding(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < building_base_[dimensionID].size())
		return building_base_[dimensionID][positionInVector];
}

EntityDrop* DataBase::getEntityDrop(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < drop_base_[dimensionID].size())
		return drop_base_[dimensionID][positionInVector];
}

EntityBase* DataBase::getEntityMinion(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < minion_base_[dimensionID].size())
		return minion_base_[dimensionID][positionInVector];
}

EntityBase* DataBase::getEntityBoss(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < boss_base_[dimensionID].size())
		return boss_base_[dimensionID][positionInVector];
}

void DataBase::setEntity(bool isBoss, bool isMinion, unsigned dimensionID, EntityBase* entity)
{
	if (isBoss)
		boss_base_[dimensionID].push_back(entity);

	else if (isMinion)
		minion_base_[dimensionID].push_back(entity);
}

void DataBase::setEntity(unsigned dimensionID, EntityDrop* entity)
{
	drop_base_[dimensionID].push_back(entity);
}

int DataBase::sizeOfDataBase(unsigned base, unsigned dimensionID)
{

	//0 - ITEM BASE, 1 - DROP BASE, 2 - BUILDING BASE, 3 - ENTITY MINION BASE
	switch (base)
	{
	case 0:
		return item_base_.size();
	case 1:
		return drop_base_[dimensionID].size();
	case 2:
		return building_base_[dimensionID].size();
	case 3:
		return minion_base_[dimensionID].size();
	case 4: 
		return boss_base_[dimensionID].size();
	default:
		return 0;
	};
}

Color DataBase::getRarityColor(unsigned rarity)
{
	return rarity_color_[rarity];
}

void DataBase::destroyEntityDrop(unsigned dimensionID, int positionInVector)
{
	drop_base_[dimensionID].erase(drop_base_[dimensionID].begin() + positionInVector);
}

void DataBase::destroyEntityMinion(unsigned dimensionID, int positionInVector)
{
	minion_base_[dimensionID].erase(minion_base_[dimensionID].begin() + positionInVector);
}

void DataBase::destroyEntityBoss(unsigned dimensionID, int positionInVector)
{
	boss_base_[dimensionID].erase(boss_base_[dimensionID].begin() + positionInVector);
}