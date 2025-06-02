#include "Engine.h"
#include "LevelManager.h"
#include "LVL_ProtoCollision.h"
#include "Proto_Map.h"
#include "ETG_CharacterLevel.h"
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

	//Proto_Map* _level = new Proto_Map("mapTest");

	//WeaponTestlevel* _level = new WeaponTestlevel("LevelTestWeapon");

	ETG_CharacterLevel* _level = new ETG_CharacterLevel("ETG_CharacterLevel");

	M_LEVEL.SetLevel(_level);

	Engine _engine;
	_engine.Start();

	return EXIT_SUCCESS;
}