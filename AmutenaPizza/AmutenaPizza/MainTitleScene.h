#pragma once
#include "NNScene.h"

class NNSprite;
class CUIButton;

class CMainTitleScene :
	public NNScene
{
public:
	CMainTitleScene(void);
	~CMainTitleScene(void);

	virtual void Render();
	virtual void Update( float dTime );

	NNCREATE_FUNC(CMainTitleScene);

private:
	void Init();

	NNSprite* m_pBackground;

	CUIButton*		m_newGame;
	CUIButton*		m_LoadGame;
	CUIButton*		m_Exit;
};

