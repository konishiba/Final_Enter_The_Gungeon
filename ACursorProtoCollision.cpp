#include "ACursorProtoCollision.h"
#include "Level.h"
#include "GameMode.h"
#include "PlayerController.h"
#include "CollisionComponent.h"

ACursorProtoCollision::ACursorProtoCollision(Level* _level, const RectangleShapeData& _data, const string& _name)
					 : AMeshActor(_level, _data, _name)
{
	collision = CreateDefaultSubobject<UCollisionComponent>();
	collision->SetInformation("test", IS_ALL, CT_OVERLAP);
	AddComponent(collision);
}

void ACursorProtoCollision::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void ACursorProtoCollision::Tick(const float _deltatime)
{
	Super::Tick(_deltatime);
	if (!canMove)return;
	const Vector2i& _pixelPos = Mouse::getPosition(GetLevel()->GetRenderWindow());
	const Vector2f& _pixelToCoords = GetLevel()->GetRenderWindow().mapPixelToCoords(_pixelPos, *GetLevel()->GetCameraManager().GetCurrent()->GetView());
	//const Vector2f& _coord = GetLevel()->GetGameMode()->GetPlayerController()->GetPixelToCoords();
	//SetPosition(Vector2f(Mouse::getPosition()));
	SetPosition(_pixelToCoords);
}

void ACursorProtoCollision::Init()
{
	canMove = true;
	collision->AddResponses({{"test", CT_OVERLAP}});
	GetMesh()->GetShape()->GetDrawable()->setFillColor(sf::Color::Cyan);
}

void ACursorProtoCollision::CollisionEnter(const CollisionData& _data)
{
	Super::CollisionEnter(_data);
	LOG(Display, "collisionEnter");
}
