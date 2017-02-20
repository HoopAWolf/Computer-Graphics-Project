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

float timer = 0.0f;
DataBase *DataBase::s_instance = nullptr;
MapBase *MapBase::s_instance = nullptr;
RenderingBase *RenderingBase::s_instance = nullptr;
Vector3 Camera::position = 0;
Vector3 Camera::target = 0;
Vector3 Camera::up = 0;

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
	PlayerBase::instance()->startPlayer();  //RUN ONCE

	MapBase::instance()->setMapSize(1, 20, 20);  //RUN ONCE FOR EACH SCENE
	MapBase::instance()->generateMap(1, "test.txt");  //RUN ONCE FOR EACH SCENE

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

	//-------------------------------------------------------TESTING PURPOSES-----------------------------------------------------------
	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(0); i++)
	{
		DataBase::instance()->setEntity(1, new EntityDrop(i, Vector3(1 + i * 20, 0, 50), Application::elapsed_timer_));
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDataBase(0); i++)
	{
		DataBase::instance()->setEntity(1, new EntityDrop(i, Vector3(1 + i * 20, 0, 80), Application::elapsed_timer_));
	}
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
	meshList[GEO_FRONT]->textureID = LoadTGA("Image//front.tga");

	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BACK]->textureID = LoadTGA("Image//back.tga");


	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_LEFT]->textureID = LoadTGA("Image//left.tga");

	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//right.tga");

	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//bottom.tga");

	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_TOP]->textureID = LoadTGA("Image//top.tga");

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");
	//------------------------------------------------------------------------------------------
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
	camera.Update(dt);
	ShowCursor(false);

	SceneManager::getSceneManger()->frameRate = ((int)(1 / dt));

	Application::elapsed_timer_ += dt;

	PlayerBase::instance()->playerUpdate(Application::elapsed_timer_);

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(0, DIMENSIONID); i++)
	{
		DataBase::instance()->getEntityDrop(DIMENSIONID, i)->updateAI(Application::elapsed_timer_, DIMENSIONID);
		if (DataBase::instance()->getEntityDrop(DIMENSIONID, i)->isEntityDead())
		{
			DataBase::instance()->destroyEntityDrop(DIMENSIONID, i);
			--i;
		}
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(2, DIMENSIONID); i++)
	{
		DataBase::instance()->getEntityMinion(DIMENSIONID, i)->updateAI(Application::elapsed_timer_, DIMENSIONID);
		if (DataBase::instance()->getEntityMinion(DIMENSIONID, i)->isEntityDead())
		{
			DataBase::instance()->destroyEntityMinion(DIMENSIONID, i);
			--i;
		}
	}

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(3, DIMENSIONID); i++)
	{
		DataBase::instance()->getEntityBoss(DIMENSIONID, i)->updateAI(Application::elapsed_timer_, DIMENSIONID);
		if (DataBase::instance()->getEntityBoss(DIMENSIONID, i)->isEntityDead())
		{
			DataBase::instance()->destroyEntityBoss(DIMENSIONID, i);
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
	
	if (Application::IsKeyPressed(VK_ESCAPE))
	{
		currscene = SceneManager::getSceneManger()->getCurrentScene();
		SceneManager::getSceneManger()->setNextScene(6);
	}
	//light_controls---------------------------------------------------------------
	if (Application::IsKeyPressed('I'))
	{
		light[1].LightPosition.z -= (float)(LSPEED * dt);
	}
	if (Application::IsKeyPressed('K'))
	{
		light[1].LightPosition.z += (float)(LSPEED * dt);
	}
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
	if (Application::elapsed_timer_ > timer + .2)
	{
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
	}

	if (Application::IsKeyPressed(VK_LSHIFT))
	{
		PlayerBase::instance()->setPlayerState(PlayerBase::instance()->SPRINTING);
	}
	else
	{
		PlayerBase::instance()->setPlayerState(PlayerBase::instance()->WALKING);
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
					modelStack.Rotate((camera.getRotationY() - 90) - DataBase::instance()->getEntityDrop(DIMENSIONID, i)->getRotationY(), 0, 1, 0);

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

	for (int i = 0; i < DataBase::instance()->sizeOfDimensionObjBase(1, DIMENSIONID); i++)
	{
		std::cout << DataBase::instance()->sizeOfDimensionObjBase(1, DIMENSIONID) << std::endl;
		modelStack.PushMatrix();
		modelStack.Translate(DataBase::instance()->getEnvironment(DIMENSIONID, i)->getPosition().x,
			DataBase::instance()->getEnvironment(DIMENSIONID, i)->getPosition().y,
			DataBase::instance()->getEnvironment(DIMENSIONID, i)->getPosition().z);

		std::cout << DataBase::instance()->getEnvironment(DIMENSIONID, i)->getPosition() << std::endl;

		RenderMesh(RenderingBase::instance()->getEnviornmentMesh(DataBase::instance()->getEnvironment(DIMENSIONID, i)->getEnvironmentID()), true);
		modelStack.PopMatrix();
	}

	if (PlayerBase::instance()->getCurrentHeldItem() != nullptr)
	{
		modelStack.PushMatrix();
		modelStack.Translate(camera.target.x, camera.position.y - 1, camera.target.z);
		modelStack.Rotate(camera.getRotationY() + 90, 0, 1, 0);
		modelStack.Scale(.5, .5, .5);
		RenderMesh(RenderingBase::instance()->getItemMesh(PlayerBase::instance()->getCurrentHeldItem()->getItemID()), true);

		modelStack.PopMatrix();
	}


	RenderTextOnScreen(meshList[GEO_TEXT], "FPS: " + std::to_string(SceneManager::getSceneManger()->frameRate), Color(0, 1, 0), 1.8, 1, 32);

	for (int i = 0; i < 4; i++)
	{
		if (PlayerBase::instance()->getItemFromInventory(i) != nullptr)
			RenderTextOnScreen(meshList[GEO_TEXT], 
			((PlayerBase::instance()->getCurrentItemSlot() == i) ? "> " : "") + PlayerBase::instance()->getItemFromInventory(i)->getItemName(), 
			DataBase::instance()->getRarityColor(PlayerBase::instance()->getItemFromInventory(i)->getRarity()), 1.8, 1, 5 - i);
		else
			RenderTextOnScreen(meshList[GEO_TEXT], "-", Color(1, 1, 1), 1.8, 1, 5 - i);
	}
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
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

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
//=================================================================================================

void StudioProject::RenderSkybox()
{
	modelStack.PushMatrix();//push ground
	modelStack.Translate(950, 0, 950);

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

	modelStack.Translate(0, 900, 0);
	modelStack.Scale(2000, 1, 2000);
	RenderMesh(meshList[GEO_BOTTOM], true);
	modelStack.PopMatrix();//end ground
}



void StudioProject::Exit()
{
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}