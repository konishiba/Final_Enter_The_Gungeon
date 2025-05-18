#pragma once

#include "HUD.h"
#include "MeshActor.h"
using namespace UI;

class ETG_GameplayHud : public HUD
{
public:
	ETG_GameplayHud(Level* _level);
	ETG_GameplayHud(const ETG_GameplayHud& _other);
};

