
#ifndef APPLICATION_H
#define APPLICATION_H

#include "timer.h"
//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(unsigned short key);

	static GLFWwindow* m_window;
	static StopWatch m_timer;
	static const unsigned int frameTime;
	static float elapsed_timer_;

};

#endif