#include "DataBase.h"
#include "GL\glew.h"

void DataBase::playSoundFromString(string sound_name)
{
	sfx_base_->play2D(("Audio/" + sound_name + ".mp3").c_str(), GL_TRUE);
}

void DataBase::registerItems()
{
	if (item_base_.size() == 0)  //CHECKING IF THE ITEM BASE SIZE IS 0, TO MAKE SURE IT ONLY REGISTER ONCE
	{
		ItemBase *temp_obj;  //TEMP OBJ TO STORE ITEM ID

		//-----------------------------------COMMON-----------------------------------
		//Shields
		//temp_obj = new ItemKiteShield;
		//item_base_[temp_obj->getItemID()] = new ItemKiteShield; //Register Weapon
		//delete temp_obj;
		//increaseItemStarting();

		//temp_obj = new ItemRoundShield;
		//item_base_[temp_obj->getItemID()] = new ItemRoundShield; //Register Weapon
		//delete temp_obj;
		//increaseItemStarting();

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

void DataBase::registerEnvironments()
{
	//0
	EnvironmentBase *temp_obj;
	temp_obj = new EnvironmentAppleTree();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentAppleTree(); //Register Environment Obj
	delete temp_obj;

	//1

	temp_obj = new EnvironmentChristmasTree();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentChristmasTree(); //Register Environment Obj
	delete temp_obj;

	//2

	temp_obj = new EnvironmentFence();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentFence(); //Register Environment Obj
	delete temp_obj;

	//3

	temp_obj = new EnvironmentGiantSwordStand();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentGiantSwordStand(); //Register Environment Obj
	delete temp_obj;


	//4
	temp_obj = new EnvironmentHammerStand();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentHammerStand(); //Register Environment Obj
	delete temp_obj;


	//5
	temp_obj = new EnvironmentHouse();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentHouse(); //Register Environment Obj
	delete temp_obj;

	//6
	temp_obj = new EnvironmentKunaiStand();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentKunaiStand(); //Register Environment Obj
	delete temp_obj;

	//7
	temp_obj = new EnvironmentNicelookingTree();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentNicelookingTree(); //Register Environment Obj
	delete temp_obj;

	//8
	temp_obj = new EnvironmentPortal();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentPortal(); //Register Environment Obj
	delete temp_obj;

	//9
	temp_obj = new EnvironmentstatueFullSet();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentstatueFullSet(); //Register Environment Obj
	delete temp_obj;


	//10
	temp_obj = new Environmentstatuehalfset();
	environment_data_base[temp_obj->getEnvironmentID()] = new Environmentstatuehalfset(); //Register Environment Obj
	delete temp_obj;

	//11
	temp_obj = new EnvironmentNoStatue();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentNoStatue(); //Register Environment Obj
	delete temp_obj;

	//12
	temp_obj = new EnvironmentOneQuarterSet();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentOneQuarterSet(); //Register Environment Obj
	delete temp_obj;

	//13
	temp_obj = new EnvironmentTargetPractise();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentTargetPractise(); //Register Environment Obj
	delete temp_obj;

	//14
	temp_obj = new EnvironmentThreeQuarterSet();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentThreeQuarterSet(); //Register Environment Obj
	delete temp_obj;

	//15
	temp_obj = new EnvironmentWeaponMerchant();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentWeaponMerchant(); //Register Environment Obj
	delete temp_obj;

	//16
	temp_obj = new EnvironmentRoundAss();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentRoundAss(); //Register Environment Obj
	delete temp_obj;


	//17
	temp_obj = new EnvironmentMinigunStan();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentMinigunStan(); //Register Environment Obj
	delete temp_obj;

	//18
	temp_obj = new EnvironmentTowerSpwanner();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentTowerSpwanner(); //Register Environment Obj
	delete temp_obj;

	//19
	temp_obj = new EnvironmentTowerStructure();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentTowerStructure(); //Register Environment Obj
	delete temp_obj;

	//20
	temp_obj = new EnvironmentWall();
	environment_data_base[temp_obj->getEnvironmentID()] = new EnvironmentWall(); //Register Environment Obj
	delete temp_obj;



}

void DataBase::registerEntityMinion()
{
	EntityBase *temp_obj;

	temp_obj = new MeleeMinion_1(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	minion_data_base[(dynamic_cast<EntityMinion*>(temp_obj))->getMinionID()] = new MeleeMinion_1(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new MeleeMinion_2(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	minion_data_base[(dynamic_cast<EntityMinion*>(temp_obj))->getMinionID()] = new MeleeMinion_2(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new RangedMinion_1(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	minion_data_base[(dynamic_cast<EntityMinion*>(temp_obj))->getMinionID()] = new RangedMinion_1(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new RangedMinion_2(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	minion_data_base[(dynamic_cast<EntityMinion*>(temp_obj))->getMinionID()] = new RangedMinion_2(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new EntitySpawner(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	minion_data_base[(dynamic_cast<EntityMinion*>(temp_obj))->getMinionID()] = new EntitySpawner(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;
}

void DataBase::registerEntityNPC()
{
	EntityBase *temp_obj;

	temp_obj = new NPCGirlwithBoobs(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	npc_data_base[(dynamic_cast<EntityNPC*>(temp_obj))->getNPCID()] = new NPCGirlwithBoobs(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new NPCBoy(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	npc_data_base[(dynamic_cast<EntityNPC*>(temp_obj))->getNPCID()] = new NPCBoy(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new NPCScientist(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	npc_data_base[(dynamic_cast<EntityNPC*>(temp_obj))->getNPCID()] = new NPCScientist(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new NPCElephant(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	npc_data_base[(dynamic_cast<EntityNPC*>(temp_obj))->getNPCID()] = new NPCElephant(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new NPCNegan(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	npc_data_base[(dynamic_cast<EntityNPC*>(temp_obj))->getNPCID()] = new NPCNegan(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new NPCEmoKid(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	npc_data_base[(dynamic_cast<EntityNPC*>(temp_obj))->getNPCID()] = new NPCEmoKid(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new NPCLady(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	npc_data_base[(dynamic_cast<EntityNPC*>(temp_obj))->getNPCID()] = new NPCLady(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new EntityPortal(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	npc_data_base[(dynamic_cast<EntityNPC*>(temp_obj))->getNPCID()] = new EntityPortal(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

}

void DataBase::registerEntityBoss()
{
	EntityBase *temp_obj;

	temp_obj = new Boss_1(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	boss_data_base[(dynamic_cast<EntityBoss*>(temp_obj))->getBossID()] = new Boss_1(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;

	temp_obj = new Boss_4(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	boss_data_base[(dynamic_cast<EntityBoss*>(temp_obj))->getBossID()] = new Boss_4(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	delete temp_obj;
}

void DataBase::registerEntityProjectiles()
{
	EntityBase *temp_obj;

	temp_obj = new EntityFireBall(Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, false);
	projectile_data_base[(dynamic_cast<EntityProjectile*>(temp_obj))->getProjectileID()] = new EntityFireBall(Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, false);
	delete temp_obj;

	temp_obj = new EntityBullet(Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, false);
	projectile_data_base[(dynamic_cast<EntityProjectile*>(temp_obj))->getProjectileID()] = new EntityBullet(Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, false);
	delete temp_obj;

	temp_obj = new EntityChickenProjectile(Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, false);
	projectile_data_base[(dynamic_cast<EntityProjectile*>(temp_obj))->getProjectileID()] = new EntityChickenProjectile(Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, false);
	delete temp_obj;
}

ItemBase* DataBase::getItem(unsigned itemID)
{
	if (itemID < item_base_.size())  //CHECK IF ITEMID IS IN THE ITEM BASE
	{
		return item_base_[itemID];  //RETURN ITEM FROM ITEM BASE VIA ITEMID
	}

	return nullptr;  //RETURN NULL IF THERE IS NO ITME
}

EnvironmentBase* DataBase::getEnvironmentBase(unsigned environmentID)
{
	if (environmentID < environment_data_base.size())  //CHECK IF ENVIORNMENTID IS IN THE ITEM BASE
	{
		return environment_data_base[environmentID];  //RETURN ENVIONMENT FROM ENVIONMENT BASE VIA ENVIORNMENTID
	}

	return nullptr;  //RETURN NULL IF THERE IS NO ITME
}

EntityBase* DataBase::getMinionEntityBase(unsigned minionID)
{
	if (minionID < minion_data_base.size())  //CHECK IF MINIONID IS IN THE MINION BASE
	{
		return minion_data_base[minionID];  //RETURN ENTITYMINION FROM MINION BASE VIA MINIONID
	}

	return nullptr;  //RETURN NULL IF THERE IS NO ITME
}

EntityBase* DataBase::getBossEntityBase(unsigned bossID)
{
	if (bossID < boss_data_base.size())  //CHECK IF BOSSID IS IN THE BOSS BASE
	{
		return boss_data_base[bossID];  //RETURN ENTITYBASE FROM BOSS BASE VIA BOSSID
	}

	return nullptr;  //RETURN NULL IF THERE IS NO ITME
}

EntityBase* DataBase::getNPCEntityBase(unsigned npcID)
{
	if (npcID < npc_data_base.size())  //CHECK IF BOSSID IS IN THE BOSS BASE
	{
		return npc_data_base[npcID];  //RETURN ENTITYBASE FROM BOSS BASE VIA BOSSID
	}

	return nullptr;  //RETURN NULL IF THERE IS NO ITME
}

EntityBase* DataBase::getProjectileEntityBase(unsigned projectileID)
{
	if (projectileID < projectile_data_base.size())  //CHECK IF BOSSID IS IN THE BOSS BASE
	{
		return projectile_data_base[projectileID];  //RETURN ENTITYBASE FROM BOSS BASE VIA BOSSID
	}

	return nullptr;  //RETURN NULL IF THERE IS NO ITME
}

//THE RARITY FOR ITEMS IS 1 = CONFIRMED DROP, 100 = ALMOST IMPOSSIBLE FOR A DROP
//THE RARITY FOR WEAPONS IS ALWAYS 100, MUST BE 100
ItemBase* DataBase::getRandomItem(bool normal_item, bool weapon_item, unsigned rarity)
{
	unsigned randNumber;

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
				randNumber = rand() % 6;

				if (randNumber < item_base_.size())
				{
					if (getItem(randNumber)->getRarity() == 0)
					{
						return getItem(randNumber);
					}
				}
			}
		}
		else if (randNumber > 50 && randNumber <= 80)
		{
			while (1)
			{
				randNumber = (rand() % 4) + 6;

				if (randNumber < item_base_.size())
				{
					if (getItem(randNumber)->getRarity() == 1)
					{
						return getItem(randNumber);
					}
				}
			}
		}
		else if (randNumber > 80 && randNumber <= 95)
		{
			while (1)
			{
				randNumber = (rand() % 3) + 10;

				if (randNumber < item_base_.size())
				{
					if (getItem(randNumber)->getRarity() == 2)
					{
						return getItem(randNumber);
					}
				}
			}
		}
		else if (randNumber > 95 && randNumber <= 100)
		{
			while (1)
			{
				randNumber = (rand() % 3) + 13;

				if (randNumber < item_base_.size())
				{
					if (getItem(randNumber)->getRarity() == 3)
					{
						return getItem(randNumber);
					}
				}
			}
		}
	}

	return getItem(1);
}

EnvironmentBase* DataBase::getEnvironment(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < enviornment_base_[dimensionID].size())
		return enviornment_base_[dimensionID][positionInVector];
	return nullptr;
}

EntityDrop* DataBase::getEntityDrop(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < drop_base_[dimensionID].size())
		return drop_base_[dimensionID][positionInVector];
	return nullptr;
}

EntityBase* DataBase::getEntityMinion(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < minion_base_[dimensionID].size())
		return minion_base_[dimensionID][positionInVector];
	return nullptr;
}

EntityBase* DataBase::getEntityNPC(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < npc_base[dimensionID].size())
		return npc_base[dimensionID][positionInVector];
	return nullptr;
}

EntityBase* DataBase::getEntityBoss(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < boss_base_[dimensionID].size())
		return boss_base_[dimensionID][positionInVector];
	return nullptr;
}

EntityBase* DataBase::getEntityProjectile(unsigned dimensionID, int positionInVector)
{
	if (positionInVector < projectile_base_[dimensionID].size())
		return projectile_base_[dimensionID][positionInVector];
	return nullptr;
}

void DataBase::setEntity(bool isBoss, bool isMinion, bool isNPC, unsigned dimensionID, EntityBase* entity)
{
	if (isBoss)
		boss_base_[dimensionID].push_back(entity);

	else if (isMinion)
		minion_base_[dimensionID].push_back(entity);

	else if (isNPC)
		npc_base[dimensionID].push_back(entity);
}

void DataBase::setEntity(unsigned dimensionID, EntityDrop* entity)
{
	drop_base_[dimensionID].push_back(entity);
}

void DataBase::setEntity(unsigned dimensionID, EntityProjectile* entity)
{
	projectile_base_[dimensionID].push_back(entity);
}

void DataBase::setEnvironment(unsigned dimensionID, EnvironmentBase* environment)
{
	enviornment_base_[dimensionID].push_back(environment);
}


//0 - ITEM BASE, 1 - ENVIRONMENT BASE, 2 - MINION BASE, 3 - BOSS BASE, 4 - PROJECTILE BASE, 5- NPC BASE
int DataBase::sizeOfDataBase(unsigned base)
{
	switch (base)
	{
	case 0:
		return item_base_.size();
	case 1:
		return environment_data_base.size();
	case 2:
		return minion_data_base.size();
	case 3:
		return boss_data_base.size();
	case 4:
		return projectile_data_base.size();
	case 5:
		return npc_data_base.size();
	default:
		return 0;
	};
}

//0 - DROP BASE, 1 - BUILDING BASE, 2 - ENTITY MINION BASE, 3 - ENTITY BOSS BASE, 4 - PROJECTILE BOSS BASE 5 - NPC BASE
int DataBase::sizeOfDimensionObjBase(unsigned base, unsigned dimensionID)
{

	switch (base)
	{
	case 0:
		return drop_base_[dimensionID].size();
	case 1:
		return enviornment_base_[dimensionID].size();
	case 2:
		return minion_base_[dimensionID].size();
	case 3:
		return boss_base_[dimensionID].size();
	case 4:
		return projectile_base_[dimensionID].size();
	case 5:
		return npc_base[dimensionID].size();
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
	delete drop_base_[dimensionID][positionInVector];
	drop_base_[dimensionID].erase(drop_base_[dimensionID].begin() + positionInVector);
}

void DataBase::destroyEntityMinion(unsigned dimensionID, int positionInVector)
{
	delete minion_base_[dimensionID][positionInVector];
	minion_base_[dimensionID].erase(minion_base_[dimensionID].begin() + positionInVector);
}

void DataBase::destroyEntityBoss(unsigned dimensionID, int positionInVector)
{
	delete boss_base_[dimensionID][positionInVector];
	boss_base_[dimensionID].erase(boss_base_[dimensionID].begin() + positionInVector);
}

void DataBase::destroyEntityProjectile(unsigned dimensionID, int positionInVector)
{
	delete projectile_base_[dimensionID][positionInVector];
	projectile_base_[dimensionID].erase(projectile_base_[dimensionID].begin() + positionInVector);
}

void DataBase::destroyEntityNPC(unsigned dimensionID, int positionInVector)
{
	delete npc_base[dimensionID][positionInVector];
	npc_base[dimensionID].erase(npc_base[dimensionID].begin() + positionInVector);
}
