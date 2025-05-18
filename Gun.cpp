#include "Gun.h"


Gun::Gun(Level* _level, const RectangleShapeData& _shapeData, const string& _name, const Rarity& _rarity, GunData* _data) : AMeshActor(_level, _shapeData)
{
}

Gun::Gun(const Gun& _other) : AMeshActor(_other)
{
	rarity = _other.rarity;
	gunComponent = CreateDefaultSubobject<GunComponent>(_other.data);
}

Gun::~Gun()
{
	delete data;
}

void Gun::Construct()
{
	Super::Construct();
}

void Gun::Deconstruct()
{
	Super::Deconstruct();
}
