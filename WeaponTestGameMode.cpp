#include "WeaponTestGameMode.h"

WeaponTestGameMode::WeaponTestGameMode(Level* _level, const string& _name) : GameMode(_level, _name)
{
}

WeaponTestGameMode::WeaponTestGameMode(const WeaponTestGameMode& _other) : GameMode(_other)
{
}
