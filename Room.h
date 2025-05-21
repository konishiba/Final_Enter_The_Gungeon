#pragma once
#include "Actor.h"

class UStaticMeshComponent;
class RectangleShapeData;

class Room : public AActor
{
	//UStaticMeshComponent* mesh = nullptr;
	//UStaticMeshComponent* secondMesh = nullptr;

	map<UStaticMeshComponent*, Vector2f> meshInRoom = {};

public:

	Room(Level* _level, const string& _name = "Room", const TransformData& _transform = TransformData());

protected:
	void UpdateMeshPos(const Vector2f& _roomPos);
	void SpawnMeshRoom(const RectangleShapeData& _data, const Vector2f& _pos);
	void Init();
public:

	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;

};

