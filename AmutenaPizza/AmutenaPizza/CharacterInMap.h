#pragma once
#include "NNObject.h"
#include "GameConfig.h"

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

public:
	MapNumber GetNumberOfCurrentMap() { return numberOfCurrentMap;}

private:
	void Init();

	NNAnimation* Character;

	MapNumber numberOfCurrentMap;

	void OperateCharacter();
	void SetCharacterOnLeft();
	void SetCharacterOnRight();
	void ChangeNumberOfCurrentMap();

};

