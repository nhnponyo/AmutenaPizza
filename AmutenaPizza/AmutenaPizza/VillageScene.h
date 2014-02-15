#pragma once
#include "NNScene.h"
#include "GameConfig.h"

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

	CCharacterInMap*	Character;
	NNSprite*			m_pBackground0;
	NNSprite*			m_pBackground1;
	NNSprite*			m_pBackground2;
	NNSprite*			m_pBackground[NUMBER_OF_VILLAGE_MAP];

	void ChangeMapBackground();
};

