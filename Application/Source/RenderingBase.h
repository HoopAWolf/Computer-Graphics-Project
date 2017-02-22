#ifndef _RENDERING_BASE_H_
#define _RENDERING_BASE_H_

#include "Mesh.h"
#include "DataBase.h"
#include "MeshBuilder.h"

class RenderingBase
{
private:
	static RenderingBase *s_instance;  //CREATE AN INSTANCE OF THE CLASS OBJECT
	RenderingBase(){};
	
	map<unsigned, Mesh*> item_mesh;
	map<unsigned, Mesh*> environment_mesh;
	map<unsigned, Mesh*> projectile_mesh;
	map<unsigned, Mesh*> npc_mesh;
	map<unsigned, vector<Mesh*>> minion_mesh;
	map<unsigned, vector<Mesh*>> boss_mesh;

public:
	static RenderingBase *instance()  //GETTING THE INSTANCE OF THE CLASS
	{
		if (!s_instance)
			s_instance = new RenderingBase;  //CREATE A NEW INSTANCE IF THERE IS NONE AVAILABLE

		return s_instance;  //RETURNS THE INSTANCE IF THERE IS ONE AVAILABLE
	}

	void registerAllRenderingData();
	Mesh* getItemMesh(unsigned itemID);
	Mesh* getEnviornmentMesh(unsigned environmentID);
	Mesh* getNPCMesh(unsigned npcID);
	Mesh* getProjectileMesh(unsigned projectileID);
	Mesh* getMinionEntityMesh(unsigned minionID, int positionInLoop);
	Mesh* getBossEntityMesh(unsigned bossID, int positionInLoop);

};

#endif