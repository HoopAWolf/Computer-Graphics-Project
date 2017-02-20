
#include "Application.h"

//Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>

#include "StudioProject.h"
#include "SceneManager.h"
#include "SceneBossL.h"
#include "SceneBossM.h"
#include "SceneBossH.h"
#include "SceneBossR.h"
#include "exitmenu.h"
#include "Mainmenu.h"

GLFWwindow* Application::m_window = nullptr;
SceneManager* SceneManager::s_instance = nullptr;

const unsigned char FPS = 60; // FPS of this game
const unsigned int Application::frameTime = 1000 / FPS; // time for each frame
StopWatch Application::m_timer;
float Application::elapsed_timer_ = 0;

//Define an error callback
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

//Define the key input callback
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

bool Application::IsKeyPressed(unsigned short key)
{
    return ((GetAsyncKeyState(key) & 0x8001) != 0);
}

Application::Application()
{
}

Application::~Application()
{
}

void resize_callback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h); //update opengl the new window size
}
void Application::Init()
{
	//Set the error callback
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Set the GLFW window creation hints - these are optional
	glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 


	//Create a window and create its OpenGL context
	m_window = glfwCreateWindow(800, 600, "Computer Graphics", NULL, NULL);

	//If the window couldn't be created
	if (!m_window)
	{
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetWindowSizeCallback(m_window, resize_callback);

	//This function makes the context of the specified window current on the calling thread. 
	glfwMakeContextCurrent(m_window);

	//Sets the key callback
	//glfwSetKeyCallback(m_window, key_callback);

	glewExperimental = true; // Needed for core profile
	//Initialize GLEW
	GLenum err = glewInit();

	//If GLEW hasn't initialized
	if (err != GLEW_OK) 
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		//return -1;
	}
}

void Application::Run()
{
	//Main Loop
	Scene *scene = new Mainmenu();
	SceneManager::getSceneManger()->addScene(scene);
	scene = new StudioProject();
	SceneManager::getSceneManger()->addScene(scene);
	scene = new SceneBossL();
	SceneManager::getSceneManger()->addScene(scene);
	scene = new SceneBossM();
	SceneManager::getSceneManger()->addScene(scene);
	scene = new SceneBossH();
	SceneManager::getSceneManger()->addScene(scene);
	scene = new SceneBossR();
	SceneManager::getSceneManger()->addScene(scene);
	scene = new exitmenu();
	SceneManager::getSceneManger()->addScene(scene);
	

	SceneManager::getSceneManger()->initAllScene();

	Application::m_timer.startTimer();    // Start timer to calculate how long it takes to render this frame
	while (!glfwWindowShouldClose(m_window) && !SceneManager::getSceneManger()->isQuit())
	{
		SceneManager::getSceneManger()->update();

	} //Check if the ESC key had been pressed or if the window had been closed

	SceneManager::getSceneManger()->quitAllScene();
}

void Application::Exit()
{
	//Close OpenGL window and terminate GLFW
	glfwDestroyWindow(m_window);
	//Finalize and clean up GLFW
	glfwTerminate();
}
