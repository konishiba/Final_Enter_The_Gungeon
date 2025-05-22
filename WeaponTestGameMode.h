#pragma once
#include "GameMode.h"
#include "Level.h"

class WeaponTestGameMode : public GameMode
{

public:
	WeaponTestGameMode(Level* _level, const string& _name = "GameModeWeapon");
	WeaponTestGameMode(const WeaponTestGameMode& _other);


};

