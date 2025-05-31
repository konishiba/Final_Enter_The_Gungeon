#include "Gun.h"
#include "LevelManager.h"


Gun::Gun(Level* _level, const RectangleShapeData& _shapeData, const string& _name, const Rarity& _rarity, GunData* _data) : AMeshActor(_level, _shapeData)
{
	SetScale({ 2.f,2.f });
	rarity = _rarity;
	data = _data;
	rotate = CreateDefaultSubobject<RotateToTargetComponent>();
	gunComponent = CreateDefaultSubobject<GunComponent>(data);
}

Gun::Gun(const Gun& _other) : AMeshActor(_other)
{
	rarity = _other.rarity;
	data = _other.data;
	gunComponent = CreateDefaultSubobject<GunComponent>(*_other.gunComponent);
	rotate = CreateDefaultSubobject<RotateToTargetComponent>();
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
	const RenderWindow& _window = M_LEVEL.GetCurrentLevel()->GetRenderWindow();
	const Vector2i& _pixelPos = Mouse::getPosition(_window);
	const Vector2f& _pixelToCoords = _window.mapPixelToCoords(_pixelPos, *M_LEVEL.GetCurrentLevel()->GetCameraManager().GetCurrent()->GetView());
	rotate->SetTargetPos(_pixelToCoords);
	rotate->Launch();
}