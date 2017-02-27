#ifndef _DATA_BASE_H_
#define _DATA_BASE_H_

#include "ItemWeapon.h"
#include "EntityDrop.h"
#include "EntityMinion.h"
#include "EntityBoss.h"
#include "EnvironmentBase.h"


//Weapons 
#include "ItemBattleAxe.cpp"
#include "ItemGreatSword.cpp"
#include "ItemChickenGun.cpp"
#include "ItemDagger.cpp"
#include "ItemGiggsGun.cpp"
#include "ItemHammer.cpp"
#include "ItemKunai.cpp"
#include "ItemLaserGun.cpp"
#include "ItemLucille.cpp"
#include "ItemM4A4.cpp"
#include "ItemMinigun.cpp"
#include "Itemshotgun.cpp"
#include "ItemShuriken.cpp"
#include "ItemSpear.cpp"
#include "ItemSword.cpp"
#include "ItemWoodenSword.cpp"



//non weapons but still here for I dont know what reason lel
#include "ItemKiteShield.cpp"
#include "ItemRoundShield.cpp"


#include "EnvironmentAppleTree.cpp"
#include "EnvironmentChristmasTree.cpp"
#include "EnviromentStatueHalfSet.cpp"
#include "EnviromentTargetPractise.cpp"
#include "EnvironmentFence.cpp"
#include "EnvironmentGiantSwordStand.cpp"
#include "EnvironmentHammerStand.cpp"
#include "EnvironmentHouse.cpp"
#include "EnvironmentNiceLookingTree.cpp"
#include "EnvironmentNoStatue.cpp"
#include "EnvironmentOnequarterSet.cpp"
#include "EnvironmentPortal.cpp"
#include "EnvironmentRoundAss.cpp"
#include "EnvironmentStatueFullSet.cpp"
#include "EnvironmentThreeQuarterSetStatue.cpp"
#include "EnvironmentWeaponMerchant.cpp"
#include "EnvironmentKunaiStand.cpp"
#include "EnvironmentMinigunStan.cpp"
#include "EnvironmentTowerSpwanner.cpp"
#include "EnvironmentTowerStructure.cpp"
#include "EnvironmentWall.cpp"

#include "Boss_1.h"
#include "Boss_2.cpp"
#include "Boss_3.cpp"
#include "Boss_4.h"

#include "MeleeMinion_1.cpp"
#include "MeleeMinion_2.cpp"
#include "RangedMinion_1.h"
#include "RangedMinion_2.h"
#include "EntitySpawner.h"

#include "NPCGirlWithBoobs.cpp"
#include "NPCBoy.cpp"
#include "NPCScientist.cpp"
#include "NPCElephant.cpp"
#include "NPCNegan.cpp"
#include "NPCEmoKid.cpp"
#include "NPCLady.cpp"



#include <vector>
#include <map>
#include <string>
#include <time.h>

using std::vector;
using std::string;
using std::map;

class DataBase
{
private:
	static DataBase *s_instance;  //CREATE AN INSTANCE OF THE CLASS OBJECT
	DataBase()
	{
			/*COMMON,
			UNCOMMON,
			RARE,
			LEGENDARY*/

		rarity_color_[0] = Color(1, 1, 1);
		rarity_color_[1] = Color(0.137255, 0.556863, 0.419608);
		rarity_color_[2] = Color(0.35, 0.35, 0.67);
		rarity_color_[3] = Color(0.81, 0.71, 0.23);
	
	}
	~DataBase()
	{
		for (int i = 0; i < item_base_.size(); i++)
		{
			delete item_base_[i];
		}

		for (int i = 0; i < environment_data_base.size(); i++)
		{
			delete environment_data_base[i];
		}

		for (int i = 0; i < minion_data_base.size(); i++)
		{
			delete minion_data_base[i];
		}

		for (int i = 0; i < boss_data_base.size(); i++)
		{
			delete boss_data_base[i];
		}

		for (int i = 0; i < projectile_data_base.size(); i++)
		{
			delete projectile_data_base[i];
		}

		for (int i = 0; i < npc_data_base.size(); i++)
		{
			delete npc_data_base[i];
		}

		for (int i = 0; i < drop_base_.size(); i++)
		{
			for (int j = 0; j < drop_base_[i].size(); j++)
			{
				delete drop_base_[i][j];
			}
		}

		for (int i = 0; i < enviornment_base_.size(); i++)
		{
			for (int j = 0; j < enviornment_base_[i].size(); j++)
			{
				delete enviornment_base_[i][j];
			}
		}

		for (int i = 0; i < minion_base_.size(); i++)
		{
			for (int j = 0; j < minion_base_[i].size(); j++)
			{
				delete minion_base_[i][j];
			}
		}

		for (int i = 0; i < boss_base_.size(); i++)
		{
			for (int j = 0; j < boss_base_[i].size(); j++)
			{
				delete boss_base_[i][j];
			}
		}

		for (int i = 0; i < npc_base.size(); i++)
		{
			for (int j = 0; j < npc_base[i].size(); j++)
			{
				delete npc_base[i][j];
			}
		}

		for (int i = 0; i < projectile_base_.size(); i++)
		{
			for (int j = 0; j < projectile_base_[i].size(); j++)
			{
				delete projectile_base_[i][j];
			}
		}
	}

