#include "Room.h"
#include "StaticMeshComponent.h"

Room::Room(Level* _level, const string& _name, const TransformData& _transform) : AActor(_level, _name, _transform)
{
	//mesh = CreateDefaultSubobject<UStaticMeshComponent>(RectangleShapeData({ 50.0f,100.0f }));
	//secondMesh = CreateDefaultSubobject<UStaticMeshComponent>(RectangleShapeData({ 100.0f,50.0f }));
}

void Room::UpdateMeshPos(const Vector2f& _roomPos)
{
	for (pair<UStaticMeshComponent*,Vector2f> _meshAndPos : meshInRoom)
	{
		_meshAndPos.first->GetShape()->SetPosition(_roomPos + _meshAndPos.second);
	}
}

void Room::SpawnMeshRoom(const RectangleShapeData& _data, const Vector2f& _pos)
{
	//UStaticMeshComponent* _mesh = CreateDefaultSubobject<UStaticMeshComponent>(_data);
	pair<UStaticMeshComponent*, Vector2f> _pair = { CreateDefaultSubobject<UStaticMeshComponent>(_data),_pos };
	_pair.first->SetupAttachment(root);
	meshInRoom.insert(_pair);
	//meshInRoom[_mesh] = _pos;
	//_mesh->SetupAttachment(root);
}

void Room::Init()
{
	SpawnMeshRoom(RectangleShapeData({ 50.0f,100.0f }), Vector2f{ 0.0f,0.0f });
	SpawnMeshRoom(RectangleShapeData({ 100.0f,50.0f }), Vector2f{ 50,50.0f });
}

void Room::Construct()
{
	Super::Construct();

	//mesh->SetupAttachment(root);
	//secondMesh->SetupAttachment(root);

	//mesh->GetShape()->SetPosition(GetPosition() + Vector2f{ 0.0f,0.0f });
	//secondMesh->GetShape()->SetPosition(GetPosition() + Vector2f{ 200.0f,200.0f });
}

void Room::Deconstruct()
{
	Super::Deconstruct();
}

void Room::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void Room::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	UpdateMeshPos(GetPosition());
	//mesh->GetShape()->SetPosition(GetPosition() + Vector2f{ 0.0f,0.0f });
	//secondMesh->GetShape()->SetPosition(GetPosition() + Vector2f{ 10.0f,130.0f });
}

void Room::BeginDestroy()
{
	Super::BeginDestroy();
}
