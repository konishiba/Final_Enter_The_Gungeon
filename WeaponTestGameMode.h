#pragma once
#include "GameMode.h"
#include "Level.h"
#include "CUSTOMPlayerController.h"
#include "CUSTOMHUD.h"

class WeaponTestGameMode : public GameMode
{
public:
	FORCEINLINE virtual CUSTOMPlayerController* GetPlayerControllerRef() override
	{
		return new CUSTOMPlayerController(GetLevel());
	}
	FORCEINLINE virtual CUSTOMHUD* GetHUDRef() override
	{
		return new CUSTOMHUD(GetLevel());
	}
public:
	WeaponTestGameMode(Level* _level, const string& _name = "GameModeWeapon");
	WeaponTestGameMode(const WeaponTestGameMode& _other);


};

