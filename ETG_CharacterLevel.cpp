#include "ETG_CharacterLevel.h"
#include "ETG_GameplayGamemode.h"
#include "ETG_GameplayHud.h"
#include "ETG_GameplayPlayerController.h"
#include "PlayerController.h"
ETG_CharacterLevel::ETG_CharacterLevel(const string& _name):Level(_name)
{


}

void ETG_CharacterLevel::InitLevel()
{
	Super::InitLevel();
	HUD* _hud = GetGameMode()->GetHUD();
}
