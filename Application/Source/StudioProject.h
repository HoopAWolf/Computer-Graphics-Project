#ifndef STUDIO_PROJECT_H
#define STUDIO_PROJECT_H

//Azimuth_Camera_System
#include "Camera2.h"
//FPS_Camera_System
#include "Camera3.h"
#include "SceneManager.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"
#include "DataBase.h"

#include <string>
#include <vector>
using std::vector;

class StudioProject : public Scene
{
	enum GEOMETRY_TYPE
	{
		GEO_AXES,

		//basic shapes
		GEO_QUAD,
		GEO_CUBE,
		GEO_CIRCLE,
		GEO_RING,
		GEO_HEMISPHERE,
		GEO_SPHERE,
		GEO_LIGHTBALL,
		GEO_CYLINDER,

		//skybox
		GEO_LEFT,
		GEO_RIGHT,
		GEO_TOP,
		GEO_BOTTOM,
		GEO_FRONT,
		GEO_BACK,
		GEO_TEXT,

		GEO_BOSS_1_BODY,
		GEO_BOSS_1_LEFT_ARM,
		GEO_BOSS_1_RIGHT_ARM,
		GEO_BOSS_1_LEFT_LEG,
		GEO_BOSS_1_RIGHT_LEG,
		GEO_BOSS_2_BODY,
		GEO_BOSS_2_LEFT_ARM,
		GEO_BOSS_2_RIGHT_ARM,
		GEO_BOSS_2_LEFT_LEG,
		GEO_BOSS_2_RIGHT_LEG,
		GEO_BOSS_3_BODY,
		GEO_BOSS_3_LEFT_ARM,
		GEO_BOSS_3_RIGHT_ARM,
		GEO_BOSS_3_LEFT_LEG,
		GEO_BOSS_3_RIGHT_LEG,
		GEO_BOSS_4_BODY,
		GEO_BOSS_4_LEFT_ARM,
		GEO_BOSS_4_RIGHT_ARM,
		GEO_BOSS_4_LEFT_LEG,
		GEO_BOSS_4_RIGHT_LEG,

		GEO_NOSTATUE,
		GEO_STATUE,
		GEO_HALFSTATUE,
		GEO_QUARTERSTATUE,
		GEO_THREEQUARTERSTATUE,
		GEO_BIGHOUSE,
		GEO_HOUSE,
		GEO_APPLETREE,
		GEO_CHRISTMASTREE,
		GEO_FENCE,
		GEO_GIANTSWORDSTAND,
		GEO_HAMMERSTAND,
		GEO_KUNAISTAND,
		GEO_MINIGUNSTAND,
		GEO_NICELOOKINGTREE,
		GEO_PORTAL,
		GEO_POTIONMERCHANT,
		GEO_ROUNDASS,
		GEO_TARGETPRACTISE,
		GEO_WEAPONMERCHANT,

		GEO_EMOKIDNPC,   
		GEO_ELENPC,
		GEO_SCIENTISTNPC,
	    GEO_BOYNPC, 
		GEO_GIRL,    
 		GEO_LADY,    
		GEO_NEGAN,
		GEO_ATTRIBUTES,
		GEO_SHOP,
		GEO_MOUSE,
		GEO_INVENTORY,

		NUM_GEOMETRY,
	};

	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHTENABLED,

		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		//================================================================================================
		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_TYPE,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,
		//================================================================================================

		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,

		U_TOTAL,
	};

	MS modelStack, viewStack, projectionStack;
public:
	StudioProject();
	~StudioProject();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
	int currscene;

	float rotateleftLeg = 0.0f;
	float rotaterightLeg = 0.0f;
	float rotateleftArm = 0.0f;

	bool rightlegForward = true;
	bool rightlegBackward = false;
	bool leftlegForward = false;
	bool leftlegBackward = true;
	bool walking = false;
	bool attacking = false;
	bool pause=false;

	bool attrib = false;
	bool inattrib = false;
	bool mouse = false;

	bool s=false;
	bool inv = false;
	bool ininv = false;
	bool i = false;
	bool f = false;
	bool shop = false;
	int itemOne = 27;
	int itemTwo = 27;
	bool inshop = false;
	int itemhover = 0;


	

private:

	unsigned m_vertexArrayID;
	Mesh *meshList[NUM_GEOMETRY];

	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	bool bEnableLight = true;

	Light light[1];

	void RenderMesh(Mesh *mesh, bool enableLight);
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderUI(Mesh* mesh, Color color, float size, float x, float y, bool enableLight);
	void RenderMeshOnScreen(Mesh* mesh, float x, float y, int sizex, int sizey, int rotate);
	void RenderSkybox();

	char mapArray[2000][2000];
	Camera3 camera;
};

#endif