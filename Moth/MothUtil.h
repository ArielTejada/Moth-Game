#pragma once

#include "pch.h"

#ifdef MOTH_WINDOWS
	#ifdef MOTH_LIB
		#define MOTH_API __declspec(dllexport)
	#else
		#define MOTH_API __declspec(dllimport)
	#endif
#else
	#define MOTH_API
#endif

#ifdef MOTH_DEBUG
	#define MOTH_LOG(x) std::cout<<x<<std::endl;
#else
	#define MOTH_LOG(x)
#endif