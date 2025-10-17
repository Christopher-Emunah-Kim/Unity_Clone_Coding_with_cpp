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
#include <functional>
#include <filesystem>

#include <assert.h>

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Msimg32.lib")

#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")


#include "K_Math.h"
#include "K_Enums.h"

using namespace std;

//컴파일 상수
constexpr int WINDOW_WIDTH = 1280; //윈도우 창 크기 너비
constexpr int WINDOW_HEIGHT = 720; //윈도우 창 크기 높이
constexpr int APP_POSITION_X = 250;//윈도우 창 시작 좌표 X
constexpr int APP_POSITION_Y = 180;//윈도우 창 시작 좌표 Y