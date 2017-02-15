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