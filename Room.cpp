#include "Room.h"
#include "StaticMeshComponent.h"

Room::Room(Level* _level, const string& _name, const TransformData& _transform) : AActor(_level, _name, _transform)
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(RectangleShapeData({ 50.0f,50.0f }));
	secondMesh = CreateDefaultSubobject<UStaticMeshComponent>(RectangleShapeData({ 100.0f,50.0f }));
}

void Room::Construct()
{
	Super::Construct();

	mesh->SetupAttachment(root);
	secondMesh->SetupAttachment(root);

	mesh->GetShape()->SetPosition({ 0.0f,0.0f });
	secondMesh->GetShape()->SetPosition({ 50.0f,50.0f });
}

void Room::Deconstruct()
{
	Super::Deconstruct();
}

void Room::BeginPlay()
{
	Super::BeginPlay();
}

void Room::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
}

void Room::BeginDestroy()
{
	Super::BeginDestroy();
}
