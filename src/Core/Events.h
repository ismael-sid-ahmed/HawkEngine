#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

#include "Window.h"
#include "../vendor/GLFW/glfw3.h"

//Event Bus Explanation (to be deleted): The callbacks from GLFW would dispatch the
//event into the event bus, being inserted in the first place. In the Event Bus,
//the events will get checked by functions that recieve events. When one reacts to this
//event, it will send a signal to change the isHandeled bool to true. With that the Event
//will get marked for deletion.

typedef struct
{
	char* eventName;
	struct Event* next;
	bool isHandeled;
}Event;

typedef struct
{
	char* eventName;
}Listener;

Event* head = NULL;

Event* EventDispatch(Event event);
void AddListener();

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_pos_callback(GLFWwindow* window, double xPos, double yPos);