	unsigned item_starting_ = 0;  //STORES THE ITEM STARTING POSITION FOR THE ITEM DATA BASE
	map<unsigned, ItemBase *> item_base_;  //STORES ALL THE ITEMS INTO THE DATABASE
	map<unsigned, EnvironmentBase *> environment_data_base;  //STORES ALL ENVIRONMENT DATA
	map<unsigned, EntityBase *> minion_data_base;  //STORES ALL ENVIRONMENT DATA
	map<unsigned, EntityBase *> npc_data_base;  //STORES ALL ENVIRONMENT DATA
	map<unsigned, EntityBase *> boss_data_base;  //STORES ALL ENVIRONMENT DATA
	map<unsigned, EntityBase *> projectile_data_base;  //STORES ALL PROJECTILE DATA

	map<unsigned, vector<EntityDrop *>> drop_base_;  //STORES ALL ENTITY DROPS IN THE WORLD
	map<unsigned, vector<EnvironmentBase *>> enviornment_base_;  //STORES ALL BUILDINGS IN THE WORLD
	map<unsigned, vector<EntityBase *>> minion_base_;  //STORES ALL ENTITY MINION IN THE WORLD
	map<unsigned, vector<EntityBase *>> npc_base;  //STORES ALL ENTITY MINION IN THE WORLD
	map<unsigned, vector<EntityBase *>> boss_base_;  //STORES ALL ENTITY BOSS IN THE WORLD
	map<unsigned, vector<EntityBase*>> projectile_base_;  //STORES ALL PROJECTILES IN THE WORLD
	Color rarity_color_[4];

public:
	static DataBase *instance()  //GETTING THE INSTANCE OF THE CLASS
	{
		if (!s_instance)
			s_instance = new DataBase;  //CREATE A NEW INSTANCE IF THERE IS NONE AVAILABLE

		return s_instance;  //RETURNS THE INSTANCE IF THERE IS ONE AVAILABLE
	}

	void registerItems();  //REGISTER ALL ITEMS ONLY ONCE
	void registerEnvironments();  //REGISTER ALL ENVIRONMENT ONLY ONCE
	void registerEntityMinion();  //REGISTER ALL MINIONS ONLY ONCE
	void registerEntityNPC();  //REGISTER ALL NPCS ONLY ONCE
	void registerEntityBoss();  //REGISTER ALL BOSS ONLY ONCE
	void registerEntityProjectiles();  //REGISTER ALL PROJECTILES ONLY ONCE
	ItemBase* getItem(unsigned itemID);  //RETURN ITEM THROUGH ITEMID
	EnvironmentBase* getEnvironmentBase(unsigned environmentID);  //RETURN ENVIONMENT OBJ THROUGH ENVIONRMENT ID
	EntityBase* getMinionEntityBase(unsigned minionID);  //RETURN MINION ENTITY THROUGH ENTITY ID
	EntityBase* getNPCEntityBase(unsigned npcID);  //RETURN NPC ENTITY THROUGH ENTITY ID
	EntityBase* getBossEntityBase(unsigned bossID);  //RETURN BOSS THROUGH BOSS ID
	EntityBase* getProjectileEntityBase(unsigned projectileID);  //RETURN PROJECTILE THROUGH PROJECTILE ID


	ItemBase* getRandomItem(bool normal_item, bool weapon_item, unsigned rarity = 100);  //GET RANDOM ITEM THROUGH RARITY AND IF IT IS A NORMAL ITEM OR A WEAPON ITEM

	EnvironmentBase* getEnvironment(unsigned dimensionID, int positionInVector);
	EntityDrop* getEntityDrop(unsigned dimensionID, int positionInVector);
	EntityBase* getEntityMinion(unsigned dimensionID, int positionInVector);
	EntityBase* getEntityNPC(unsigned dimensionID, int positionInVector);
	EntityBase* getEntityBoss(unsigned dimensionID, int positionInVector);
	EntityBase* getEntityProjectile(unsigned dimensionID, int positionInVector);

	int sizeOfDataBase(unsigned base);
	int sizeOfDimensionObjBase(unsigned base, unsigned dimensionID);
	void setEntity(bool isBoss, bool isMinion, bool isNPC, unsigned dimensionID, EntityBase* entity);
	void setEntity(unsigned dimensionID, EntityDrop* entity);
	void setEntity(unsigned dimensionID, EntityProjectile* entity);
	void setEnvironment(unsigned dimensionID, EnvironmentBase* environment);
	void increaseItemStarting()
	{
		++item_starting_;
	}

	unsigned getItemStarting()
	{
		return item_starting_;
	}

	Color getRarityColor(unsigned rarity);

	void destroyEntityDrop(unsigned dimensionID, int positionInVector);
	void destroyEntityMinion(unsigned dimensionID, int positionInVector);
	void destroyEntityBoss(unsigned dimensionID, int positionInVector);
	void destroyEntityNPC(unsigned dimensionID, int positionInVector);
	void destroyEntityProjectile(unsigned dimensionID, int positionInVector);
	
};

#endif