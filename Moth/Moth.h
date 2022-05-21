#pragma once

#include "MothApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "KeyCodes.h"
#include "Events.h"

#define MOTH_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}
