#include "DetectMemoryLeak.h"
#include "StudioProject.h"
#include "GL\glew.h"

#include "shader.hpp"
#include "Mtx44.h"

#include "Application.h"

#include "Utility.h"
#include "LoadTGA.h"

#include <iostream>

#define DIMENSIONID 1

DataBase *DataBase::s_instance = nullptr;
MapBase *MapBase::s_instance = nullptr;
RenderingBase *RenderingBase::s_instance = nullptr;
ShopBase *ShopBase::s_instance = nullptr;
Vector3 Camera::position = 0;
Vector3 Camera::target = 0;
Vector3 Camera::up = 0;
Vector3 Camera::playerRight = 0;
Vector3 Camera::view = 0;

StudioProject::StudioProject()
{
}

StudioProject::~StudioProject()
{
}

void StudioProject::Init()
{
	
	DataBase::instance()->registerItems();  //RUN ONCE
	DataBase::instance()->registerEnvironments();  //RUN ONCE
	DataBase::instance()->registerEntityMinion();  //RUN ONCE
	DataBase::instance()->registerEntityBoss();  //RUN ONCE
	DataBase::instance()->registerEntityProjectiles();  //RUN ONCE
	DataBase::instance()->registerEntityNPC();  //RUN ONCE
	PlayerBase::instance()->startPlayer();  //RUN ONCE
	srand(time(nullptr));
	ShopBase::instance()->startShop();  //RUN ONCE

	//MapBase::instance()->setMapSize(DIMENSIONID, 500, 500);  //RUN ONCE FOR EACH SCENE
	//MapBase::instance()->generateMap(DIMENSIONID);  //RUN ONCE FOR EACH SCENE

	MapBase::instance()->setMapSize(DIMENSIONID, 500, 500);  //RUN ONCE FOR EACH SCENE
	MapBase::instance()->generateMap(DIMENSIONID, "Town.txt");  //RUN ONCE FOR EACH SCENE

	RenderingBase::instance()->registerAllRenderingData();  //RUN ONCE

	//RUN ONCE
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(0); i++)
	{
		string tempString = "Image//" + DataBase::instance()->getItem(i)->getTextureString() + ".tga";
		RenderingBase::instance()->getItemMesh(i)->textureID = LoadTGA(tempString.c_str());
	}

	//RUN ONCE
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(1); i++)
	{
		string tempString = "Image//" + DataBase::instance()->getEnvironmentBase(i)->getTextureString() + ".tga";
		RenderingBase::instance()->getEnviornmentMesh(i)->textureID = LoadTGA(tempString.c_str());
	}

	//RUN ONCE
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(2); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			string tempString = "Image//" + DataBase::instance()->getMinionEntityBase(i)->getTextureString(j) + ".tga";
			RenderingBase::instance()->getMinionEntityMesh(i, j)->textureID = LoadTGA(tempString.c_str());
		}
	}

	//RUN ONCE
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(3); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			string tempString = "Image//" + DataBase::instance()->getBossEntityBase(i)->getTextureString(j) + ".tga";
			RenderingBase::instance()->getBossEntityMesh(i, j)->textureID = LoadTGA(tempString.c_str());
		}
	}

	//RUN ONCE
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(4); i++)
	{		
		string tempString = "Image//" + DataBase::instance()->getProjectileEntityBase(i)->getTextureString() + ".tga";
		RenderingBase::instance()->getProjectileMesh(i)->textureID = LoadTGA(tempString.c_str());
	}

	//RUN ONCE
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(5); i++)
	{
		string tempString = "Image//" + DataBase::instance()->getNPCEntityBase(i)->getTextureString() + ".tga";
		RenderingBase::instance()->getNPCMesh(i)->textureID = LoadTGA(tempString.c_str());
	}

	//-------------------------------------------------------TESTING PURPOSES-----------------------------------------------------------
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(0); i++)
	{
		DataBase::instance()->setEntity(1, new EntityDrop(i, Vector3(1 + i * 20, 0, 50), Application::elapsed_timer_));
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(0); i++)
	{
		DataBase::instance()->setEntity(1, new EntityDrop(i, Vector3(1 + i * 20, 0, 80), Application::elapsed_timer_));
	}

	DataBase::instance()->setEntity(true, false, false, 1, new Boss_1(Vector3(10 + 0 * 20, 0, 10), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(true, false, false, 1, new Boss_2(Vector3(10 + 5 * 20, 0, 10), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(true, false, false, 1, new Boss_3(Vector3(10 + 10 * 20, 0, 10), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(true, false, false, 1, new Boss_4(Vector3(10 + 15 * 20, 0, 10), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));

	DataBase::instance()->setEntity(false, true, false, 1, new EntitySpawner(Vector3(10 + 0 * 20, 0, 20), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	
	DataBase::instance()->setEntity(false, false, true, 1, new NPCGirlwithBoobs(Vector3(10 + 0 * 20, 0, 40), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(false, false, true, 1, new NPCBoy(Vector3(10 + 5 * 20, 0, 40), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(false, false, true, 1, new NPCScientist(Vector3(1 + 10 * 20, 0, 40), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(false, false, true, 1, new NPCElephant(Vector3(10 + 15 * 20, 0, 40), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(false, false, true, 1, new NPCNegan(Vector3(10 + 20 * 10, 0, 40), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(false, false, true, 1, new NPCEmoKid(Vector3(1 + (10 * 20), 0, 118), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));
	DataBase::instance()->setEntity(false, false, true, 1, new NPCLady(Vector3(10 + 20 * 20, 0, 40), Vector3(0, 1, 0), Vector3(1, 0, 0), Vector3(10, 0, 10).Cross(Vector3(0, 1, 0)), Vector3(1, 0, 0)));

	//--------------------------------------------------------^REMOVE ONCE DONE^--------------------------------------------------------

	// Set background color to dark blue
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//Enable depth buffer and depth testing
	glEnable(GL_DEPTH_TEST);

	//Enable back face culling
	glEnable(GL_CULL_FACE);

	//Default to fill mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Load vertex and fragment shaders
	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");

	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");

	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

	//================================================================================================
	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");
	//================================================================================================

	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");

	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");

	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	// Use our shader
	glUseProgram(m_programID);
	// Get a handle for our "MVP" uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

	//variable to rotate geometry

	//meshes------------------------------------------------------------------------------------------
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference", 1000, 1000, 1000);

	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1, 1, 1), 24, 13, 1);

	//..........................................................................................


	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_FRONT]->textureID = LoadTGA("Image//deception_pass_ft.tga");

	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BACK]->textureID = LoadTGA("Image//deception_pass_bk.tga");


	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_LEFT]->textureID = LoadTGA("Image//deception_pass_lf.tga");

	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//deception_pass_rt.tga");

	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//deception_pass_dn.tga");

	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_TOP]->textureID = LoadTGA("Image//deception_pass_up.tga");

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");

	meshList[GEO_HUD] = MeshBuilder::GenerateOBJ("hud", "OBJ//hud.obj");
	meshList[GEO_HUD]->textureID = LoadTGA("Image//hud.tga");

	meshList[GEO_HEALTH] = MeshBuilder::GenerateOBJ("health", "OBJ//health.obj");
	meshList[GEO_HEALTH]->textureID = LoadTGA("Image//health.tga");

	meshList[GEO_EXP] = MeshBuilder::GenerateOBJ("exp", "OBJ//exp.obj");
	meshList[GEO_EXP]->textureID = LoadTGA("Image//exp.tga");

	meshList[GEO_ATTRIBUTES] = MeshBuilder::GenerateOBJ("", "OBJ//attribute.obj");
	meshList[GEO_ATTRIBUTES]->textureID = LoadTGA("Image//attribute.tga");

	meshList[GEO_INVENTORY] = MeshBuilder::GenerateOBJ("", "OBJ//inventory.obj");
	meshList[GEO_INVENTORY]->textureID = LoadTGA("Image//inventoryui.tga");

	meshList[GEO_MOUSE] = MeshBuilder::GenerateOBJ("", "OBJ//play1.obj");
	meshList[GEO_MOUSE]->textureID = LoadTGA("Image//gay_mouse.tga");

	meshList[GEO_SHOP] = MeshBuilder::GenerateOBJ("", "OBJ//shop.obj");
	meshList[GEO_SHOP]->textureID = LoadTGA("Image//shopui.tga");

	meshList[GEO_AIM] = MeshBuilder::GenerateOBJ("", "OBJ//Crosshair.obj");
	meshList[GEO_AIM]->textureID = LoadTGA("Image//Crosshair.tga");

	//------------------------------------------------------------------------------------------
	//NPC for this scene only
	//Its gonna be funny seeing all of dem walk huehuehue
	//Just Kidding,you got pranked there aint no time for hard codings 
	//-------------------------------------------------------------------------------------------
	//light
	light[0].type = Light::LIGHT_DIRECTIONAL;
	light[0].LightPosition.Set(0, 1, 0);
	light[0].color.Set(1, 1, 1);
	light[0].power = 1;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(45));
	light[0].cosInner = cos(Math::DegreeToRadian(30));
	light[0].exponent = 3.f;
	light[0].spotDirection.Set(0.f, 1.f, 0.f);

	// Make sure you pass uniform parameters after glUseProgram()

	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

	//=============================================================================
	//light
	light[1].type = Light::LIGHT_POINT;
	light[1].LightPosition.Set(1000, 1000, 1000);
	light[1].color.Set(1, 1, 1);
	light[1].power = 1;
	light[1].kC = 1.f;
	light[1].kL = 0.01f;
	light[1].kQ = 0.001f;
	light[1].cosCutoff = cos(Math::DegreeToRadian(45));
	light[1].cosInner = cos(Math::DegreeToRadian(30));
	light[1].exponent = 3.f;
	light[1].spotDirection.Set(0.f, 1.f, 0.f);

	// Make sure you pass uniform parameters after glUseProgram()
	glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &light[1].color.r);
	glUniform1f(m_parameters[U_LIGHT1_POWER], light[1].power);
	glUniform1f(m_parameters[U_LIGHT1_KC], light[1].kC);
	glUniform1f(m_parameters[U_LIGHT1_KL], light[1].kL);
	glUniform1f(m_parameters[U_LIGHT1_KQ], light[1].kQ);
	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], light[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT1_COSINNER], light[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], light[1].exponent);
	//=============================================================================

	glUniform1i(m_parameters[U_NUMLIGHTS], 2);

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 5000.f);
	projectionStack.LoadMatrix(projection);
}

void StudioProject::Update(double dt)
{
	if (PlayerBase::instance()->getDimension() != DIMENSIONID)
		PlayerBase::instance()->setPlayerDimension(DIMENSIONID);

	SceneManager::getSceneManger()->getmycursor();

	ShowCursor(false);

	if (!inattrib && !ininv && !inshop)
	{
			camera.Update(dt);
			mouse = false;
	}

	else if (attrib || shop || inv)
	{
			mouse = true;
	}

	SceneManager::getSceneManger()->frameRate = ((int)(1 / dt));

	Application::elapsed_timer_ += dt;

	if (PlayerBase::instance()->getPlayerState() == PlayerBase::instance()->IDLE)
	{
		if (Application::IsKeyPressed(MK_LBUTTON))
		{
			PlayerBase::instance()->setPlayerState(PlayerBase::instance()->LEFT_CLICK);
		}
	}

	PlayerBase::instance()->playerUpdate(Application::elapsed_timer_, dt);
	srand(time(nullptr));

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(0, DIMENSIONID); i++)
	{
		DataBase::instance()->getEntityDrop(DIMENSIONID, i)->updateAI(Application::elapsed_timer_, DIMENSIONID, dt);
		if (DataBase::instance()->getEntityDrop(DIMENSIONID, i)->isEntityDead())
		{
			DataBase::instance()->destroyEntityDrop(DIMENSIONID, i);
			--i;
		}
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(2, DIMENSIONID); i++)
	{
		DataBase::instance()->getEntityMinion(DIMENSIONID, i)->updateAI(Application::elapsed_timer_, DIMENSIONID, dt);
		if (DataBase::instance()->getEntityMinion(DIMENSIONID, i)->isEntityDead())
		{
			DataBase::instance()->getEntityMinion(DIMENSIONID, i)->onDeath();
			EntityDrop* drop = new EntityDrop(DataBase::instance()->getRandomItem(false, true)->getItemID(), DataBase::instance()->getEntityMinion(DIMENSIONID, i)->getPosition(), Application::elapsed_timer_);
			DataBase::instance()->setEntity(DIMENSIONID, drop);
			DataBase::instance()->destroyEntityMinion(DIMENSIONID, i);
			--i;
		}
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(3, DIMENSIONID); i++)
	{
		DataBase::instance()->getEntityBoss(DIMENSIONID, i)->updateAI(Application::elapsed_timer_, DIMENSIONID, dt);
		if (DataBase::instance()->getEntityBoss(DIMENSIONID, i)->isEntityDead())
		{
			DataBase::instance()->getEntityBoss(DIMENSIONID, i)->onDeath();
			for (int k = -1; k <= 1; k++)
			{
				for (int j = -1; j <= 1; j++)
				{
					EntityDrop* drop = new EntityDrop(DataBase::instance()->getRandomItem(false, true)->getItemID(), 
						Vector3(DataBase::instance()->getEntityBoss(DIMENSIONID, i)->getPosition().x + k,
						DataBase::instance()->getEntityBoss(DIMENSIONID, i)->getPosition().y,
						DataBase::instance()->getEntityBoss(DIMENSIONID, i)->getPosition().z + j),
						Application::elapsed_timer_);
					DataBase::instance()->setEntity(DIMENSIONID, drop);
				}
			}
			DataBase::instance()->destroyEntityBoss(DIMENSIONID, i);
			--i;
		}
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(4, DIMENSIONID); i++)
	{
		DataBase::instance()->getEntityProjectile(DIMENSIONID, i)->updateAI(Application::elapsed_timer_, DIMENSIONID, dt);
		if (DataBase::instance()->getEntityProjectile(DIMENSIONID, i)->isEntityDead())
		{
			DataBase::instance()->destroyEntityProjectile(DIMENSIONID, i);
			--i;
		}
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(5, DIMENSIONID); i++)
	{
		DataBase::instance()->getEntityNPC(DIMENSIONID, i)->updateAI(Application::elapsed_timer_, DIMENSIONID, dt);
		if (DataBase::instance()->getEntityNPC(DIMENSIONID, i)->isEntityDead())
		{
			DataBase::instance()->destroyEntityNPC(DIMENSIONID, i);
			--i;
		}
	}


	float LSPEED = 10.f;

	if (Application::IsKeyPressed('1')) //enable back face culling
		glEnable(GL_CULL_FACE);
	if (Application::IsKeyPressed('2')) //disable back face culling
		glDisable(GL_CULL_FACE);
	if (Application::IsKeyPressed('3'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	if (Application::IsKeyPressed('4'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
	
		if (Application::IsKeyPressed(VK_ESCAPE)&&!pause)
		{
			currscene = SceneManager::getSceneManger()->getCurrentScene();
			SceneManager::getSceneManger()->setNextScene(4);
			pause = true;
		}
		else
		{
			pause = false;
		}

		if (Application::IsKeyPressed(VK_F1))
		{
			SceneManager::getSceneManger()->setNextScene(2);
		}
		if (Application::IsKeyPressed(VK_F2))
		{
			SceneManager::getSceneManger()->setNextScene(3);
		}
		
	//light_controls---------------------------------------------------------------
	//if (Application::IsKeyPressed('I'))
	//{
	//	light[1].LightPosition.z -= (float)(LSPEED * dt);
	//}
	//if (Application::IsKeyPressed('K'))
	//{
	//	light[1].LightPosition.z += (float)(LSPEED * dt);
	//}
	if (Application::IsKeyPressed('J'))
		light[1].LightPosition.x -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('L'))
		light[1].LightPosition.x += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('O'))
		light[1].LightPosition.y -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('P'))
		light[1].LightPosition.y += (float)(LSPEED * dt);

	if (Application::IsKeyPressed('5'))
	{
		light[0].type = Light::LIGHT_POINT;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	}
	else if (Application::IsKeyPressed('6'))
	{
		light[0].type = Light::LIGHT_DIRECTIONAL;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	}
	else if (Application::IsKeyPressed('7'))
	{
		light[0].type = Light::LIGHT_SPOT;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	}
	
	if (timer == 0.0f)
	{
		timer = Application::elapsed_timer_;
	}

	if (Application::elapsed_timer_ > timer + .2 && PlayerBase::instance()->getPlayerState() == PlayerBase::instance()->IDLE)
	{
		if (Application::IsKeyPressed(VK_RBUTTON))
		{
			for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(5, DIMENSIONID); i++)
			{
				if (DataBase::instance()->getEntityNPC(DIMENSIONID, i)->getBoundingBox().increaseBoundry(Vector3(10, 10, 10), Vector3(10, 10, 10)).isPointInsideAABB(Camera::position, Camera::view))
				{
					dynamic_cast<EntityNPC*>(DataBase::instance()->getEntityNPC(DIMENSIONID, i))->setState(2);
				}
			}
		}

		if (Application::IsKeyPressed('Q'))
		{
			PlayerBase::instance()->moveCurrItem(false);
			timer = Application::elapsed_timer_;
		}
		else if (Application::IsKeyPressed('E'))
		{
			PlayerBase::instance()->moveCurrItem(true);
			timer = Application::elapsed_timer_;
		}

		if (Application::IsKeyPressed(VK_LEFT))
		{
			PlayerBase::instance()->moveCurrSkill(false);
			timer = Application::elapsed_timer_;
		}
		else if (Application::IsKeyPressed(VK_RIGHT))
		{
			PlayerBase::instance()->moveCurrSkill(true);
			timer = Application::elapsed_timer_;
		}

		if (Application::IsKeyPressed(VK_SPACE))
		{
			PlayerBase::instance()->useSkills(Application::elapsed_timer_);
			timer = Application::elapsed_timer_;
		}

		if (Application::IsKeyPressed('K') && !attrib)
		{
			attrib = true;
			inattrib = true;
			timer = Application::elapsed_timer_;
			PlayerBase::instance()->setPlayerState(PlayerBase::instance()->IN_UI);
		}
		
		if (Application::IsKeyPressed('I') && !inv)
		{
			inv = true;
			ininv = true;
			timer = Application::elapsed_timer_;
			PlayerBase::instance()->setPlayerState(PlayerBase::instance()->IN_UI);

		}
		
		if (Application::IsKeyPressed('L') && !shop)
		{
			shop = true;
			inshop = true;
			timer = Application::elapsed_timer_;
			PlayerBase::instance()->setPlayerState(PlayerBase::instance()->IN_UI);
			std::cout << std::to_string(PlayerBase::instance()->getPlayerState()) << std::endl;
		}
	}

	else if (Application::elapsed_timer_ > timer + .2 && PlayerBase::instance()->getPlayerState() == PlayerBase::instance()->IN_UI)
	{
		if (Application::IsKeyPressed('K') && attrib)
		{
			attrib = false;
			inattrib = false;
			timer = Application::elapsed_timer_;
			PlayerBase::instance()->setPlayerState(PlayerBase::instance()->IDLE);
		}

		if (Application::IsKeyPressed('I') && inv)
		{
			inv = false;
			ininv = false;
			timer = Application::elapsed_timer_;
			PlayerBase::instance()->setPlayerState(PlayerBase::instance()->IDLE);
		}

		if (Application::IsKeyPressed('L') && shop)
		{
			shop = false;
			inshop = false;
			timer = Application::elapsed_timer_;
			PlayerBase::instance()->setPlayerState(PlayerBase::instance()->IDLE);
		}

		if (Application::IsKeyPressed(VK_LBUTTON) && !s && attrib)
		{

			if (PlayerBase::instance()->getAttributePoint() != 0)
			{
				if (SceneManager::getSceneManger()->cx > 481 && SceneManager::getSceneManger()->cx < 538 && SceneManager::getSceneManger()->cy>138 && SceneManager::getSceneManger()->cy < 190)
				{
					PlayerBase::instance()->increaseSkillPoint(0);
				}
				if (SceneManager::getSceneManger()->cx > 481 && SceneManager::getSceneManger()->cx < 538 && SceneManager::getSceneManger()->cy>232 && SceneManager::getSceneManger()->cy < 285)
				{
					PlayerBase::instance()->increaseSkillPoint(1);
				}
				if (SceneManager::getSceneManger()->cx > 481 && SceneManager::getSceneManger()->cx < 538 && SceneManager::getSceneManger()->cy>363 && SceneManager::getSceneManger()->cy < 416)
				{
					PlayerBase::instance()->increaseSkillPoint(2);
				}
				if (SceneManager::getSceneManger()->cx > 481 && SceneManager::getSceneManger()->cx < 538 && SceneManager::getSceneManger()->cy>458 && SceneManager::getSceneManger()->cy < 511)
				{
					PlayerBase::instance()->increaseSkillPoint(3);
				}
			}
			s = true;
			timer = Application::elapsed_timer_;

		}
		else
		{
			s = false;
		}

		if (Application::IsKeyPressed(VK_LBUTTON) && !i && inv)
		{
			if (itemOne == 27)
			{
				//set itemOne to slot
				//col1 row1
				if (SceneManager::getSceneManger()->cx > 206 && SceneManager::getSceneManger()->cx < 285 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					
					itemOne = 0;
				}
				//col1 row2
				else if (SceneManager::getSceneManger()->cx > 206 && SceneManager::getSceneManger()->cx < 285 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					
					itemOne = 1;
				}
				//col1 row3
				else if (SceneManager::getSceneManger()->cx > 206 && SceneManager::getSceneManger()->cx < 285 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
		
					itemOne = 2;
				}
				//col1 row4
				else if (SceneManager::getSceneManger()->cx > 206 && SceneManager::getSceneManger()->cx < 285 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
				
					itemOne = 3;
				}


				//col2 row1
				else if (SceneManager::getSceneManger()->cx > 289 && SceneManager::getSceneManger()->cx < 364 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemOne = 4;
				}
				//col2 row2
				else if (SceneManager::getSceneManger()->cx > 289 && SceneManager::getSceneManger()->cx < 364 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemOne = 5;
				}
				//col2 row3
				else if (SceneManager::getSceneManger()->cx > 289 && SceneManager::getSceneManger()->cx < 364 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemOne = 6;
				}
				//col2 row4
				else if (SceneManager::getSceneManger()->cx > 289 && SceneManager::getSceneManger()->cx < 364 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
					itemOne = 7;
				}


				//col3 row1
				else if (SceneManager::getSceneManger()->cx > 366 && SceneManager::getSceneManger()->cx < 443 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemOne = 8;
				}
				//col3 row2
				else if (SceneManager::getSceneManger()->cx > 366 && SceneManager::getSceneManger()->cx < 443 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemOne = 9;
				}
				//col3 row3
				else if (SceneManager::getSceneManger()->cx > 366 && SceneManager::getSceneManger()->cx < 443 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemOne = 10;
				}
				//col3 row4
				else if (SceneManager::getSceneManger()->cx > 366 && SceneManager::getSceneManger()->cx < 443 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
					itemOne = 11;
				}


				//col4 row1
				else if (SceneManager::getSceneManger()->cx > 445 && SceneManager::getSceneManger()->cx < 522 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemOne = 12;
				}
				//col4 row2
				else if (SceneManager::getSceneManger()->cx > 445 && SceneManager::getSceneManger()->cx < 522 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemOne = 13;
				}
				//col4 row3
				else if (SceneManager::getSceneManger()->cx > 445 && SceneManager::getSceneManger()->cx < 522 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemOne = 14;
				}
				//col4 row4
				else if (SceneManager::getSceneManger()->cx > 445 && SceneManager::getSceneManger()->cx < 522 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy <481)
				{
					itemOne = 15;
				}


				//col5 row1
				else if (SceneManager::getSceneManger()->cx > 524 && SceneManager::getSceneManger()->cx < 599 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemOne = 16;
				}
				//col5 row2
				else if (SceneManager::getSceneManger()->cx > 524 && SceneManager::getSceneManger()->cx < 599 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemOne = 17;
				}
				//col5 row3
				else if (SceneManager::getSceneManger()->cx > 524 && SceneManager::getSceneManger()->cx < 599 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemOne = 18;
				}
				//col5 row4
				else if (SceneManager::getSceneManger()->cx > 524 && SceneManager::getSceneManger()->cx < 599 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
					itemOne = 19;
				}
			}


			else if (itemOne != 27 && itemTwo == 27)
			{
				//same for itemTwo
				//col1 row1
				if (SceneManager::getSceneManger()->cx > 206 && SceneManager::getSceneManger()->cx < 285 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemTwo = 0;
				}
				//col1 row2
				else if (SceneManager::getSceneManger()->cx > 206 && SceneManager::getSceneManger()->cx < 285 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemTwo = 1;
				}
				//col1 row3
				else if (SceneManager::getSceneManger()->cx > 206 && SceneManager::getSceneManger()->cx < 285 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemTwo = 2;
				}
				//col1 row4
				else if (SceneManager::getSceneManger()->cx > 206 && SceneManager::getSceneManger()->cx < 285 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
					itemTwo = 3;
				}


				//col2 row1
				else if (SceneManager::getSceneManger()->cx > 289 && SceneManager::getSceneManger()->cx < 364 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemTwo = 4;
				}
				//col2 row2
				else if (SceneManager::getSceneManger()->cx > 329 && SceneManager::getSceneManger()->cx < 364 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemTwo = 5;
				}
				//col2 row3
				else if (SceneManager::getSceneManger()->cx > 329 && SceneManager::getSceneManger()->cx < 364 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemTwo = 6;
				}
				//col2 row4
				else if (SceneManager::getSceneManger()->cx > 329 && SceneManager::getSceneManger()->cx < 364 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
					itemTwo = 7;
				}


				//col3 row1
				else if (SceneManager::getSceneManger()->cx > 366 && SceneManager::getSceneManger()->cx < 443 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemTwo = 8;
				}
				//col3 row2
				else if (SceneManager::getSceneManger()->cx > 366 && SceneManager::getSceneManger()->cx < 443 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemTwo = 9;
				}
				//col3 row3
				else if (SceneManager::getSceneManger()->cx > 366 && SceneManager::getSceneManger()->cx < 443 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemTwo = 10;
				}
				//col3 row4
				else if (SceneManager::getSceneManger()->cx > 366 && SceneManager::getSceneManger()->cx < 443 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
					itemTwo = 11;
				}


				//col4 row1
				else if (SceneManager::getSceneManger()->cx > 445 && SceneManager::getSceneManger()->cx < 522 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemTwo = 12;
				}
				//col4 row2
				else if (SceneManager::getSceneManger()->cx > 445 && SceneManager::getSceneManger()->cx < 522 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemTwo = 13;
				}
				//col4 row3
				else if (SceneManager::getSceneManger()->cx > 445 && SceneManager::getSceneManger()->cx < 522 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemTwo = 14;
				}
				//col4 row4
				else if (SceneManager::getSceneManger()->cx > 445 && SceneManager::getSceneManger()->cx < 522 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
					itemTwo = 15;
				}


				//col5 row1
				else if (SceneManager::getSceneManger()->cx > 524 && SceneManager::getSceneManger()->cx < 599 && SceneManager::getSceneManger()->cy>179 && SceneManager::getSceneManger()->cy < 251)
				{
					itemTwo = 16;
				}
				//col5 row2
				else if (SceneManager::getSceneManger()->cx > 524 && SceneManager::getSceneManger()->cx < 599 && SceneManager::getSceneManger()->cy>256 && SceneManager::getSceneManger()->cy < 329)
				{
					itemTwo = 17;
				}
				//col5 row3
				else if (SceneManager::getSceneManger()->cx > 524 && SceneManager::getSceneManger()->cx < 599 && SceneManager::getSceneManger()->cy>334 && SceneManager::getSceneManger()->cy < 406)
				{
					itemTwo = 18;
				}
				//col5 row4
				else if (SceneManager::getSceneManger()->cx > 524 && SceneManager::getSceneManger()->cx < 599 && SceneManager::getSceneManger()->cy>411 && SceneManager::getSceneManger()->cy < 481)
				{
					itemTwo = 19;
				}
			}
			i = true;
			timer = Application::elapsed_timer_;
		}
		else
		{
			i = false;
		}
		if (itemOne != 27 && itemTwo != 27)
		{
			PlayerBase::instance()->swapItemInInventory(itemOne, itemTwo);
			itemOne = itemTwo = 27;
		}

		if (Application::IsKeyPressed(VK_LBUTTON) && !s && shop)
		{
			if (SceneManager::getSceneManger()->cx > 694 && SceneManager::getSceneManger()->cx < 738)
			{
				if (SceneManager::getSceneManger()->cy > 141 && SceneManager::getSceneManger()->cy < 172)
				{
					ShopBase::instance()->buyItem(0);
				}
				else if (SceneManager::getSceneManger()->cy > 204 && SceneManager::getSceneManger()->cy < 234)
				{
					ShopBase::instance()->buyItem(1);
				}
				else if (SceneManager::getSceneManger()->cy > 267 && SceneManager::getSceneManger()->cy < 298)
				{
					ShopBase::instance()->buyItem(2);
				}
				else if (SceneManager::getSceneManger()->cy > 331 && SceneManager::getSceneManger()->cy < 361)
				{
					ShopBase::instance()->buyItem(3);
				}
				else if (SceneManager::getSceneManger()->cy > 396 && SceneManager::getSceneManger()->cy < 427)
				{
					ShopBase::instance()->buyItem(4);
				}
				else if (SceneManager::getSceneManger()->cy > 458 && SceneManager::getSceneManger()->cy < 489)
				{
					ShopBase::instance()->buyItem(5);
				}
			}
			s = true;
			timer = Application::elapsed_timer_;
		}
		else 
		{
			s = false;
		}
	}

	if (Application::IsKeyPressed(VK_LSHIFT))
	{
		PlayerBase::instance()->setPlayerState(PlayerBase::instance()->SPRINTING);
	}
	else if (PlayerBase::instance()->getPlayerState() == PlayerBase::instance()->SPRINTING)
	{
		PlayerBase::instance()->setPlayerState(PlayerBase::instance()->IDLE);
	}

	if (SceneManager::getSceneManger()->cx > 447 && SceneManager::getSceneManger()->cx < 738)
	{
		if (SceneManager::getSceneManger()->cy > 141 && SceneManager::getSceneManger()->cy < 172)
		{
			itemhover = 0;
		}
		else if (SceneManager::getSceneManger()->cy > 204 && SceneManager::getSceneManger()->cy < 234)
		{
			itemhover = 1;
		}
		else if (SceneManager::getSceneManger()->cy > 267 && SceneManager::getSceneManger()->cy < 298)
		{
			itemhover = 2;
		}
		else if (SceneManager::getSceneManger()->cy > 331 && SceneManager::getSceneManger()->cy < 361)
		{
			itemhover = 3;
		}
		else if (SceneManager::getSceneManger()->cy > 396 && SceneManager::getSceneManger()->cy < 427)
		{
			itemhover = 4;
		}
		else if (SceneManager::getSceneManger()->cy > 458 && SceneManager::getSceneManger()->cy < 489)
		{
			itemhover = 5;
		}
	}
	if ((PlayerBase::instance()->getPlayerHealth()) <= 0)
	{
		PlayerBase::instance()->deaded();
		SceneManager::getSceneManger()->setNextScene(5);
	}
}

void StudioProject::Render()
{
	// Render VBO here
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Mtx44 MVP;


	viewStack.LoadIdentity();

	viewStack.LookAt(camera.position.x, camera.position.y,
		camera.position.z, camera.target.x, camera.target.y,
		camera.target.z, camera.up.x, camera.up.y, camera.up.z);


	Position lightPosition_cameraspace = viewStack.Top() * light[0].LightPosition;
	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	//===================================================================================
	Position lightPosition_cameraspace2 = viewStack.Top() * light[1].LightPosition;//test
	glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace2.x);//test
	//===================================================================================

	modelStack.LoadIdentity();
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	//=====================================================================================
	if (light[1].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(light[1].LightPosition.x, light[1].LightPosition.y, light[1].LightPosition.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
	}
	if (light[1].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[1].LightPosition;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[1].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	if (light[1].type == Light::LIGHT_POINT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[1].LightPosition;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
	}
	//=======================================================================================

	if (light[0].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(light[0].LightPosition.x, light[0].LightPosition.y, light[0].LightPosition.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
	}
	if (light[0].type == Light::LIGHT_SPOT)//else if
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[0].LightPosition;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	if (light[0].type == Light::LIGHT_POINT)//else
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[0].LightPosition;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	}

	RenderMesh(meshList[GEO_AXES], false);

	RenderSkybox();

	//=================================================================================================
	modelStack.PushMatrix();
	modelStack.Translate(light[0].LightPosition.x, light[0].LightPosition.y, light[0].LightPosition.z);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(light[1].LightPosition.x, light[1].LightPosition.y, light[1].LightPosition.z);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();
	//===================================================================================================

	//--------------------------------------------------ENVIRONMENT--------------------------------------------------
	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(1, DIMENSIONID); i++)
	{
		modelStack.PushMatrix();
		modelStack.Translate(DataBase::instance()->getEnvironment(DIMENSIONID, i)->getPosition().x,
			DataBase::instance()->getEnvironment(DIMENSIONID, i)->getPosition().y,
			DataBase::instance()->getEnvironment(DIMENSIONID, i)->getPosition().z);

		RenderMesh(RenderingBase::instance()->getEnviornmentMesh(DataBase::instance()->getEnvironment(DIMENSIONID, i)->getEnvironmentID()), true);
		modelStack.PopMatrix();
	}

	//--------------------------------------------------MINION--------------------------------------------------
	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(2, DIMENSIONID); i++)
	{
		modelStack.PushMatrix();
		modelStack.Translate(DataBase::instance()->getEntityMinion(DIMENSIONID, i)->getPosition().x,
			DataBase::instance()->getEntityMinion(DIMENSIONID, i)->getPosition().y,
			DataBase::instance()->getEntityMinion(DIMENSIONID, i)->getPosition().z);
		modelStack.Rotate(DataBase::instance()->getEntityMinion(DIMENSIONID, i)->getRotationY(), 0, 1, 0);

		modelStack.PushMatrix();
		if (RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 1) !=
			RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 0))
		{
			modelStack.Translate(.1, 1.9, 0);
			RenderMesh(RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 1), true);
		}
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		if (RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 1) !=
			RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 0))
		{
			modelStack.Translate(-.1, 1.9, 0);
			modelStack.Rotate(-(dynamic_cast<EntityMinion*>((DataBase::instance()->getEntityMinion(DIMENSIONID, i))))->getMinionrotateArm(), 1, 0, 0);
			RenderMesh(RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 2), true);
		}
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		if (RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 1) !=
			RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 0))
		{
			modelStack.Rotate(-(dynamic_cast<EntityMinion*>((DataBase::instance()->getEntityMinion(DIMENSIONID, i))))->getMinionrotateleftLeg(), 1, 0, 0);
			RenderMesh(RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 3), true);
		}
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		if (RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 1) !=
			RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 0))
		{
			modelStack.Rotate((dynamic_cast<EntityMinion*>((DataBase::instance()->getEntityMinion(DIMENSIONID, i))))->getMinionrotaterightLeg(), 1, 0, 0);
			RenderMesh(RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 4), true);
		}
		modelStack.PopMatrix();

		RenderMesh(RenderingBase::instance()->getMinionEntityMesh((dynamic_cast<EntityMinion*>(DataBase::instance()->getEntityMinion(DIMENSIONID, i)))->getMinionID(), 0), true);
		modelStack.PopMatrix();
	}

	//--------------------------------------------------BOSS--------------------------------------------------
	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(3, DIMENSIONID); i++)
	{
		if (!((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->isInvisible())
		{
			modelStack.PushMatrix();
			modelStack.Translate(DataBase::instance()->getEntityBoss(DIMENSIONID, i)->getPosition().x,
				DataBase::instance()->getEntityBoss(DIMENSIONID, i)->getPosition().y + ((((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getBossID() == 3) ? 0 : 2),
				DataBase::instance()->getEntityBoss(DIMENSIONID, i)->getPosition().z);

			modelStack.Rotate(DataBase::instance()->getEntityBoss(DIMENSIONID, i)->getRotationY(), 0, 1, 0);

			modelStack.PushMatrix();
			modelStack.Translate(.1, 5, 0);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getspin(), 0, 1, 0);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getrotaterightArmZ(), 0, 0, 1);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getrotaterightArmY(), 0, 1, 0);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getrotaterightArmX(), 1, 0, 0);
			RenderMesh(RenderingBase::instance()->getBossEntityMesh((dynamic_cast<EntityBoss*>(DataBase::instance()->getEntityBoss(DIMENSIONID, i)))->getBossID(), 1), true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(.1, 5, 0);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getspin(), 0, 1, 0);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getrotateleftArmZ(), 0, 0, 1);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getrotateleftArmY(), 0, 1, 0);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getrotateleftArmX(), 1, 0, 0);
			RenderMesh(RenderingBase::instance()->getBossEntityMesh((dynamic_cast<EntityBoss*>(DataBase::instance()->getEntityBoss(DIMENSIONID, i)))->getBossID(), 2), true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getspin(), 0, 1, 0);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getrotaterightLeg(), 1, 0, 0);
			RenderMesh(RenderingBase::instance()->getBossEntityMesh((dynamic_cast<EntityBoss*>(DataBase::instance()->getEntityBoss(DIMENSIONID, i)))->getBossID(), 3), true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getspin(), 0, 1, 0);
			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getrotateleftLeg(), 1, 0, 0);
			RenderMesh(RenderingBase::instance()->getBossEntityMesh((dynamic_cast<EntityBoss*>(DataBase::instance()->getEntityBoss(DIMENSIONID, i)))->getBossID(), 4), true);
			modelStack.PopMatrix();

			modelStack.Rotate(((EntityBoss*)DataBase::instance()->getEntityBoss(DIMENSIONID, i))->getspin(), 0, 1, 0);
			RenderMesh(RenderingBase::instance()->getBossEntityMesh((dynamic_cast<EntityBoss*>(DataBase::instance()->getEntityBoss(DIMENSIONID, i)))->getBossID(), 0), true);
			modelStack.PopMatrix();
		}
	}

	//--------------------------------------------------PROJECTILE--------------------------------------------------
	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(4, DIMENSIONID); i++)
	{
		modelStack.PushMatrix();
		modelStack.Translate(DataBase::instance()->getEntityProjectile(DIMENSIONID, i)->getPosition().x,
			DataBase::instance()->getEntityProjectile(DIMENSIONID, i)->getPosition().y,
			DataBase::instance()->getEntityProjectile(DIMENSIONID, i)->getPosition().z);
		modelStack.Rotate(Application::elapsed_timer_ * 50, 1, 1, 1);
		RenderMesh(RenderingBase::instance()->getProjectileMesh((dynamic_cast<EntityProjectile*>(DataBase::instance()->getEntityProjectile(DIMENSIONID, i)))->getProjectileID()), false);
		modelStack.PopMatrix();
	}

	//--------------------------------------------------NPC--------------------------------------------------
	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(5, DIMENSIONID); i++)
	{
		modelStack.PushMatrix();
		modelStack.Translate(DataBase::instance()->getEntityNPC(DIMENSIONID, i)->getPosition().x,
			DataBase::instance()->getEntityNPC(DIMENSIONID, i)->getPosition().y,
			DataBase::instance()->getEntityNPC(DIMENSIONID, i)->getPosition().z);
		modelStack.Rotate(DataBase::instance()->getEntityNPC(DIMENSIONID, i)->getRotationY(), 0, 1, 0);
		RenderMesh(RenderingBase::instance()->getNPCMesh((dynamic_cast<EntityNPC*>(DataBase::instance()->getEntityNPC(DIMENSIONID, i)))->getNPCID()), false);
		modelStack.PopMatrix();
	}

	//--------------------------------------------------DROPS--------------------------------------------------
	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(0, DIMENSIONID); i++)
	{
		Color tempColor;
		modelStack.PushMatrix();
		modelStack.Translate(DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getPosition().x,
			DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getPosition().y,
			DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getPosition().z);

		AABB playerItemDetectionRange;
		playerItemDetectionRange.setBoundry(Vector3(-12, -3, -12), Vector3(12, 3, 12));

		modelStack.Rotate(DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getRotationY(), 0, 1, 0);
		RenderMesh(RenderingBase::instance()->getItemMesh(DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getItemDrop()), true);

		if (DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getBoundingBox().isAABBInsideAABB(playerItemDetectionRange.getBoundryAtCoord(camera.position)))
		{
			for (int j = 0; j < 4; j++)
			{
				modelStack.PushMatrix();
				modelStack.Translate(0, 4 - j, 0);

				if (camera.getRotationY() != 0)
					modelStack.Rotate((camera.getRotationY() + 750) - DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getRotationY(), 0, 1, 0);

				if (j != 0)
				{
					modelStack.Scale(.25, .25, .25);
					tempColor = Color(1, 1, 1);
				}
				else
				{
					modelStack.Scale(.4, .4, .4);
					tempColor = DataBase::instance()->getRarityColor(DataBase::instance()->getItem(DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getItemDrop())->getRarity());
				}
				RenderText(meshList[GEO_TEXT], DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getDropInfo(j), tempColor);
				modelStack.PopMatrix();
			}
		}
		modelStack.PopMatrix();
	}

	//--------------------------------------------------HELD ITEMS--------------------------------------------------
	if (PlayerBase::instance()->getCurrentHeldItem() != nullptr)
	{
		modelStack.PushMatrix();
		modelStack.Translate(camera.target.x, camera.position.y - 1, camera.target.z);
		modelStack.Rotate(camera.getRotationY() - 155, 0, 1, 0);
		modelStack.Rotate(-camera.getRotationZ(), 1, 0, 0);
		modelStack.Scale(.5, .5, .5);

		modelStack.PushMatrix();
		modelStack.Rotate(PlayerBase::instance()->getRotationX(), 1, 0, 0);
		RenderMesh(RenderingBase::instance()->getItemMesh(PlayerBase::instance()->getCurrentHeldItem()->getItemID()), true);
		modelStack.PopMatrix();

		modelStack.PopMatrix();
	}

	//--------------------------------------------------FPS--------------------------------------------------
	RenderTextOnScreen(meshList[GEO_TEXT], "FPS: " + std::to_string(SceneManager::getSceneManger()->frameRate), Color(0, 1, 0), 1.8, 1, 32);

	//--------------------------------------------------MAIN INVENTORY(4 SLOTS)--------------------------------------------------
	for (int i = 0; i < 4; i++)
	{
		if (PlayerBase::instance()->getItemFromInventory(i) != nullptr)
			RenderTextOnScreen(meshList[GEO_TEXT], 
			((PlayerBase::instance()->getCurrentItemSlot() == i) ? "> " : "") + PlayerBase::instance()->getItemFromInventory(i)->getItemName(), 
			DataBase::instance()->getRarityColor(PlayerBase::instance()->getItemFromInventory(i)->getRarity()), 1.8, 1, 5 - i);
		else
			RenderTextOnScreen(meshList[GEO_TEXT], "-", Color(1, 1, 1), 1.8, 1, 5 - i);
	}

	//--------------------------------------------------HEALTH & LEVEL--------------------------------------------------
	modelStack.PushMatrix();
	string healthBar = "";
	RenderMeshOnScreen(meshList[GEO_HUD], 35, 8, 20, 20, 90);

	RenderMeshOnScreen(meshList[GEO_HEALTH], 34.71, 8, ((float)((float)PlayerBase::instance()->getPlayerHealth() / 100.) * 20.), 20, 90);
	RenderMeshOnScreen(meshList[GEO_EXP], 34.71, 8, ((float)((float)PlayerBase::instance()->getPlayerExperience() / (float)PlayerBase::instance()->getPlayerLevelCap()) * 20.), 
		20, 90);


	RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(PlayerBase::instance()->getPlayerLevel()), Color(1, 1, 0), 2, 21.5, 1.85);
	RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(PlayerBase::instance()->getPlayerHealth()), Color(1, 1, 0), 1.8, 23.2, 3.6);
		
	modelStack.PopMatrix();

	//--------------------------------------------------SPEECH--------------------------------------------------
	modelStack.PushMatrix();
	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(5, DIMENSIONID); i++)
	{
		if ((dynamic_cast<EntityNPC*>(DataBase::instance()->getEntityNPC(DIMENSIONID, i)))->isInteracting())
		{
			RenderTextOnScreen(meshList[GEO_TEXT], (dynamic_cast<EntityNPC*>(DataBase::instance()->getEntityNPC(DIMENSIONID, i)))->getInteractionString(), 
				Color(1, 1, 0), 1.8, 20, 10);
		}
	}
	modelStack.PopMatrix();

	//--------------------------------------------------POSITION--------------------------------------------------
	RenderTextOnScreen(meshList[GEO_TEXT], "X:  " + std::to_string((int)camera.position.x), Color(1, 0, 0), 1.8, 1, 30);
	RenderTextOnScreen(meshList[GEO_TEXT], "Y:  " + std::to_string((int)camera.position.y), Color(0, 1, 0), 1.8, 1, 28);
	RenderTextOnScreen(meshList[GEO_TEXT], "Z:  " + std::to_string((int)camera.position.z), Color(0, 0, 1), 1.8, 1, 26);

	//--------------------------------------------------SKILLS--------------------------------------------------
		RenderTextOnScreen(meshList[GEO_TEXT], "Skill Active ", Color(0, 1, 1), 1.8, 32, 32);

		if (PlayerBase::instance()->getCurrentSkillPoint(PlayerBase::instance()->getCurrentEquippedSkill()) > 0
			&& PlayerBase::instance()->getCurrentSkillCoolDown(PlayerBase::instance()->getCurrentEquippedSkill()) <= 0)
		{
			RenderTextOnScreen(meshList[GEO_TEXT], "SPACE : " + PlayerBase::instance()->getSkillName(PlayerBase::instance()->getCurrentEquippedSkill()), Color(0, 1, 0), 1.8,28, 31);
		}
		else
		{
			RenderTextOnScreen(meshList[GEO_TEXT], "SPACE : " + PlayerBase::instance()->getSkillName(PlayerBase::instance()->getCurrentEquippedSkill()), Color(.4, .4, .4), 1.8, 28, 31);
		}

	//-----------------------------------------------------ATTRIBUTE-----------------------------------------------------

	if (attrib)
	{
		RenderMeshOnScreen(meshList[GEO_ATTRIBUTES], 40, 27.5, 40, 40, 90); 

		RenderTextOnScreen(meshList[GEO_TEXT], "Attribute Points: " + std::to_string(PlayerBase::instance()->getAttributePoint()), Color(1, 1, 1), 1.8, 15, 27);
		RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(PlayerBase::instance()->getCurrentSkillPoint(0)), Color(1, 1, 1), 1.8, 24,24.4 );
		RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(PlayerBase::instance()->getCurrentSkillPoint(1)), Color(1, 1, 1), 1.8, 24, 19.1);
		RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(PlayerBase::instance()->getCurrentSkillPoint(2)), Color(1, 1, 1), 1.8, 24, 12);
		RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(PlayerBase::instance()->getCurrentSkillPoint(3)), Color(1, 1, 1), 1.8, 24, 6.7);
	}

	//-----------------------------------------------------SHOP-----------------------------------------------------
	if (shop)
	{
		Color tempColor;
		string priceTag;
		RenderMeshOnScreen(meshList[GEO_SHOP], 40, 27.5, 40, 40, 90);

		RenderTextOnScreen(meshList[GEO_TEXT], "Currency: " + std::to_string(PlayerBase::instance()->getPlayerCurrency()), Color(1, .5, 0), 1.8, 26, 5);

		for (int i = 0; i < ShopBase::instance()->getShopItemSize(); i++)
		{
			if (ShopBase::instance()->getItemInShop(i) != nullptr)
			{
				tempColor = DataBase::instance()->getRarityColor(DataBase::instance()->getItem(ShopBase::instance()->getItemInShop(i)->getItemID())->getRarity());
				RenderTextOnScreen(meshList[GEO_TEXT], ShopBase::instance()->getItemInShop(i)->getItemName(), tempColor, 1.8, 27, 24.6 - (3.565 * i));
				priceTag = "[" + std::to_string(dynamic_cast<ItemWeapon*>(ShopBase::instance()->getItemInShop(i))->getPriceOfWeapon()) + "]";
				RenderTextOnScreen(meshList[GEO_TEXT], priceTag, Color(1, .5, 0), 1.8, 40 - priceTag.size(), 24.6 - (3.565 * i));
			}
		}

		if (ShopBase::instance()->getItemInShop(itemhover) != nullptr)
		{
			RenderMeshOnScreen(RenderingBase::instance()->getItemMesh(ShopBase::instance()->getItemInShop(itemhover)->getItemID()),
				28, 33, 3, 3, 217);

			tempColor = DataBase::instance()->getRarityColor(DataBase::instance()->getItem(ShopBase::instance()->getItemInShop(itemhover)->getItemID())->getRarity());
			RenderTextOnScreen(meshList[GEO_TEXT], ShopBase::instance()->getItemInShop(itemhover)->getItemName(), tempColor, 1.8, 8, 23.5);

			RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(dynamic_cast<ItemWeapon*>(ShopBase::instance()->getItemInShop(itemhover))->getWeaponDamage()), Color(1, 1, 1), 1.8, 13, 9.8);
			RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(dynamic_cast<ItemWeapon*>(ShopBase::instance()->getItemInShop(itemhover))->getWeaponDurability()), Color(1, 1, 1), 1.8, 13, 8.2);
			RenderTextOnScreen(meshList[GEO_TEXT], std::to_string(dynamic_cast<ItemWeapon*>(ShopBase::instance()->getItemInShop(itemhover))->getWeaponAttackSpeed()), Color(1, 1, 1), 1.8, 13, 6.5);
		}
	}

	//-----------------------------------------------------INVENTORY-----------------------------------------------------
	if (inv)
	{
		RenderMeshOnScreen(meshList[GEO_INVENTORY], 40, 27.5, 40, 40, 90);

		int item = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (PlayerBase::instance()->getItemFromInventory(item) != nullptr)
				{
					RenderMeshOnScreen(RenderingBase::instance()->getItemMesh(PlayerBase::instance()->getItemFromInventory(item)->getItemID()),
						27 + (i * 8), 40 - (j * 8), 1, 1, 
						217);
				}

				item++;
			}
		}
	}
	//-----------------------------------------------------MOUSE-----------------------------------------------------
	if (mouse)
	{
		RenderMeshOnScreen(meshList[GEO_MOUSE], SceneManager::getSceneManger()->cx / 10, (-(SceneManager::getSceneManger()->cy) + SceneManager::getSceneManger()->wy) / 10, 15, 15, 90);
	}


	//----------------------------------------------------AIM--------------------------------------------------------------

	RenderMeshOnScreen(meshList[GEO_AIM], 40, 27.5, 3, 3, 90);

}


