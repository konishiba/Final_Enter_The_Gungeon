#pragma once
#include "Level.h"
class WeaponTestLevel : public Level
{

public:
	WeaponTestLevel(const string& _name);

protected:
	virtual void InitLevel() override;
};

