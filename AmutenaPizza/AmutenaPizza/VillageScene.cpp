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
	ChangeMapBackground();
	Character->EnterBuilding(); // 캐릭터 클래스에서 씬을 변경할 수 없어서 여기서 업데이트 한다
}

void CVillageScene::Init()
{


	m_pBackground0 = NNSprite::Create(L"Sprite/map1.png");
	m_pBackground1 = NNSprite::Create(L"Sprite/map2.png");
	m_pBackground2 = NNSprite::Create(L"Sprite/map3.png");

	m_pBackground[0] = m_pBackground0;
	m_pBackground[1] = m_pBackground1;
	m_pBackground[2] = m_pBackground2;

	m_pBackground0 -> SetVisible(true);
	m_pBackground1 -> SetVisible(false);
	m_pBackground2 -> SetVisible(false);

	AddChild(m_pBackground0);
	AddChild(m_pBackground1);
	AddChild(m_pBackground2);

	Character = CCharacterInMap::Create();
	AddChild(Character);
}

void CVillageScene::ChangeMapBackground()
{
	MapNumber mapNumber = Character->GetNumberOfCurrentMap();

	if(m_pBackground[mapNumber]->GetVisible() == false)
	{
		m_pBackground[mapNumber]->SetVisible(true);

		for(int i=0; i<NUMBER_OF_VILLAGE_MAP; ++i )
		{
			if(i != mapNumber )
				m_pBackground[i]->SetVisible(false);
		}
	}
}
