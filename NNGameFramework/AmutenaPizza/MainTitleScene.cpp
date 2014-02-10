#include "MainTitleScene.h"
#include "NNSprite.h"
#include "UIButton.h"
#include "NNInputSystem.h"
#include "NNApplication.h"
#include "VillageScene.h"


CMainTitleScene::CMainTitleScene(void)
{
	Init();
}


CMainTitleScene::~CMainTitleScene(void)
{
}

void CMainTitleScene::Render()
{
	NNScene::Render();
}

void CMainTitleScene::Update( float dTime )
{
	NNScene::Update(dTime);

	m_newGame->CheckButtonOn();
	m_LoadGame->CheckButtonOn();
	m_Exit->CheckButtonOn();

	if(NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON))
	{
		if(m_newGame->CheckButtonArea())
		{
			NNSceneDirector::GetInstance()->ChangeScene(CVillageScene::Create());
			return ;
		}
		else if(m_LoadGame->CheckButtonArea())
		{
			return ;
		}
		else if(m_Exit->CheckButtonArea())
		{
			PostMessage( NNApplication::GetInstance()->GetHWND(), 
				WM_DESTROY, 0, 0 );
			return;
		}
	}
}

void CMainTitleScene::Init()
{
	m_pBackground = NNSprite::Create(L"Sprite/title.png");
	m_pBackground->SetPosition(0,0);
	AddChild(m_pBackground);

	m_newGame = CUIButton::Create(L"Sprite/newgame.png", L"Sprite/newgame_on.png",L"Sprite/newgame_on.png");
	m_newGame->SetPosition(450, 370);
	AddChild(m_newGame);

	m_LoadGame = CUIButton::Create(L"Sprite/Loadgame.png", L"Sprite/Loadgame_on.png", L"Sprite/Loadgame_on.png");
	m_LoadGame->SetPosition(450, 430);
	AddChild(m_LoadGame);

	m_Exit = CUIButton::Create(L"Sprite/exit.png", L"Sprite/exit_on.png", L"Sprite/exit_on.png");
	m_Exit->SetPosition(480,490);
	AddChild(m_Exit);
}
