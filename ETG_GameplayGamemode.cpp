#include "ETG_GameplayGamemode.h"
#include "Level.h"

ETG_GameplayGamemode::ETG_GameplayGamemode(Level* _level, const string& _name) : GameMode(_level, _name)
{

}

ETG_GameplayGamemode::ETG_GameplayGamemode(const ETG_GameplayGamemode& _other) : GameMode(_other)
{

}
