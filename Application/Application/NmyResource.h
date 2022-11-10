#pragma once
#include "NCommon.h"



namespace Nmy
{
	class Resource
	{
	public:
		Resource();
		virtual ~Resource();

		// 순수가상함수는 자식객체가 무조건 만들어야한다.
		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetKey() { return mKey; }
		const std::wstring& GetPath() { return mPath; }

		void SetKey(const std::wstring& key) { mKey = key; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		std::wstring mPath;
		std::wstring mKey;
	};

}



