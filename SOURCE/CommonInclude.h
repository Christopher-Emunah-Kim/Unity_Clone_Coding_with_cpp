#pragma once

#ifndef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION 0x0800
#endif

#include <Windows.h>
#include <iostream>
#include <chrono>
#include <conio.h>
#include <ctime>

#include <vector>
#include <map>
#include <list>
#include <string>

#include <assert.h>

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Msimg32.lib")

#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")

using namespace std;


#include "K_Math.h"
#include "K_Enums.h"