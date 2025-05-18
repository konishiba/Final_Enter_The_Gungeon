#include "Engine.h"
#include "LevelManager.h"
#include "CUSTOMLevel.h"
#include "ETG_CharacterLevel.h"

void InitConfig()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Logger::Reset();
	system("cls");
}

int main()
{
	InitConfig();
	ETG_CharacterLevel* _level = new ETG_CharacterLevel("TEST");
	//TESTLevel* _level = new TESTLevel("TESTLevel");
	Engine _engine;
	M_LEVEL.SetLevel(_level);

	_engine.Start();

	return EXIT_SUCCESS;
}