void StudioProject::RenderMesh(Mesh *mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	modelView = viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);

	if (Application::IsKeyPressed('9'))
	{

		bEnableLight = false;
	}
	if (Application::IsKeyPressed('0'))
	{
		bEnableLight = true;
	}
	if (enableLight && bEnableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}
	if (mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}
	mesh->Render();
	if (mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}

void StudioProject::RenderText(Mesh* mesh, std::string text, Color color)
{
	if (!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for (unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	glEnable(GL_DEPTH_TEST);
}

void StudioProject::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if (!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);

	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for (unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 0.8f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);

	//Add these code just before glEnable(GL_DEPTH_TEST);
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();

	glEnable(GL_DEPTH_TEST);
}

//============================================TESTING===============================================
void StudioProject::RenderUI(Mesh* mesh, Color color, float size, float x, float y, bool enableLight)
{
	if (!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);

	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Translate(x, y, 0);
	modelStack.Scale(size, size, size);

	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	modelView = viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);

	if (Application::IsKeyPressed('9'))
	{
		bEnableLight = false;
	}
	if (Application::IsKeyPressed('0'))
	{
		bEnableLight = true;
	}
	if (enableLight && bEnableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}

	if (mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}
	mesh->Render();
	if (mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void StudioProject::RenderMeshOnScreen(Mesh* mesh, float x, float y, int sizex, int sizey, int rotate)
{
	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity();
	modelStack.Translate(x, y, 0);
	modelStack.Rotate(rotate, 0, 0, 1);
	modelStack.Rotate(rotate, 1, 0, 0);
	modelStack.Rotate(rotate, 0, -1, 0);
	modelStack.Scale(sizex, sizey, sizey);
	RenderMesh(mesh, false); //UI should not have light
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}

//=================================================================================================

void StudioProject::RenderSkybox()
{
	modelStack.PushMatrix();//push ground
	modelStack.Translate(camera.position.x, 0, camera.position.z);

	modelStack.PushMatrix();//push ground
	modelStack.Translate(0, -900, 0);

	modelStack.PushMatrix();//seperate from ground
	modelStack.PushMatrix();//push top
	modelStack.Translate(0, 1995, 0);
	modelStack.Rotate(180, 0, 0, 1);
	modelStack.Scale(2000, 1, 2000);
	RenderMesh(meshList[GEO_TOP], false);
	modelStack.PopMatrix();//end top


	modelStack.PushMatrix();//push back
	modelStack.Translate(0, 997, 997);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Scale(2000, 1, 2000);
	RenderMesh(meshList[GEO_BACK], false);
	modelStack.PopMatrix();//end back

	modelStack.PushMatrix();//push front
	modelStack.Translate(0, 997, -997);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Rotate(180, 1, 0, 0);
	modelStack.Scale(2000, 1, 2000);
	RenderMesh(meshList[GEO_FRONT], false);
	modelStack.PopMatrix();//end front

	modelStack.PushMatrix();//push left
	modelStack.Translate(997, 997, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Scale(2000, 1, 2000);
	RenderMesh(meshList[GEO_LEFT], false);
	modelStack.PopMatrix();//end left

	modelStack.PushMatrix();//push right
	modelStack.Translate(-997, 997, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Rotate(90, 1, 0, 0);
	modelStack.Scale(2000, 1, 2000);
	RenderMesh(meshList[GEO_RIGHT], false);
	modelStack.PopMatrix();//end right

	modelStack.PopMatrix();//end speration
	modelStack.PopMatrix();//end ground
	modelStack.PopMatrix();//end ground

	modelStack.PushMatrix();//push ground
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(2000, 1, 2000);
	RenderMesh(meshList[GEO_BOTTOM], true);
	modelStack.PopMatrix();//end ground
}



void StudioProject::Exit()
{
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}