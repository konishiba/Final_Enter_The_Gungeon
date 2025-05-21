#pragma once
#include "Component.h"
#include "ETG_MovementComponent.h"
class ETG_PlayerMovementComponent : public ETG_MovementComponent
{
	bool canMove;
	float dodgeMultiplicater;
	bool isOnDodge;

public:
	ETG_PlayerMovementComponent(AActor* _owner);
	ETG_PlayerMovementComponent(AActor* _owner, const ETG_PlayerMovementComponent& _other);

public:
	FORCEINLINE bool IsLaunch()
	{
		return isOnDodge;
	}
	FORCEINLINE void SetIsOnDodgetate(const bool _state)
	{
		isOnDodge = _state;

	}
	FORCEINLINE void Reset()
	{
		speed = 100.f;
		canMove = false;
		direction = Vector2f();

	}
	FORCEINLINE void SetCanMoveState(const bool _state)
	{
		canMove = _state;
	}
	virtual FORCEINLINE void ResetX()
	{
		direction.x = 0;
	}
	virtual FORCEINLINE void ResetY()
	{
		direction.y = 0;
	}
	FORCEINLINE void SetSpeed(const float _speed)
	{
		speed = _speed;
	}
	FORCEINLINE bool IsAxisNormalise(const float _axis)
	{
		return _axis <= 1.0f && _axis >= -1.0f;
	}
	FORCEINLINE bool IsVector2fNormalise(const Vector2f& _vectorDirection)
	{
		return IsAxisNormalise(_vectorDirection.x) && IsAxisNormalise(_vectorDirection.y);
	}
	FORCEINLINE bool IsVector2fNull(const Vector2f& _vectorDirection)
	{
		return _vectorDirection.x == 0.0f && _vectorDirection.y == 0.0f;
	}

protected:
	virtual void Move(const float _deltaTime);
public:
	virtual void Dodge();
	virtual void ProcessInput(const Vector2f& _inputOffSet);
	virtual UComponent* Clone(AActor* _owner) const override;

};

