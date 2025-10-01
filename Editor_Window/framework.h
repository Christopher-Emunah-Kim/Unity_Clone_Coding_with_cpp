#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>



//컴파일 상수
constexpr int WINDOW_WIDTH = 1280; //윈도우 창 크기 너비
constexpr int WINDOW_HEIGHT = 720; //윈도우 창 크기 높이
constexpr int APP_POSITION_X = 200;//윈도우 창 시작 좌표 X
constexpr int APP_POSITION_Y = 100;//윈도우 창 시작 좌표 Y