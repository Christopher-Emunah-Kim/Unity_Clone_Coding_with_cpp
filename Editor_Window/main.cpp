// Unity_Clone_Coding_with_cpp.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Unity_Clone_Coding_with_cpp.h"

#include "../SOURCE/K_Application.h"

//#pragma comment(lib, "../x64/Debug/Engine_Window.lib")

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

KHS::Application application; //애플리케이션 객체

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


//API 엔트리포인트
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //프로그램 인스턴스 핸들 값 (프로세스가 실행될 때 OS가 부여하는 고유 핸들 값 _ 프로세스/핸들 주소값)
	                 _In_opt_ HINSTANCE hPrevInstance, //이전 인스턴스 핸들 값 (현재는 사용되지 않음)
	                 _In_ LPWSTR    lpCmdLine, //명령행 인수 (프로그램 실행 시 전달되는 추가 정보) (현재는 사용되지 않음)
	                 _In_ int       nCmdShow) //프로그램이 실행될 형태. 창의 초기 표시 상태를 지정하는 정수 값 (예: 최대화, 최소화, 일반 창 등)
{

    //레거시 코드에서 넘어온 현재는 사용하지않는 파라미터들.
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.





    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_UNITYCLONECODINGWITHCPP, szWindowClass, MAX_LOADSTRING);

	MyRegisterClass(hInstance); //윈도우 클래스 등록

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_UNITYCLONECODINGWITHCPP));
    //HACCEL : 단축키(Accelerator) 테이블 핸들
    //LoadAccelerators함수 : 단축키(Accelerator) 테이블을 로드
    //hInstance : 애플리케이션 인스턴스 핸들
    //MAKEINTRESOURCE : 정수를 리소스 식별자로 변환하는 매크로
    //IDC_CONSOLESHOOTING2D : 단축키 리소스 ID


    MSG msg;
    // MSG : 윈도우 메시지 구조체

    // 기본 메시지 루프입니다:(메시지 큐에 들어온 메시지를 처리하는 반복문)
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))  //단축키 메시지인지 확인
            {
                TranslateMessage(&msg); //키보드 메시지를 변환 (가상키코드를 문자메시지로 변환)
                DispatchMessage(&msg); //메시지를 해당 윈도우 프로시저로 전달
            }
        }
        else
        {
            //게임 로직 및 렌더링
            application.Run();
        }
    }


    //GetMessage 함수 : 메시지 큐에서 메시지를 가져옴(없으면 아무것도 가져오지않음)
    //PeekMessage 함수 : 메시지 큐에서 메시지를 확인(조회)만 함 (큐에서 제거하지 않음) 항상 리턴됨
    //                   true를 반환하면 메시지가 있는 것, false를 반환하면 메시지가 없는 것
    
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) //단축키 메시지인지 확인
    //    {
    //        TranslateMessage(&msg); //키보드 메시지를 변환 (가상키코드를 문자메시지로 변환)
    //        DispatchMessage(&msg); //메시지를 해당 윈도우 프로시저로 전달
    //    }
    //}

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex; //WINDOW CLASS Extended 유니코드 버전(WIndow창 모양 등록용 구조체)

    wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW; //윈도우 스타일(가로세로 크기 변경시 다시 그리기)
    wcex.lpfnWndProc    = WndProc; //윈도우 프로시져 함수 포인터
    wcex.cbClsExtra     = 0; //클래스별 추가 메모리 바이트 수
	wcex.cbWndExtra     = 0; //윈도우별 추가 메모리 바이트 수
	wcex.hInstance      = hInstance; //현재 인스턴스 핸들
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_UNITYCLONECODINGWITHCPP)); //윈도우 아이콘 핸들
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); //윈도우 커서 핸들
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1); //배경 브러시 핸들 (윈도우 배경색)
	wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_UNITYCLONECODINGWITHCPP); //메뉴 리소스 이름
	wcex.lpszClassName  = szWindowClass; //윈도우 클래스 이름
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); //작은 아이콘 핸들

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //윈도우콘솔 타이틀 수정
   SetConsoleTitle(L"Unity Console Shooting 2D");

   //클라이언트 영역 크기 조정
   RECT myRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT }; //클라이언트 영역 크기 설정
   AdjustWindowRectEx(&myRect, WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME, FALSE, 0);
   //윈도우 스타일 (최대화 버튼 제거 연산, 테두리 크기 변경 제거 비트 연산) 
   //AdjustWindowRect함수 : 윈도우 스타일에 맞게 클라이언트 영역 크기를 조정
   //myRect : 조정할 RECT 구조체 포인터

   //실제 윈도우 생성
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,
       APP_POSITION_X, APP_POSITION_Y, //시작좌표(스크린 좌표계)
       myRect.right - myRect.left, myRect.bottom - myRect.top, //윈도우 스타일에 맞춰 조정된 너비와 높이
       nullptr, nullptr, hInstance, nullptr);

   application.Initialize(hWnd); //애플리케이션 초기화

   /* HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);  (DEFAULT) */
       //CreateWindowW함수
       //윈도우 클래스 이름, 윈도우 타이틀, 윈도우 스타일, x좌표, y좌표, 너비, 높이, 부모 윈도우 핸들, 메뉴 핸들, 인스턴스 핸들, 추가 매개변수

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow); //윈도우를 화면에 표시
   UpdateWindow(hWnd); //윈도우의 클라이언트 영역을 갱신

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다. (메시지 루프의 처리함수. 핵심부분)
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
