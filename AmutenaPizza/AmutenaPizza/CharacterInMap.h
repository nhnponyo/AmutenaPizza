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
	void EnterBuilding();// ĳ���� Ŭ������ ����Ǿ� ������, ������ ������ ������ �Ѵ�. �������� ���� ������Ʈ���� �ȵǳ����Ф� ������.. ���߿� �� ����غ��� �ҵ�

};

