#include "ETG_GameplayPlayerController.h"
#include "ETG_CharacterPawn.h"

ETG_GameplayPlayerController::ETG_GameplayPlayerController(Level* _level, const string& _name) :PlayerController(_level, _name)
{
}

ETG_GameplayPlayerController::ETG_GameplayPlayerController(const ETG_GameplayPlayerController& _other) :PlayerController(_other)
{
}

APawn* ETG_GameplayPlayerController::GetPawnRef() const
{
	return new ETG_CharacterPawn(level);
}
