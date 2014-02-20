#pragma once
#include "NNObject.h"
#include "GameConfig.h"

class NNAnimation;
class NNScene;

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

	NNAnimation*	Character;

	MapNumber		numberOfCurrentMap;

	NNScene*		buildingScene[NUMBER_OF_BIULDING];

	void OperateCharacter();
	void SetCharacterOnLeft();
	void SetCharacterOnRight();
	void ChangeNumberOfCurrentMap();

public:
	void EnterBuilding();// 캐릭터 클래스에 선언되어 있지만, 실행은 빌리지 씬에서 한다. 씬변경이 하위 오브젝트에선 안되나봄ㅠㅠ 에러남.. 나중에 더 고민해봐야 할듯

};

