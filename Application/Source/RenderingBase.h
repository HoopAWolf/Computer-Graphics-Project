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
	
	vector<Mesh*> item_mesh;
	vector<Mesh*> building_mesh;

public:
	static RenderingBase *instance()  //GETTING THE INSTANCE OF THE CLASS
	{
		if (!s_instance)
			s_instance = new RenderingBase;  //CREATE A NEW INSTANCE IF THERE IS NONE AVAILABLE

		return s_instance;  //RETURNS THE INSTANCE IF THERE IS ONE AVAILABLE
	}

	void registerAllRenderingData();
	Mesh* getItemMesh(unsigned itemID);
	Mesh* getBuildingMesh(unsigned dimension);

};

#endif