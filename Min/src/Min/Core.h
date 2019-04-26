#pragma once


#ifdef MIN_PLATFORM_WINDOWS
#ifdef MIN_BUILD_DLL
#define MIN_API __declspec(dllexport)
#else 
#define MIN_API __declspec(dllimport)
#endif 

#else 
#error Min only support Windows


#endif 
#define BIT(x) (1 << x)
