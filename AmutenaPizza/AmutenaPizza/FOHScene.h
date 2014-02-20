#pragma once
#include "NNScene.h"

class NNSprite;

class CFOHScene :
	public NNScene
{
public:
	CFOHScene(void);
	~CFOHScene(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CFOHScene);

private:
	void Init();

	NNSprite* m_pBackground;

};

