#include "Nmyimage.h"
#include "myNewApplication.h"
#include "MyResources.h"

namespace Nmy
{
	image* image::Create(const std::wstring& key, UINT width, UINT height)
	{

		
		image* pimage = Resources::Find<image>(key);
		if (pimage != nullptr)
		{
			MessageBox(nullptr, L"�ߺ� Ű �̹��� ����", L"�̹��� ����",MB_OK);
			return nullptr;
		}

		pimage = new image();

		HDC mainHDC = NewApplication::Getinstance().GetHDC();
		pimage->mBitmap = CreateCompatibleBitmap(mainHDC, width, height);
		pimage->mhdc = CreateCompatibleDC(mainHDC);

		if (pimage->mBitmap == NULL || pimage->mhdc == NULL)
			return nullptr;

		// ���� ������ ��Ʈ�ʰ� DC�� ���� �������ش�
		HBITMAP  defaultBitmap = (HBITMAP)SelectObject(pimage->mhdc, pimage->mBitmap);
		DeleteObject(defaultBitmap);

		// ��Ʈ�� ���� Ȯ��
		BITMAP bitmap = {};
		GetObject(pimage->mBitmap, sizeof(BITMAP), &bitmap);

		pimage->mWidth = bitmap.bmWidth;
		pimage->mheight = bitmap.bmHeight;

		pimage->SetKey(key);
		Resources::Insert<image>(key, pimage);

		return pimage;
	}
	image::image()
		: mBitmap(NULL)
		, mhdc(NULL)
		, mWidth(0)
		, mheight(0)
	{

	}

	image::~image()
	{
		HWND newHwnd = NewApplication::Getinstance().GetWindowdata().hWnd;
		ReleaseDC(newHwnd, mhdc);
	}

	HRESULT image::Load(const std::wstring& path)
	{

		mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(),
			IMAGE_BITMAP, 0, 0,
			LR_LOADFROMFILE | LR_LOADFROMFILE);
		if (mBitmap == nullptr)
		{
			return E_FAIL;
		}

		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

		mWidth = bitInfo.bmWidth;
		mheight = bitInfo.bmHeight;

		HDC mainDC = NewApplication::Getinstance().GetWindowdata().hdc;
		mhdc = CreateCompatibleDC(mainDC);

		HBITMAP prevBit = (HBITMAP)SelectObject(mhdc,mBitmap);
		DeleteObject(prevBit);


		return S_OK;
	}


}