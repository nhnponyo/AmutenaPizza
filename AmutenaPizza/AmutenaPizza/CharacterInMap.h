#pragma once
#include "NNObject.h"

class NNAnimation;

class CCharacterInMap :
	public NNObject
{
public:
	CCharacterInMap(void);
	~CCharacterInMap(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CCharacterInMap);

private:
	void Init();

	NNAnimation* Character;

	void OperateCharacter();
};

