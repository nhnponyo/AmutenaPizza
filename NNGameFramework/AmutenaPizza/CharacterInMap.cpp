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
}

void CCharacterInMap::Init()
{
	Character = NNAnimation::Create(1, L"Sprite/cook.png");
	Character->SetPosition(30,400);
	AddChild(Character);
}

void CCharacterInMap::OperateCharacter()
{
	NNPoint nowPosition = Character->GetPosition();

	if(NNInputSystem::GetInstance()->GetKeyState(VK_LEFT) == KEY_PRESSED)
		Character->SetPosition(nowPosition + NNPoint( -0.5, 0.0 ));

	if(NNInputSystem::GetInstance()->GetKeyState(VK_RIGHT) == KEY_PRESSED)
		Character->SetPosition(nowPosition + NNPoint( 0.5, 0.0 ));
}


