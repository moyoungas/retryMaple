#pragma once

#include "framework.h"
#include <vector>
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <bitset>
#include "def.h"
#include "Maths.h"
#pragma comment(lib,"Msimg32.lib")
#include <functional>
#include <filesystem>

#include <set>
// typedef Pos POINT;
// 메인함수에 이미 존재하기에 주석처리 
//using Pos = POINT;

struct WindowDataA
{
	HWND hWnd;
	HDC hdc; // 메인버퍼

	// 렌더타겟, 프레임 버퍼
	HBITMAP backTexture;
	HDC backBuffer; // 백버퍼

	UINT height;
	UINT width;
	
	void clear()
	{
		HWND hWnd = nullptr;
		HDC hdc = nullptr;
		UINT height = 0;
		UINT width = 0;
	}
};

struct Pen
{
private:
	HDC mhdc;
	HPEN oldPen;
	HPEN asPen;
public:
	Pen(HDC hdc)
		: mhdc(hdc)
		, oldPen(NULL)
		, asPen(NULL)
	{

	}
	Pen(HDC hdc, HPEN mPen)
		: mhdc(hdc)
		, oldPen(NULL)
		, asPen(mPen)
	{
		oldPen = (HPEN)SelectObject(mhdc, mPen);
	}

	~Pen()
	{
		SelectObject(mhdc, oldPen);
		DeleteObject(asPen);
	}
	void SetPen(HPEN mPen)
	{
		oldPen = (HPEN)SelectObject(mhdc, mPen);
	}
};

struct Brush
{
private:
	HDC mhdc;
	HBRUSH oldbrush;
	HBRUSH mbrush;
public:
	Brush(HDC hdc, HBRUSH brush)
		: mhdc(hdc)
		, oldbrush(NULL)
		, mbrush(brush)
	{

		oldbrush = (HBRUSH)SelectObject(mhdc, brush);
	}

	~Brush()
	{

		SelectObject(mhdc, oldbrush);
		DeleteObject(mbrush);
	}

};
