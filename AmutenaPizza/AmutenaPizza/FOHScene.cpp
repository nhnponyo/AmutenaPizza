#include "FOHScene.h"
#include "NNSprite.h"


CFOHScene::CFOHScene(void)
{
	Init();
}


CFOHScene::~CFOHScene(void)
{
}

void CFOHScene::Render()
{
	NNScene::Render();
}

void CFOHScene::Update( float dTime )
{
	NNScene::Update(dTime);
}

void CFOHScene::Init()
{
	m_pBackground = NNSprite::Create(L"Sprite/FOH.png");
	AddChild(m_pBackground);
}
