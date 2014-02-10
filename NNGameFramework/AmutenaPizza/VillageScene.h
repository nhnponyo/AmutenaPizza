#pragma once
#include "NNScene.h"

class CCharacterInMap;
class NNSprite;

class CVillageScene :
	public NNScene
{
public:
	CVillageScene(void);
	~CVillageScene(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CVillageScene);

private:
	void Init();

	NNSprite*			m_pBackground0;
	CCharacterInMap*	Character;
};

