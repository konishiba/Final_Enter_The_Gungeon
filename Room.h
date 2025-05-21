#pragma once
#include "Actor.h"

class UStaticMeshComponent;

class Room : public AActor
{
	UStaticMeshComponent* mesh = nullptr;
	UStaticMeshComponent* secondMesh = nullptr;

public:

	Room(Level* _level, const string& _name = "Room", const TransformData& _transform = TransformData());

public:

	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;
};

