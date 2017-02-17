#include "EntityDrop.h"
#include "DataBase.h"

string EntityDrop::getDropInfo()
{
	string info_data;

	info_data +=  DataBase::instance()->getItem(getItemDrop())->getItemName();

	/*if (getItemDrop() <= DataBase::instance()->getItemStarting())
	{
		ItemWeapon* tempObj = (ItemWeapon*)DataBase::instance()->getItem(getItemDrop());
		info_data += "Damage: " + tempObj->getWeaponDamage();
		info_data += "Attack Speed: " + tempObj->getWeaponAttackSpeed();
		info_data += "Durability: " + tempObj->getWeaponDurability();
	}*/

	return info_data;
}
