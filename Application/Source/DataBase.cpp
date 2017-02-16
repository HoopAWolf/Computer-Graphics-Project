#include "DataBase.h"

void DataBase::registerItems()
{
	if (item_base_.size() == 0)  //CHECKING IF THE ITEM BASE SIZE IS 0, TO MAKE SURE IT ONLY REGISTER ONCE
	{
		int item_starting = 0;  //STARTING ITEM PLACEMENT
		ItemBase *temp_obj;  //TEMP OBJ TO STORE ITEM ID
		
		//temp_obj = new ItemLightSword;
		//item_base_[temp_obj->getItemID()] = new ItemLightSword;  //REGISTER WEAPON
		//delete temp_obj;  //DELETE OBJ WHEN REGISTERED
		//item_starting++;  //INCREASE BY ONE WHEN ITEM REGISTERED IS WEAPON



		//Weapons
		temp_obj = new ItemBattleAxe;
		item_base_[temp_obj->getItemID()] = new ItemBattleAxe; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemGreatSword;
		item_base_[temp_obj->getItemID()] = new ItemGreatSword; //Register Weapon
		delete temp_obj;
		item_starting++;


		temp_obj = new ItemChickenGun;
		item_base_[temp_obj->getItemID()] = new ItemChickenGun; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemDagger;
		item_base_[temp_obj->getItemID()] = new ItemDagger; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemGiggsGun;
		item_base_[temp_obj->getItemID()] = new ItemGiggsGun; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemHammer;
		item_base_[temp_obj->getItemID()] = new ItemHammer; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemKunai;
		item_base_[temp_obj->getItemID()] = new ItemKunai; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemLaserGun;
		item_base_[temp_obj->getItemID()] = new ItemLaserGun; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemLucille;
		item_base_[temp_obj->getItemID()] = new ItemLucille; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemM4A4;
		item_base_[temp_obj->getItemID()] = new ItemM4A4; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemMinigun;
		item_base_[temp_obj->getItemID()] = new ItemMinigun; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new Itemshotgun;
		item_base_[temp_obj->getItemID()] = new Itemshotgun; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemShuriken;
		item_base_[temp_obj->getItemID()] = new ItemShuriken; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemSpear;
		item_base_[temp_obj->getItemID()] = new ItemSpear; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemSword;
		item_base_[temp_obj->getItemID()] = new ItemSword; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemWoodenSword;
		item_base_[temp_obj->getItemID()] = new ItemWoodenSword; //Register Weapon
		delete temp_obj;
		item_starting++;


		//Shields
		temp_obj = new ItemKiteShield;
		item_base_[temp_obj->getItemID()] = new ItemKiteShield; //Register Weapon
		delete temp_obj;
		item_starting++;

		temp_obj = new ItemRoundShield;
		item_base_[temp_obj->getItemID()] = new ItemRoundShield; //Register Weapon
		delete temp_obj;
		item_starting++;






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

ItemBase* DataBase::getRandomItem(bool normal_item, bool weapon_item, unsigned rarity)
{
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
		if (rand() % (rarity + 1) == 1)
		{
			return getItem((rand() % item_starting_));
		}
	}
}