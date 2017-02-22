#include "PlayerBase.h"
#include "DataBase.h"

PlayerBase* PlayerBase::s_instance = 0;

void PlayerBase::startPlayer()
{
	player_health_ = 100;
	damage_ = 1;
	attack_speed_ = 1;
	moving_speed_ = 1;
	ammo_ = 20;
	attribute_points_ = 0;
	resistance_ = 1;
	level_ = 1;
	level_cap_ = 500;
	experience_ = 0;
	player_state_ = IDLE;
	current_held_item_ = 0;
	size_ = Vector3(2, 3, 2);
	current_skill_active_[0] = 0;
	current_skill_active_[1] = 1;

	for (int i = 0; i < 20; i++)
	{
		inventory_data_.push_back(nullptr);
	}

	for (int i = 0; i < 4; i++)
	{
		skills_[i] = Vector3(0, 0, 0);
	}
}

void PlayerBase::playerUpdate(float timer)
{
	if (player_state_ == LEFT_CLICK)
	{
		if (getCurrentHeldItem() != nullptr)
		{
			if (getCurrentHeldItem()->getItemID() <= DataBase::instance()->getItemStarting())
			{
				if (((ItemWeapon *)getCurrentHeldItem())->getWeaponType() == 3)
				{
					if (((ItemWeapon *)getCurrentHeldItem())->onItemAttackProjectile(timer) != nullptr)
					{
						DataBase::instance()->setEntity(dimension_, ((ItemWeapon *)getCurrentHeldItem())->onItemAttackProjectile(timer));
					}
					player_state_ = IDLE;
				}
				else
				{

					player_state_ = IDLE;
				}
			}
		}
		else
			player_state_ = IDLE;
	}

	//RESET COOLDOWN
	for (int i = 0; i < skills_.size(); i++)
	{
		if (skills_[i].z == 0)
		{
			if (timer >= skills_[i].y && skills_[i].y != 0)
				skills_[i].y = 0;
		}
		else
		{
			if (timer >= skills_[i].z && skills_[i].z != 0)
			{
				skills_[i].z = 0;
				skills_[i].y = timer + 20;

				if (i == 2)
					attack_speed_ = 1;
				else if (i == 3)
					resistance_ = 1;
			}
		}
	}
}


ItemBase* PlayerBase::getItemFromInventory(int slot)
{
	return inventory_data_[slot];
}

unsigned PlayerBase::getCurrentItemSlot()
{
	return current_held_item_;
}

ItemBase* PlayerBase::getCurrentHeldItem()
{
	return inventory_data_[current_held_item_];
}

unsigned PlayerBase::getCurrentEquippedSkill(unsigned slotNum)
{
	unsigned num = slotNum;

	if (num < 0)
		num = 0;
	else if (num > 1)
		num = 1;

	return current_skill_active_[num];
}

unsigned PlayerBase::getPlayerDamage()
{
	if (getCurrentHeldItem()->getItemID() <= DataBase::instance()->getItemStarting())
		return damage_ + ((ItemWeapon*)getCurrentHeldItem())->getWeaponDamage();
	return damage_;
}
unsigned PlayerBase::getPlayerAttackSpeed()
{
	if (getCurrentHeldItem()->getItemID() <= DataBase::instance()->getItemStarting())
		return attack_speed_ * ((ItemWeapon*)getCurrentHeldItem())->getWeaponDamage();
	return attack_speed_;
}

unsigned PlayerBase::getPlayerMovingSpeed()
{
	if (getCurrentHeldItem()->getItemID() <= DataBase::instance()->getItemStarting())
		return moving_speed_ * ((ItemWeapon*)getCurrentHeldItem())->getWeaponAttackSpeed();
	return moving_speed_;
}

unsigned PlayerBase::getPlayerResistance()
{
	return resistance_;
}

unsigned PlayerBase::getAttributePoint()
{
	return attribute_points_;
}

unsigned PlayerBase::getCurrentSkillPoint(unsigned skill_slot)
{
	return skills_[skill_slot].x;
}

