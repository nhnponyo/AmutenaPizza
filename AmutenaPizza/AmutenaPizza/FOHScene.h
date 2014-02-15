#pragma once
#include "NNScene.h"
class CFOHScene :
	public NNScene
{
public:
	CFOHScene(void);
	~CFOHScene(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CFOHScene);
};

