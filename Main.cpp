#include "Engine.h"
#include "LevelManager.h"
#include "WeaponTestLevel.h"
#include "CUSTOMLevel.h"

void InitConfig()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Logger::Reset();
	system("cls");
}

int main()
{
	InitConfig();

	WeaponTestlevel* _level = new WeaponTestlevel("LevelTestWeapon");
	M_LEVEL.SetLevel(_level);

	Engine _engine;
	_engine.Start();

	return EXIT_SUCCESS;
}