#pragma once
#define KEY_PRESSED(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::PRESSED
#define KEY_DOWN(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::DOWN
#define KEY_UP(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::UP

// ũ�⺯ȯ ���̺귯��

enum class eSceneType
{

	Logo,
	Title,
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
	Sound,
	END,


};

#define _COLLIDER_LAYER 16
enum class eColliderLayer
{
	Defalut,
	BackGround,
	Tile,
	Player,
	Player_Projecttile,
	Monster,
	Monster_Projecttile,

	BACKPACK,

	UI = _COLLIDER_LAYER - 1,
	End = 16,
};

enum class CameraEffect
{
	None,
	FadeIn,
	FadeOut,
	End,


};

// union ����ü 
//- ������ �޸� ������ ������
union ColliderID
{
	// �����̶� �� ���� �˻��ϱ����� 
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 ID;

};