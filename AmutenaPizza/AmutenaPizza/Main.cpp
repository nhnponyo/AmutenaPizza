
#include "NNApplication.h"
#include "NNAudioSystem.h"
#include "MainTitleScene.h"


#ifdef _DEBUG
#pragma comment(lib, "NNGameFramework_DEBUG.lib")
#else
#pragma comment(lib, "NNGameFramework.lib")
#endif

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd ){
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );
	AllocConsole();
	FILE* console;
	freopen_s( &console, "CONOUT$", "wt", stdout );

	printf_s("Console Open \n");
#endif 


	NNApplication* Application = NNApplication::GetInstance();
	Application->Init( L"Amutena Pizza", 1024, 640, D2D );
	
	NNSceneDirector::GetInstance()->ChangeScene( CMainTitleScene::Create());
	
	Application->Run();
	Application->Release();

#ifdef _DEBUG
	FreeConsole();
#endif

	return 0;
}