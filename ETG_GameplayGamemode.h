#pragma once
#include "GameMode.h"
#include "ETG_GameplayPlayerController.h"
#include "ETG_GameplayHud.h"
#include "CUSTOMHUD.h"

class ETG_GameplayGamemode : public GameMode
{
public:
	FORCEINLINE virtual ETG_GameplayPlayerController* GetPlayerControllerRef() override
	{
		return new ETG_GameplayPlayerController(GetLevel());
	}

	FORCEINLINE virtual ETG_GameplayHud* GetHUDRef() override
	{
		return new ETG_GameplayHud(GetLevel());
	}
	 

public:
	ETG_GameplayGamemode(Level* _level, const string& _name = "GameMode");
	ETG_GameplayGamemode(const ETG_GameplayGamemode& _other);
};

