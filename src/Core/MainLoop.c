#include "MainLoop.h"

void MainLoop()
{
	//The main loop will do the following things:
	//1. Poll all events
	//2. Update all game objects
	//3. Render the results

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();

		glfwSetKeyCallback(window, key_callback);
		glfwSetCursorPosCallback(window, cursor_pos_callback);
	}
	
	TerminateWindow();
}