#pragma once
#include "Level.h"
#include "ETG_GameplayGameMode.h"


class ETG_CharacterLevel : public Level
{
	ETG_CharacterPawn* player;
public:
	FORCEINLINE virtual ETG_GameplayGamemode* GetGameModeRef() override
	{
		return new ETG_GameplayGamemode(this);
	}

public:
	ETG_CharacterLevel(const string& _name);

protected:
	virtual void InitLevel() override;
};

