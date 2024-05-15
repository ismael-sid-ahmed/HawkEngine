#include "Window.h"

int CreateWindow()
{
	if (!glfwInit())
	{
		log_error("Failed to initialize GLFW");
		return -1;
	}

	window = glfwCreateWindow(1280, 720, "Hawk Engine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	//
	//{
		//glClear(GL_COLOR_BUFFER_BIT);
		//glfwSwapBuffers(window);
		//glfwPollEvents();
	//}

	log_trace("Window creation was succesfull");
	return 0;
}

void TerminateWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
