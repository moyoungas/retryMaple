#include "myNewApplication.h"
#include "SceneManager.h"
#include "Time.h"
#include "NmyInput.h"
#include "DropManager.h"
#include "MyResources.h"
#include "ColliderManager.h"
#include "NmyCamera.h"

#include "Application.h"

namespace Nmy
{/*
	NewApplication NewApplication::mInstance;*/
	// �̱��� ���� �޸𸮼Ҹ��ڰ� ȣ����� ����

	void Nmy::NewApplication::Initialize(WindowDataA data)
	{
		initializeWindow(data);

		Time::Initialize();
		Input::Initialize();
		Camera::Initialize();

		SceneManager::Initialize();
		//DropManager::Initialize();
	}

	void Nmy::NewApplication::initializeAtalsWindow(WindowDataA data)
	{
		mAtlasWindowdata = data;
		mAtlasWindowdata.hdc = GetDC(data.hWnd);

	}

	void Nmy::NewApplication::Tick()
	{
		Time::Tick();
		Input::Tick();

		Camera::Tick();

		SceneManager::Tick();
		ColliderManager::Tick();

		HBRUSH hPrevBrush = (HBRUSH)SelectObject(mWindowdata.backBuffer, mBrush[(UINT)eBrushColor::Gray]);
		// clear
		Rectangle(mWindowdata.backBuffer,
			-1, -1, mWindowdata.width + 1, mWindowdata.height + 1);
		SelectObject(mWindowdata.backBuffer, hPrevBrush);

		SceneManager::Render(mWindowdata.backBuffer);
		Camera::Render(mWindowdata.backBuffer);
		Input::Render(mWindowdata.backBuffer);
		Time::Render(mWindowdata.backBuffer);

		// BitBlt �Լ��� dc���� �̹����� �������ִ� �Լ�
		BitBlt(mWindowdata.hdc, 0, 0, mWindowdata.width, mWindowdata.height
			,mWindowdata.backBuffer, 0,0, SRCCOPY);


		// actor ����

		SceneManager::DestroyActor();
	}

	Nmy::NewApplication::NewApplication()
	{
		mWindowdata.clear();
	}

	Nmy::NewApplication::~NewApplication()
	{
		SceneManager::Release();
		Resources::Release();
		ReleaseDC(mWindowdata.hWnd, mWindowdata.hdc);
		ReleaseDC(mWindowdata.hWnd, mWindowdata.backBuffer);
	}

	void NewApplication::initializeWindow(WindowDataA data)
	{
		mWindowdata = data;
		mWindowdata.hdc = GetDC(data.hWnd);

		// ��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�� ���
		RECT rect = { 0, 0, mWindowdata.width, mWindowdata.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		// ������ ũ�� ����
		SetWindowPos(mWindowdata.hWnd, nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top, 0
		);

		ShowWindow(mWindowdata.hWnd, true);

		mWindowdata.backTexture 
			= CreateCompatibleBitmap(mWindowdata.hdc, mWindowdata.width, mWindowdata.height);

		mWindowdata.backBuffer
			= CreateCompatibleDC(mWindowdata.hdc);

		HBITMAP defalutBitmap 
			= (HBITMAP)SelectObject(mWindowdata.backBuffer, mWindowdata.backTexture);

		DeleteObject(defalutBitmap);

		// �޸� ���� �ʼ�
		mPen[(UINT)ePenColor::RED] = CreatePen(PS_SOLID,2,RGB(255,0,0));
		mPen[(UINT)ePenColor::GREEN] = CreatePen(PS_SOLID,2,RGB(255,0,0));
		mPen[(UINT)ePenColor::BLUE] = CreatePen(PS_SOLID,2,RGB(255,0,0));


		 mBrush[(UINT)eBrushColor::Transparent] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		 mBrush[(UINT)eBrushColor::Black] = (HBRUSH)GetStockObject(BLACK_BRUSH);
		 mBrush[(UINT)eBrushColor::White] = (HBRUSH)GetStockObject(WHITE_BRUSH);
		 mBrush[(UINT)eBrushColor::Gray] = CreateSolidBrush(RGB(71, 71, 71));


		 mMenu = LoadMenu(nullptr, MAKEINTRESOURCEW(IDC_APPLICATION));
	}



	void NewApplication::SetMenuBar(bool power)
	{
		SetMenu(mWindowdata.hWnd, mMenu);

		// ��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�� ���
		RECT rect = { 0, 0, mWindowdata.width, mWindowdata.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, power);

		// ������ ũ�� ����
		SetWindowPos(mWindowdata.hWnd, nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top, 0
		);

		ShowWindow(mWindowdata.hWnd, true);

	}

}

