#pragma once
#include "PlayerController.h"
class ETG_GameplayPlayerController : public PlayerController
{
public:
	ETG_GameplayPlayerController(Level* _level, const string& _name = "GameplayPlayerController");
	ETG_GameplayPlayerController(const ETG_GameplayPlayerController& _other);

public:
	virtual APawn* GetPawnRef() const override;
};

