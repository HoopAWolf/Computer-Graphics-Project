#include "PlayerBase.h"
#include "DataBase.h"

PlayerBase* PlayerBase::s_instance = 0;

void PlayerBase::startPlayer()
{
	player_health_ = 100;
	damage_ = 1;
	attack_speed_ = 0;
	moving_speed_ = 1;
	ammo_ = 300;
	currency_ = 10;
	attribute_points_ = 0;
	resistance_ = 1;
	level_ = 1;
	level_cap_ = 500;
	experience_ = 0;
	player_state_ = IDLE;
	current_held_item_ = 0;
	size_ = Vector3(2, 4, 2);
	isRecharging = false;
	current_skill_ = 0;
	health_regen_timer = 0;

	rotationX = 0;
	hit = false;

	for (int i = 0; i < 20; i++)
	{
		inventory_data_.push_back(nullptr);
	}

	for (int i = 0; i < 4; i++)
	{
		skills_[i] = Vector3(0, 0, 0);
	}

	addIntoPlayerInventory(5);
}

void PlayerBase::playerUpdate(float timer, float dt)
{

	if (player_state_ == LEFT_CLICK)
	{
		if (getCurrentHeldItem() != nullptr)
		{
			if (getCurrentHeldItem()->getItemID() <= DataBase::instance()->getItemStarting())
			{
				if ((dynamic_cast<ItemWeapon *>(getCurrentHeldItem()))->getWeaponType() == 3)
				{
					if (getPlayerAmmo() > 0 && !isRecharging)
					{
						EntityProjectile* tempObj = (dynamic_cast<ItemWeapon *>(getCurrentHeldItem()))->onItemAttackProjectile(timer, dt);
						if (tempObj != nullptr)
						{
							DataBase::instance()->setEntity(dimension_, tempObj);
							ammo_ -= (dynamic_cast<ItemWeapon *>(getCurrentHeldItem()))->getBulletCount();
							if (Camera::view.y < .5)
								Camera::target.y += (dynamic_cast<ItemWeapon *>(getCurrentHeldItem()))->getRecoil();

							if (getPlayerAmmo() <= 0)
							{
								ammo_ = 0;
								rechargingTimer = timer;
								isRecharging = true;
							}
						}
					}

					player_state_ = IDLE;
				}
				else
				{
					if (rotationX <= 80 && !hit)
					{
						rotationX += getPlayerAttackSpeed();
					}
					else
					{
						if (!hit)
						{

							for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(3, dimension_); i++)
							{
								if (DataBase::instance()->getEntityBoss(dimension_, i)->getBoundingBox().isPointInsideAABB(Camera::position, Camera::playerRight.Cross(Camera::up)))
								{
									dynamic_cast<EntityBoss*>(DataBase::instance()->getEntityBoss(dimension_, i))->
										onAttacked(getPlayerDamage());

									/*std::cout << "BOSS HEALTH LEFT: " +
									std::to_string(dynamic_cast<EntityBoss*>(DataBase::instance()->getEntityBoss(dimension_, i))->getHealth())
									<< std::endl;*/
									goto here;
								}
							}

							for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(2, dimension_); i++)
							{
								if (DataBase::instance()->getEntityMinion(dimension_, i)->getBoundingBox().isPointInsideAABB(Camera::position, Camera::playerRight.Cross(Camera::up)))
								{
									dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(dimension_, i))->
										onAttacked(getPlayerDamage());

									/*std::cout << "ENEMY HEALTH LEFT: " + 
										std::to_string(dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(dimension_, i))->getHealth()) 
										<< std::endl;*/
									break;
								}
							}

						here:

							hit = true;
						}

						rotationX -= getPlayerAttackSpeed();

						if (rotationX <= 0)
						{
							hit = false;
							player_state_ = IDLE;
						}
					}
				}
			}
		}
		else
			player_state_ = IDLE;
	}
	
	if (player_health_ < 100)
	{
		if (timer > health_regen_timer + 4)
		{
			player_health_++;
			health_regen_timer = timer;
		}
	}

	if (isRecharging == true)
	{
		if (timer > rechargingTimer + 1)
		{
			if (ammo_ >= 300)
			{
				isRecharging = false;
			}
			else
			{
				ammo_ += 30;
				rechargingTimer = timer;
			}
		}
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
					attack_speed_ = 0;
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

unsigned PlayerBase::getCurrentEquippedSkill()
{
	return current_skill_;
}

unsigned PlayerBase::getPlayerDamage()
{
	if (getCurrentHeldItem()->getItemID() <= DataBase::instance()->getItemStarting())
		return damage_ + ((ItemWeapon*)getCurrentHeldItem())->getWeaponDamage();
	return damage_;
}
float PlayerBase::getPlayerAttackSpeed()
{
	if (getCurrentHeldItem()->getItemID() <= DataBase::instance()->getItemStarting())
		return attack_speed_ + (((ItemWeapon*)getCurrentHeldItem())->getWeaponAttackSpeed());
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

int PlayerBase::getPlayerCurrency()
{
	return currency_;
}

void PlayerBase::increaseCurrency(unsigned currency)
{
	currency_ += currency;
}

void PlayerBase::decreaseCurrency(unsigned currency)
{
	if (currency > currency_)
		currency_ = 0;
	else
		currency_ -= currency;
}

void PlayerBase::playerAttacked(int damage)
{
	player_health_ -= (damage - ((resistance_ / 100) * 100));
}

AABB PlayerBase::getBoundingBox()
{
	AABB bounding;
	bounding.setBoundry(-size_, size_);

	return bounding.getBoundryAtCoord(Camera::position);
}

int PlayerBase::getPlayerAmmo()
{
	return ammo_;
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

float PlayerBase::getRotationX()
{
	return rotationX;
}

bool PlayerBase::isPlayerDead()
{
	if (getPlayerHealth() <= 0)
		return true;

	return false;
}

void PlayerBase::deaded()
{
	player_health_ = 100;
	experience_ = 0;
}

void PlayerBase::healPlayer(unsigned ammount)
{
	if (getPlayerHealth() > 0)
		player_health_ += ammount;

	if (getPlayerHealth() > 100)
		player_health_ = 100;
}

void PlayerBase::useSkills(float timer)
{
	if (skills_[current_skill_].x != 0)
	{
		switch (current_skill_)
		{
		case 0:
			if (skills_[current_skill_].y <= 0)
			{
				EntityFireBall* bullet = new EntityFireBall(Vector3(Camera::position.x, Camera::position.y, Camera::position.z), (Camera::target - Camera::position).Normalized(), damage_, timer, true);
				DataBase::instance()->setEntity(dimension_, bullet);
				skills_[current_skill_].y = timer + 10;
			}
			break;
		case 1:

			if (skills_[current_skill_].y <= 0)
			{
				healPlayer((getPlayerHealth() * ((5 + skills_[current_skill_].x) / 100)));  //PLUS 5% OF CURRENT HEALTH WITH ADDITION OF 1% EVERY SKILL POINT
				skills_[current_skill_].y = timer + 10;
			}
			break;
		case 2:

			if (skills_[current_skill_].y <= 0)
			{
				attack_speed_ = 2;
				skills_[current_skill_].z = timer + (2 + skills_[current_skill_].x);
			}

			break;
		case 3:
			if (skills_[current_skill_].y <= 0)
			{
				resistance_ = (resistance_ * 2);
				skills_[current_skill_].z = timer + (2 + skills_[current_skill_].x);
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
			if (level_ % 5 == 0)
			{
				attribute_points_++;
			}
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

void PlayerBase::swapItemInInventory(int itemOne, int itemTwo)
{
	if (inventory_data_[itemOne] != nullptr && inventory_data_[itemTwo] != nullptr)
	{
		ItemBase *tempObj = inventory_data_[itemOne];
		inventory_data_[itemOne] = inventory_data_[itemTwo];
		inventory_data_[itemTwo] = tempObj;
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

void PlayerBase::moveCurrSkill(bool forward)
{
	if (forward)
	{
		++current_skill_;
		if (current_skill_ > 3)
			current_skill_ = 0;
	}
	else
	{
		--current_skill_;
		if (current_skill_ < 0)
			current_skill_ = 3;
	}
}

void PlayerBase::increaseSkillPoint(unsigned skill_slot)
{
	skills_[skill_slot].x++;
	attribute_points_--;
}