unsigned PlayerBase::getCurrentSkillDamage(unsigned skill_slot)
{
	return skills_[skill_slot].z;
}

unsigned PlayerBase::getCurrentSkillCoolDown(unsigned skill_slot)
{
	return skills_[skill_slot].y;
}

int PlayerBase::getPlayerHealth()
{
	return player_health_;
}

unsigned PlayerBase::getDimension()
{
	return dimension_;
}

unsigned PlayerBase::getPlayerLevel()
{
	return level_;
}

unsigned PlayerBase::getPlayerExperience()
{
	return experience_;
}

unsigned PlayerBase::getPlayerLevelCap()
{
	return level_cap_;
}

AABB PlayerBase::getBoundingBox()
{
	AABB bounding;
	bounding.setBoundry(-size_, size_);

	return bounding.getBoundryAtCoord(Camera::position);
}

string PlayerBase::getSkillName(unsigned skillID)
{

	switch (skillID)
	{
	case 0:
		return "Fire Ball";
	case 1:
		return "Water Heal";
	case 2:
		return "Lightning Speed";
	case 3:
		return "Rock Hard";
	default:
		return "Dafug";
	}
}

bool PlayerBase::isPlayerDead()
{
	if (getPlayerHealth() <= 0)
		return true;

	return false;
}

void PlayerBase::healPlayer(unsigned ammount)
{
	if (getPlayerHealth() > 0)
		player_health_ += ammount;

	if (getPlayerHealth() > 100)
		player_health_ = 100;
}

void PlayerBase::useSkills(unsigned skill_slot, float timer)
{
	if (skills_[skill_slot].x != 0)
	{
		switch (skill_slot)
		{
		case 0:
			if (skills_[skill_slot].y <= 0)
				//FIRE STUFF
			break;
		case 1:

			if (skills_[skill_slot].y <= 0)
			{
				healPlayer((getPlayerHealth() * ((5 + skills_[skill_slot].x) / 100)));  //PLUS 5% OF CURRENT HEALTH WITH ADDITION OF 1% EVERY SKILL POINT
				skills_[skill_slot].y = timer + 10;
			}
			break;
		case 2:

			if (skills_[skill_slot].y <= 0)
			{
				attack_speed_ = (attack_speed_ * 2);
				skills_[skill_slot].z = timer + (2 + skills_[skill_slot].x);
			}

			break;
		case 3:
			if (skills_[skill_slot].y <= 0)
			{
				resistance_ = (resistance_ * 2);
				skills_[skill_slot].z = timer + (2 + skills_[skill_slot].x);
			}

			break;
		default:
			break;
		}
	}
}

void PlayerBase::setPlayerState(PLAYER_STATE player_state)
{
	player_state_ = player_state;
}

void PlayerBase::setPlayerDimension(unsigned dimensionID)
{
	dimension_ = dimensionID;
}

void PlayerBase::increaseExperience(unsigned ammount)
{
	experience_ += ammount;
	while (experience_ > getPlayerLevelCap())
	{
		if (getPlayerExperience() >= getPlayerLevelCap())
		{
			experience_ -= level_cap_;
			level_cap_ = getPlayerLevelCap() + (int)((double)getPlayerLevelCap() * (8. / 100.));
			level_ += 1;	
		}
	}
}

void PlayerBase::addIntoPlayerInventory(unsigned itemID)
{
	for (int i = 0; i < inventory_data_.size(); i++)
	{
		if (inventory_data_[i] == nullptr)
		{
			inventory_data_[i] = DataBase::instance()->getItem(itemID);
			break;
		}
	}
}

bool PlayerBase::isInventoryFull()
{
	for (int i = 0; i < inventory_data_.size(); i++)
	{
		if (inventory_data_[i] == nullptr)
		{
			return false;
		}
	}

	return true;
}

void PlayerBase::moveCurrItem(bool forward)
{
	if (forward)
	{
		++current_held_item_;
		if (current_held_item_ > 3)
			current_held_item_ = 0;
	}
	else
	{
		--current_held_item_;
		if (current_held_item_ < 0)
			current_held_item_ = 3;
	}
}
