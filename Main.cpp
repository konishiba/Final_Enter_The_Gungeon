#include "Engine.h"
#include "LevelManager.h"
#include "Proto_Map.h"


void InitConfig()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Logger::Reset();
	system("cls");
}

int main()
{
	InitConfig();

	Proto_Map* _level = new Proto_Map("mapTest");
	M_LEVEL.SetLevel(_level);

	Engine _engine;
	_engine.Start();

	return EXIT_SUCCESS;
}