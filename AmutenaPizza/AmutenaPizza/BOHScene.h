#pragma once
#include "NNScene.h"
class CBOHScene :
	public NNScene
{
public:
	CBOHScene(void);
	~CBOHScene(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CBOHScene);
};

