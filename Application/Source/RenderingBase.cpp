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
		minion_mesh[i].push_back(MeshBuilder::GenerateOBJ(((EntityMinion*)DataBase::instance()->getMinionEntityBase(i))->getMinionName(), "OBJ//" + DataBase::instance()->getMinionEntityBase(i)->getTextureString() + ".obj"));
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(3); i++)
	{
		for (int j = 0; j < 4; j++)
			boss_mesh[i].push_back(MeshBuilder::GenerateOBJ(((EntityBoss*)DataBase::instance()->getBossEntityBase(i))->getBossName(), "OBJ//" + ((EntityBoss*)DataBase::instance()->getBossEntityBase(i))->getMultiTextureString(j) + ".obj"));
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
