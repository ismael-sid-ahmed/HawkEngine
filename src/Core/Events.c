#include "Events.h"

Event* EventDispatch(Event event)
{
	Event* new = NULL;

	if (head == NULL) //if empty
	{
		new = malloc(sizeof(Event));
		if (new == NULL)
		{
			log_trace("Not enough memory for the event");
			return NULL;
		}

		new->eventName = event.eventName;
		head = new;
		new->next = NULL; 
	}
	else //if not empty
	{
		new = malloc(sizeof(Event));
		if (new == NULL)
		{
			log_trace("Not enough memory for the event");
			return NULL;
		}
		new->eventName = event.eventName;
		new->next = head;
		head = new;
	}

	return new;
}

void AddListener()
{

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Event key_event;
	char buffer[14];

	snprintf(&buffer, 14, "key_event_%c", key);

	key_event.eventName = _strdup(buffer);
	log_trace("Key pressed: %s", key_event.eventName);

	EventDispatch(key_event);
}

void cursor_pos_callback(GLFWwindow* window, double xPos, double yPos)
{
	Event mouse_event;
	char buffer[35];

	snprintf(&buffer, 14, "mouse_pos_event-X%f Y%f", xPos, yPos);

	mouse_event.eventName = _strdup(buffer);

	log_trace("Mouse Pos: X %f, Y %f", xPos, yPos);
	EventDispatch(mouse_event);
}