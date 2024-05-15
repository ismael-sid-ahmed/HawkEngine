#pragma once

#include "../vendor/glad/glad.h"
#include "../vendor/GLFW/glfw3.h"

#include "../header.h"

int CreateWindow();

void CaptureInput();
void TerminateWindow();

GLFWwindow* window;