#pragma once
#include "Component.h"
class BulletMovementComponent : public UComponent
{
protected:
	float speed;
	Vector2f direction;

public:


	FORCEINLINE float GetSpeed() const
	{
		return speed;
	}
	FORCEINLINE void SetSpeed(const float _speed)
	{
		speed = _speed;
	}
	FORCEINLINE void SetDirection(Vector2f _direction)
	{
		direction = _direction;
	}
	FORCEINLINE Vector2f GetDiretion() const
	{
		return direction;
	}
	FORCEINLINE bool IsDirectionNull() const
	{
		return direction == Vector2f();
	}
	FORCEINLINE virtual UComponent* Clone(AActor* _owner) const
	{
		return new BulletMovementComponent(_owner, *this);
	}
public:
	BulletMovementComponent(AActor* _owner, const float _speed = 10.0f,
		const Vector2f& _direction = Vector2f());

	BulletMovementComponent(AActor* _owner, const BulletMovementComponent& _other);

	virtual ~BulletMovementComponent();

protected:
	virtual void Move(const float _deltaTime);
public:
	virtual void Tick(const float _deltaTime);
};

