#include "ETG_GameplayHud.h"
#include "Level.h"


ETG_GameplayHud::ETG_GameplayHud(Level* _level) : HUD(_level)
{
	mesh = _level->SpawnActor<AMeshActor>(CircleShapeData(10.0f));
	mesh->SetPosition(Vector2f(10.0f, 10.0f));
}

ETG_GameplayHud::ETG_GameplayHud(const ETG_GameplayHud& _other) : HUD(_other)
{
	mesh = _other.mesh;
}
