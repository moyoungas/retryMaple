#pragma once
#include "Actor.h"

namespace Nmy
{
	class image;

	class BGActor : public Actor
	{

	public:
		BGActor();
		~BGActor();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& imageName);

	private:
		image* pImage;
	};


}


