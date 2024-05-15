#include "EntryPoint.h"

int main(int argc, char* argv[])
{
	log_info("Starting up Hawk Engine");
	log_info("Hawk Engine has started succesfully");

	CreateWindow();
	MainLoop();
}