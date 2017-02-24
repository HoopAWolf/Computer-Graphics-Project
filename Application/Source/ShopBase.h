#ifndef _SHOP_BASE_H_
#define _SHOP_BASE_H_

#include "DataBase.h"
#include "PlayerBase.h"

class ShopBase
{
private:
	static ShopBase *s_instance;  //CREATE AN INSTANCE OF THE CLASS OBJECT
	vector<ItemBase*> shop_items_;
	ShopBase(){}

public:
	static ShopBase *instance()  //GETTING THE INSTANCE OF THE CLASS
	{
		if (!s_instance)
			s_instance = new ShopBase;  //CREATE A NEW INSTANCE IF THERE IS NONE AVAILABLE

		return s_instance;  //RETURNS THE INSTANCE IF THERE IS ONE AVAILABLE
	}

	void startShop();
	ItemBase* getItemInShop(int position);
	int getShopItemSize();
	void buyItem(int position);
	void sellItem();
};

#endif