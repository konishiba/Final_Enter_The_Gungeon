#pragma once
#include "Level.h"

class Proto_Map : public Level
{

public:
	Proto_Map(const string& _name);

protected:
	virtual void InitLevel();

public:
	virtual void Load();
	virtual void Unload();
};

