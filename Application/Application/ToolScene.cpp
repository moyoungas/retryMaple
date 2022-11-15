#include "framework.h"
#include "ToolScene.h"
#include "myNewApplication.h"
#include "Application.h"
#include "NmyInput.h"
#include "Nmyimage.h"


namespace Nmy
{

    ToolScene::ToolScene()
        : mTileIndex(0)
	{
		mTilePalette = new TilePalette();

	}

	ToolScene::~ToolScene()
	{
		delete mTilePalette;
	}


	void ToolScene::Initialize()
	{
		
	}

	void ToolScene::Tick()
	{
        if (mTilePalette)
            mTilePalette->Tick();
	
	}

	void ToolScene::Render(HDC hdc)
	{

		Scene::Render(hdc);

		WindowDataA mainWidnow = NewApplication::Getinstance().GetWindowdata();

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0, 125, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		int maxRow = mainWidnow.height / TILE_SIZE * TILE_SCALE + 1;
		for (size_t i = 0; i < maxRow; i++)
		{
			MoveToEx(hdc, 0, TILE_SIZE * i * TILE_SCALE, nullptr);
			LineTo(hdc, mainWidnow.width, TILE_SIZE * i * TILE_SCALE);
		}

		int maxColumn = mainWidnow.width / TILE_SIZE * TILE_SCALE + 1;
		for (size_t i = 0; i < maxColumn; i++)
		{
			MoveToEx(hdc, TILE_SIZE * i * TILE_SCALE, 0, nullptr);
			LineTo(hdc, TILE_SIZE * i * TILE_SCALE, mainWidnow.height);
		}

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);


	}


	void ToolScene::Enter()
	{

		NewApplication::Getinstance().SetMenuBar(true);
	}

	void ToolScene::Exit()
	{
	}

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

        RECT rect = { 0, 0, atlas->GetWidth() * TILE_SCALE, atlas->GetHeight() * TILE_SCALE };
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
            //DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
        if (GetFocus())
        {
            Nmy::Vector2 mousePos = Nmy::Input::GetMousePos(hWnd);

            int y = mousePos.y / (TILE_SIZE * TILE_SCALE);
            int x = mousePos.x / (TILE_SIZE * TILE_SCALE);

            int index = (y * TILE_LINE_X) + (x % TILE_LINE_X);

            Nmy::Scene* scene = Nmy::SceneManager::GetPlayScene();
            Nmy::ToolScene* toolScene = dynamic_cast<Nmy::ToolScene*>(scene);
            toolScene->SetTileIndex(index);
        }
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
        TransparentBlt(hdc, pos.x, pos.y, atlas->GetWidth() * TILE_SCALE , atlas->GetHeight() * TILE_SCALE,
            atlas->GetDc(), 0, 0, atlas->GetWidth(), atlas->GetHeight(), RGB(255, 0, 255));

        EndPaint(hWnd, &ps);

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
