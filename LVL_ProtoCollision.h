#pragma once
#include "Level.h"
#include "CUSTOMGameMode.h"

#include "CanvasWidget.h"
#include "LabelWidget.h"
#include "ImageWidget.h"

class ACursorProtoCollision;
//class ACameraActor;

class LVL_ProtoCollision : public Level
{
	CanvasWidget* canvas;
	LabelWidget* label;
	ImageWidget* image;

	ACursorProtoCollision* cursor;

public:
	FORCEINLINE virtual CUSTOMGameMode* GetGameModeRef() override
	{
		return new CUSTOMGameMode(this);
	}

public:
	LVL_ProtoCollision(const string& _name);

protected:
	virtual void InitLevel() override;

};