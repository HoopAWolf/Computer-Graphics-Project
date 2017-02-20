#include "EntityDrop.h"
#include "DataBase.h"

string EntityDrop::getDropInfo(unsigned iterator)
{
	string info_data;

	switch (iterator)
	{
	case 0:
		info_data = DataBase::instance()->getItem(getItemDrop())->getItemName();
		break;
	case 1:
		if (getItemDrop() <= DataBase::instance()->getItemStarting())
		{
			info_data = "Damage: " + std::to_string(((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponDamage());
			unsigned playerDamage = ((PlayerBase::instance()->getCurrentHeldItem() != nullptr) ? ((ItemWeapon*)PlayerBase::instance()->getCurrentHeldItem())->getWeaponDamage() : 1);

			if (((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponDamage() > playerDamage)
				info_data += " ^ ";
			else if (((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponDamage() <  playerDamage)
				info_data += " v ";
			else
				info_data += " == ";

			info_data += '(' + std::to_string(playerDamage) + ')';
		}
		break;
	case 2:
		if (getItemDrop() <= DataBase::instance()->getItemStarting())
		{
			info_data = "Attack Speed: " + std::to_string(((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponAttackSpeed());
			unsigned playerAttackSpeed = ((PlayerBase::instance()->getCurrentHeldItem() != nullptr) ? ((ItemWeapon*)PlayerBase::instance()->getCurrentHeldItem())->getWeaponAttackSpeed() : 1);

			if (((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponAttackSpeed() >  playerAttackSpeed)
				info_data += " ^ ";
			else if (((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponAttackSpeed() <  playerAttackSpeed)
				info_data += " v ";
			else
				info_data += " == ";

			info_data += '(' + std::to_string(playerAttackSpeed) + ')';
		}
		break;
	case 3:
		if (getItemDrop() <= DataBase::instance()->getItemStarting())
		{
			info_data = "Durability: " + std::to_string((((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponDurability()));
			unsigned playerDurability = ((PlayerBase::instance()->getCurrentHeldItem() != nullptr) ? ((ItemWeapon*)PlayerBase::instance()->getCurrentHeldItem())->getWeaponDurability() : 0);

			if (((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponDurability() >  playerDurability)
				info_data += " ^ ";
			else if (((ItemWeapon*)(DataBase::instance()->getItem(getItemDrop())))->getWeaponDurability() <  playerDurability)
				info_data += " v ";
			else
				info_data += " == ";

			info_data += '(' + std::to_string(playerDurability) + ')';
		}
		break;
	default:
		break;
	}

	return info_data;
}
