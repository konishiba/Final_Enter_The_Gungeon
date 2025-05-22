#include "Gun.h"


Gun::Gun(Level* _level, const RectangleShapeData& _shapeData, const string& _name, const Rarity& _rarity, GunData* _data) : AMeshActor(_level, _shapeData)
{
	SetScale({ 2.f,2.f });
	rarity = _rarity;
	data = _data;
	gunComponent = CreateDefaultSubobject<GunComponent>(data);
}

Gun::Gun(const Gun& _other) : AMeshActor(_other)
{
	rarity = _other.rarity;
	data = _other.data;
	gunComponent = CreateDefaultSubobject<GunComponent>(_other.gunComponent);
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

void Gun::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

}

void Gun::Shoot()
{
}

void Gun::Reload()
{
}

void Gun::SetupInputController(Input::InputManager& _inputManager)
{
}
