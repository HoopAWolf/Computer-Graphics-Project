#include "PlayerBase.h"

PlayerBase* PlayerBase::s_instance = 0;

void PlayerBase::startPlayer()
{
	player_health_ = 20;
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
	size_ = Vector3(2, 3, 2);

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

ItemBase* PlayerBase::getItemFromInvetory(int slot)
{
	if (inventory_data_[slot] != nullptr)
		return inventory_data_[slot];

	return nullptr;
}

ItemBase* PlayerBase::getCurrentHeldItem()
{
	if (inventory_data_[0] != nullptr)
		return inventory_data_[0];

	return nullptr;
}

unsigned PlayerBase::getPlayerDamage()
{
	return damage_;
}
unsigned PlayerBase::getPlayerAttackSpeed()
{
	return attack_speed_;
}

unsigned PlayerBase::getPlayerMovingSpeed()
{
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
	bounding.getBoundryAtCoord(Camera::position);

	return bounding;
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

void PlayerBase::increaseExperience(unsigned ammount)
{
	experience_ += ammount;
	while (experience_ > getPlayerLevelCap())
	{
		if (getPlayerExperience() >= getPlayerLevelCap())
		{
			experience_ -= level_cap_;
			level_cap_ = getPlayerLevelCap() + (getPlayerLevelCap() * (3 / 100));
			level_ += 1;	
		}
	}
}
