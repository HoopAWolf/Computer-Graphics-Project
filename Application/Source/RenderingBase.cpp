#include "RenderingBase.h"


void RenderingBase::registerAllRenderingData()
{
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(0); i++)
	{
		item_mesh[i] = MeshBuilder::GenerateOBJ(DataBase::instance()->getItem(i)->getItemName(), "OBJ//" + DataBase::instance()->getItem(i)->getTextureString() + ".obj");
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(1); i++)
	{
		environment_mesh[i] = MeshBuilder::GenerateOBJ(DataBase::instance()->getEnvironmentBase(i)->getTextureString(), "OBJ//" + DataBase::instance()->getEnvironmentBase(i)->getTextureString() + ".obj");
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(2); i++)
	{
		for (int j = 0; j < 5; j++)
			minion_mesh[i].push_back(MeshBuilder::GenerateOBJ((dynamic_cast<EntityMinion*>(DataBase::instance()->getMinionEntityBase(i)))->getMinionName(), "OBJ//" + DataBase::instance()->getMinionEntityBase(i)->getTextureString(j) + ".obj"));
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(3); i++)
	{
		for (int j = 0; j < 5; j++)
			boss_mesh[i].push_back(MeshBuilder::GenerateOBJ((dynamic_cast<EntityBoss*>(DataBase::instance()->getBossEntityBase(i)))->getBossName(), "OBJ//" + DataBase::instance()->getBossEntityBase(i)->getTextureString(j) + ".obj"));
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(4); i++)
	{
		projectile_mesh[i] = MeshBuilder::GenerateOBJ(DataBase::instance()->getProjectileEntityBase(i)->getTextureString(), "OBJ//" + DataBase::instance()->getProjectileEntityBase(i)->getTextureString() + ".obj");
	}

}

Mesh* RenderingBase::getItemMesh(unsigned itemID)
{
	return item_mesh[itemID];
}


Mesh* RenderingBase::getEnviornmentMesh(unsigned enviornmentID)
{
	return environment_mesh[enviornmentID];
}

Mesh* RenderingBase::getNPCMesh(unsigned npcID)
{
	return npc_mesh[npcID];
}

Mesh* RenderingBase::getProjectileMesh(unsigned projectileID)
{
	return projectile_mesh[projectileID];
}

Mesh* RenderingBase::getMinionEntityMesh(unsigned minionID, int positionInLoop)
{
	return minion_mesh[minionID][positionInLoop];
}

Mesh* RenderingBase::getBossEntityMesh(unsigned bossID, int positionInLoop)
{
	return boss_mesh[bossID][positionInLoop];
}
