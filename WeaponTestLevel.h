#pragma once
#include "Level.h"
#include "CUSTOMGameMode.h"

#include "CanvasWidget.h"
#include "LabelWidget.h"
#include "ImageWidget.h"

class WeaponTestlevel : public Level
{
	CanvasWidget* canvas;
	LabelWidget* label;
	ImageWidget* image;

public:
	FORCEINLINE virtual CUSTOMGameMode* GetGameModeRef() override
	{
		return new CUSTOMGameMode(this);
	}

public:
	WeaponTestlevel(const string& _name);

protected:
	virtual void InitLevel() override;
};

