#include "RenderingBase.h"


void RenderingBase::registerAllRenderingData()
{
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(0); i++)
	{
		Mesh * tempMesh;

		item_mesh.push_back(tempMesh);
		item_mesh[i] = MeshBuilder::GenerateOBJ(DataBase::instance()->getItem(i)->getItemName(), "OBJ//" + DataBase::instance()->getItem(i)->getTextureString() + ".obj");

	}
}