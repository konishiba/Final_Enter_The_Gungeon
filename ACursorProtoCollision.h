#pragma once
#include "MeshActor.h"


class UCollisionComponent;

class ACursorProtoCollision : public AMeshActor
{
	bool canMove;

	UCollisionComponent* collision;

public:
	FORCEINLINE void SetCanMove(const bool _value) { canMove = _value; }
public:

	ACursorProtoCollision(Level* _level, const RectangleShapeData& _data, const string& _name = "CursorProtoCollision");

public:
	virtual void BeginPlay();
	virtual void Tick(const float _deltatime);

	virtual void Init();

	virtual void CollisionEnter(const CollisionData& _data);
};

