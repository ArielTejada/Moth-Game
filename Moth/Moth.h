#pragma once

#include "MothApp.h"
#include "GameWindow.h"

#define MOTH_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}
