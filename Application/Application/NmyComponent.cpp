#include "NmyComponent.h"
#include "Actor.h"
namespace Nmy
{

	Component::Component(eComponentType type)
		: mType(type)
		, mOwner(nullptr)
	{

	}
	Component::~Component()
	{

	}
	void Component::Tick()
	{
		if (mOwner->IsDeath())
			return;

	}
	void Component::Render(HDC hdc)
	{
	}
}