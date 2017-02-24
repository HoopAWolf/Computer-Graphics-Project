#include "ShopBase.h"

void ShopBase::startShop()
{
	for (int i = 0; i < 6; i++)
	{
		shop_items_.push_back(DataBase::instance()->getRandomItem(false, true));
	}
}
ItemBase* ShopBase::getItemInShop(int position)
{
	return shop_items_[position];
}

int ShopBase::getShopItemSize()
{
	return shop_items_.size();
}

void ShopBase::buyItem(int position)
{
	if (PlayerBase::instance()->getPlayerCurrency() > (dynamic_cast<ItemWeapon*>(shop_items_[position])->getPriceOfWeapon()))
	{
		if (!PlayerBase::instance()->isInventoryFull())
		{
			PlayerBase::instance()->decreaseCurrency((dynamic_cast<ItemWeapon*>(shop_items_[position])->getPriceOfWeapon()));
			PlayerBase::instance()->addIntoPlayerInventory(shop_items_[position]->getItemID());
			shop_items_[position] = nullptr;
		}
	}
}

void ShopBase::sellItem()
{

}