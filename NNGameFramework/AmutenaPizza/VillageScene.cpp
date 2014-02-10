#include "VillageScene.h"
#include "CharacterInMap.h"
#include "NNSprite.h"

CVillageScene::CVillageScene(void)
{
	Init();
}


CVillageScene::~CVillageScene(void)
{
}

void CVillageScene::Render()
{
	NNScene::Render();
}

void CVillageScene::Update( float dTime )
{
	NNScene::Update(dTime);
}

void CVillageScene::Init()
{
	m_pBackground0 = NNSprite::Create(L"Sprite/map1.png");
	AddChild(m_pBackground0);

	Character = CCharacterInMap::Create();
	AddChild(Character);
}
