// Application.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "NCommon.h"
#include "Application.h"
#include "myNewApplication.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance, WNDPROC wndProc, LPCWSTR windowName);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    AtlasWndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



// int main
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
   /* _CrtSetBreakAlloc(282);*/

    // TODO: 여기에 코드를 입력합니다.

    // 1. wndclass 정의 윈도우 기반(여러가지 속성)이 되는 클래스를 정의

    // 2. 메모리상에 윈도우를 할당 (createwindow)

    // 3. showWindow함수를 통해 윈도우가 화면에 보여줌(update window)

    // 4. wndclass를 정의할 때 함수포인터에 넣어준 루프문(wndproc) 매 프레임마다 실행한다.
    
    // 윈도우즈는 크게 3가지 라이브러리로 이루어짐
    
    // 메모리를 관리하고 실행시키는 KERNEL (커널)
    // 유저 인터페이스와 관리하는 USER
    // 화면처리와 그래픽을 담당하는 GDI로 이루어져있다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_APPLICATION, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance, WndProc, szWindowClass);
    MyRegisterClass(hInstance, AtlasWndProc, L"AtlasWindow");

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_APPLICATION));

    MSG msg;

    // GetMessage : 프로세스에 발생한 메세지를 큐에서 꺼내옴
    // 메세지가 있을때만 메세지를 꺼내옴
    // 메세지 case함수를 호출해준다.
    //-> 큐 안에 없다면 응답x

    // 메시지가 없어도 메시지 큐에서 꺼내오는 방법
    // PeekMessage
    // 발생한 메시지를 가져올 때 메시지 큐에서 따로 제거해줘야함
    // 메시지 큐에 메시지가 들어있는 유/무에 상관없이 함수가 리턴됩니다.
    //-> 게임에서 사용

    // 타이머의 경우 
    // 성능에 관계없이 똑같이 프레임 초기화를 해주기 때문에
    // 게임에서 사용하기 적절치 않다.

    // 기본 메시지 루프입니다:
    while (true)
    {
        if (PeekMessage(&msg, nullptr,0,0,PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            // 게임 실행
            Nmy::NewApplication::Getinstance().Tick();
        }
    }
    // 종료가 되었을 때
    if (WM_QUIT == msg.message)
    {
        // 해제작업
    }

    return (int) msg.wParam;
}

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance, WNDPROC wndProc, LPCWSTR windowName)
{
    WNDCLASSEXW wcex;

    // 버퍼 사이즈
    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = wndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    // 프로그램 아이콘
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    // 프로그램 내 커서모양
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);

    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = nullptr;//MAKEINTRESOURCEW(IDC_APPLICATION);
    wcex.lpszClassName  = windowName;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

   WindowDataA windowdata;
   windowdata.width = 1600;
   windowdata.height = 900;



   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   windowdata.hWnd = hWnd;
   windowdata.hdc = nullptr;

   if (!hWnd)
   {
      return FALSE;
   }
   SetWindowPos(hWnd, nullptr, 0, 0, windowdata.width, windowdata.height, 0);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   Nmy::NewApplication::Getinstance().Initialize(windowdata);





   WindowDataA Atlaswindowdata;
   //Atlaswindowdata.width = 500;
   //Atlaswindowdata.height = 500;

   hWnd = CreateWindowW(L"AtlasWindow", szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   Atlaswindowdata.hWnd = hWnd;

 /*  SetWindowPos(hWnd, nullptr, windowdata.width, 0, Atlaswindowdata.width, Atlaswindowdata.height, 0);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);*/

   Nmy::NewApplication::Getinstance().initializeAtalsWindow(Atlaswindowdata);


   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

#include "SceneManager.h"
#include "NmyScene.h"
#include "ToolScene.h"
#include "ymTilePalette.h"
#include "Nmyimage.h"
#include "NmyInput.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // 윈도우는 메세지 기반으로 움직인다.
    // queue에 메세지를 넣어두고 차례대로 
    // 한개씩 처리한다.

    switch (message)
    {

    case WM_CREATE:
    {
     /*   SetTimer(hWnd, 0, 100, nullptr);*/
    }
    break;

    case WM_KEYDOWN:
    {
        // wParam : 키보드 좌표
        // lParam : 마우스 좌표
        // 키입력이 있으면 그 입력에 대한 값이 자동으로 wParam  과 lParam으로 넘어옴

        //Pos pos = player.GetPos();

        //// wParam ASCII 코드가 전달인자로 넘어온다.
        //switch (wParam)
        //{
        //case 'W':
        //{
        //    pos.y -= 10;
        //}
        //break;

        //case 'A':
        //{
        //    pos.x -= 10;
        //}
        //break;

        //case 'S':
        //{
        //    pos.y += 10;
        //}
        //break;

        //case 'D':
        //{
        //    pos.x += 10;
        //}
        //break;
        //}
        //player.SetPos(pos);
        //InvalidateRect(hWnd, nullptr, false);
    }
    break;


    case WM_TIMER:
    {
        //for (size_t i = 0; i < 256; i++)
        //{
        //    Pos pos = player[i].GetPos();
        //    pos.x += 3;
        //    player[i].SetPos(pos);
        //}
        //InvalidateRect(hWnd, nullptr, false);
    }
    break;
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

            //HBRUSH hClearBrush = CreateSolidBrush(RGB(100, 100, 100));
            HBRUSH hClearBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
            HBRUSH oldClearBrush = (HBRUSH)SelectObject(hdc, hClearBrush);

            // 선이 남기때문에 1픽셀씩 더 그려줌
            Rectangle(hdc, -1, -1, 1921, 1081);            

            // 펜 오브젝트 생성
            /*SelectObject(hdc, hBlueBrush);*/

            // 하나의 펜과 하나의 브러쉬만 사용가능하기때문에
            // 사용할 때 항상 SelectObject를 해줘야한다.
            // 처음 남겨진 펜을 남겨두자

            // 디폴트로 검정색 펜이 세팅되어 있다.


            //for (size_t i = 0; i < 256; i++)
            //{

            //    HPEN hRedPen = CreatePen(PS_SOLID, 3, RGB(rand() % 256, rand() % 256, rand() % 256));
            //    HBRUSH hBlueBrush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));

            //    HPEN oldPen = (HPEN)SelectObject(hdc, hRedPen);
            //    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);

            //    Pos playerPos = player[i].GetPos();
            //    Size playerSize = player[i].GetSize();
            //    Ellipse(hdc, playerPos.x, playerPos.y, playerPos.x + playerSize.x, playerPos.y + playerSize.y);


            //    SelectObject(hdc, oldPen);
            //    SelectObject(hdc, oldBrush);

            //    DeleteObject(hRedPen);
            //    DeleteObject(hBlueBrush);
            //}
            // 길이가 아니고 좌표이기때문에 플러스함 
            // 
            //DeleteObject(oldClearBrush);
            //DeleteObject(hRedPen);  세팅 후 메모리 해제할 것

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);

            // Paint의 문제점
            // dc를 가져올 때 겹치는 경우!?
            // dc를 새로 받아 따로따로 쓴다.
            // 
            // 펜
            // HPEN, HBRUSH
            
            // 문자
            // HFONT , HBITMAP(이미지파일)
            
            // 자주쓰는 걸 미리 만들어 놓음
            //-> 스톡 오브젝트
            
      
            // 스톡 오브젝트
            //GetStockObject(GRAY_BRUSH);

            // DC정리
            // 1. PEN , BRUSH 핸들을 선언한다.
            // 2. 선언된 핸들로 GDI 오브젝트를 생성해준다.
            // 3. 생성된 오브젝트로 hdc에 세팅해준다.(selectobject)
            // 4. 사용한 후 기존의 오브젝트로 되돌린다.
            // 5. 만들었던 핸들을 삭제한다 (deleteobject)
        }
        break;
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        // 타이머 꼭 제거할 것(타이머순서)
        /*KillTimer(hWnd, 0);*/
    }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK AtlasWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

    case WM_CREATE:
    {
        WindowDataA windowdata =
            Nmy::NewApplication::Getinstance().GetWindowdata();

        WindowDataA Atlasdata = 
            Nmy::NewApplication::Getinstance().GetAtlasWindowdata();



        Nmy::Scene* scene = Nmy::SceneManager::GetPlayScene();
        Nmy::ToolScene* toolScene = dynamic_cast<Nmy::ToolScene*>(scene);

        Nmy::image* atlas = toolScene->GetAtlasimage();

        RECT rect = { 0, 0, atlas->GetWidth(), atlas->GetHeight()};
        //AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, true);

        // 윈도우 크기 변경
        SetWindowPos(hWnd, nullptr, windowdata.width, 0,
            atlas->GetWidth(), atlas->GetHeight(), 0);

        ShowWindow(hWnd, true);
        UpdateWindow(hWnd);


        
    }
    break;
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

    case WM_LBUTTONDOWN:
    {
        Nmy::Vector2 mousePos = Nmy::Input::GetMousePos();
        int a = 0;



    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        WindowDataA Atlasdata =
            Nmy::NewApplication::Getinstance().GetAtlasWindowdata();



        Nmy::Scene* scene = Nmy::SceneManager::GetPlayScene();
        Nmy::ToolScene* toolScene = dynamic_cast<Nmy::ToolScene*>(scene);

        Nmy::image* atlas = toolScene->GetAtlasimage();

        Nmy::Vector2 pos(Nmy::Vector2::Zero);
        TransparentBlt(hdc, pos.x, pos.y, atlas->GetWidth(), atlas->GetHeight(),
            atlas->GetDc(), 0, 0, atlas->GetWidth(), atlas->GetHeight(), RGB(255, 0, 255));


    }
    break;
    case WM_DESTROY:
    {
        PostQuitMessage(0);

    }
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
