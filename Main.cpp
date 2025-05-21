#include "Engine.h"
#include "LevelManager.h"
#include "LVL_ProtoCollision.h"


void InitConfig()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Logger::Reset();
	system("cls");
}

int main()
{
	InitConfig();

	LVL_ProtoCollision* _level = new LVL_ProtoCollision("TESTLevel");
	M_LEVEL.SetLevel(_level);

	Engine _engine;
	_engine.Start();

	return EXIT_SUCCESS;
}