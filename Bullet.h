#pragma once
#include "MeshActor.h"
#include "BulletMovementComponent.h"
#include "CollisionComponent.h"

class Bullet : public AMeshActor
{
	bool isFired;
	int speed;

	float damage;
	int range;
	Vector2f posInit;
	BulletMovementComponent* movement;

public:
	FORCEINLINE int ComputeDistTraveled() const
	{
		const Vector2f& _currentPos = GetPosition();
		return CAST(int, sqrtf(powf(_currentPos.x - posInit.x, 2.0f) + powf(_currentPos.y - posInit.y, 2.0f)));
	}
	FORCEINLINE BulletMovementComponent* GetMovement()
	{
		return movement;
	}
	FORCEINLINE void SetDirection(const Vector2f& _direction)
	{
		movement->SetDirection(_direction);
	}
public:
	Bullet(Level* _level, const CircleShapeData& _data, const string& _name, const float _damage, const int _speed, const float _range, const Vector2f& _direction);

	Bullet(const Bullet& _other);


public:
	void Launch();
	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void Tick(const float _deltaTime) override;
};

