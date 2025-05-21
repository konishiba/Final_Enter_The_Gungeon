#pragma once
#include "Component.h"
class ETG_MovementComponent : public UComponent
{
protected:
	float speed;
	Vector2f direction;

public:
	FORCEINLINE void SetDirection(const Vector2f& _direction)
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

public:
	ETG_MovementComponent(AActor* _owner);
	ETG_MovementComponent(AActor* _owner, const ETG_MovementComponent& _other);

protected:
	virtual void Move(const float _deltaTime);
public:
	virtual void Tick(const float _deltaTime) override;
	virtual UComponent* Clone(AActor* _owner) const;
};

