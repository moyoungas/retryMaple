#pragma once
#define KEY_PRESSED(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::PRESSED
#define KEY_DOWN(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::DOWN
#define KEY_UP(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::UP

// 크기변환 라이브러리

enum class eSceneType
{

	Logo,
	Title,
	Tool,
	Play,
	End,
	MAX,

};

enum class ePenColor
{
	RED,
	BLUE,
	GREEN,
	END,
};

enum class eBrushColor
{
	Transparent,
	Black,
	Gray,  // 160 , 0 , 67
	White,
	END,

};

enum class eComponentType
{
	Animator,
	Collider,
	RigidBody,
	Sound,
	END,


};

#define _COLLIDER_LAYER 16
enum class eColliderLayer
{
	Defalut,
	BackGround,
	Tile,
	Map,
	Player,
	Player_Projecttile,
	Monster,
	Monster_Projecttile,
	Ground,
	BACKPACK,

	UI = _COLLIDER_LAYER - 1,
	End = 16,
};

enum class eUIType
{
	HP,
	MP,
	Inventory,
	OPTION,
	SHOP,
	END,
};

enum class CameraEffect
{
	None,
	FadeIn,
	FadeOut,
	End,


};

// union 공유체 
//- 데이터 메모리 공간을 공유함
union ColliderID
{
	// 조금이라도 더 빨리 검색하기위해 
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 ID;

};
typedef ColliderID TileID;

// 게임에 따라 변경할것

#define TILE_SIZE 32
#define TILE_SCALE 2

#define TILE_LINE_X 8
#define TILE_LINE_Y 3