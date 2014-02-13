#include "CharacterInMap.h"
#include "NNAnimation.h"
#include "NNInputSystem.h"

CCharacterInMap::CCharacterInMap(void)
{
	Init();
}


CCharacterInMap::~CCharacterInMap(void)
{
}

void CCharacterInMap::Render()
{
	NNObject::Render();
}

void CCharacterInMap::Update( float dTime )
{
	NNObject::Update(dTime);

	OperateCharacter();
	ChangeNumberOfCurrentMap();
}

void CCharacterInMap::Init()
{
	Character = NNAnimation::Create(1, L"Sprite/cook.png");

	SetCharacterOnLeft();
	AddChild(Character);

	numberOfCurrentMap = PIZZA_BAKERY_0;
}

void CCharacterInMap::OperateCharacter()
{
	NNPoint nowPosition = Character->GetPosition();

	if(NNInputSystem::GetInstance()->GetKeyState(VK_LEFT) == KEY_PRESSED)
		if( Character->GetPositionX() >= 40)
			Character->SetPosition(nowPosition + NNPoint( -0.5, 0.0 ));

	if(NNInputSystem::GetInstance()->GetKeyState(VK_RIGHT) == KEY_PRESSED)
		if( Character->GetPositionX() <= 880)
			Character->SetPosition(nowPosition + NNPoint( 0.5, 0.0 ));
}

void CCharacterInMap::SetCharacterOnLeft()
{
	Character->SetPosition(41,360);
}

void CCharacterInMap::SetCharacterOnRight()
{
	Character->SetPosition(879,360);
}

void CCharacterInMap::ChangeNumberOfCurrentMap()
{
	NNPoint charaterPosition = Character -> GetPosition();
	if( charaterPosition.GetX() >= 880)
	{
		numberOfCurrentMap =  static_cast<MapNumber> ((numberOfCurrentMap + 1) % NUMBER_OF_VILLAGE_MAP); // go forward
		SetCharacterOnLeft();
		return;
	}
	if( charaterPosition.GetX() <= 40)
	{
		numberOfCurrentMap =  static_cast<MapNumber> ((numberOfCurrentMap + NUMBER_OF_VILLAGE_MAP - 1) % NUMBER_OF_VILLAGE_MAP);
		SetCharacterOnRight();
		return;
	}
}

