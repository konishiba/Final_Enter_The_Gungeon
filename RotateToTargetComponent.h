#pragma once
#include "Component.h"
class RotateToTargetComponent : public UComponent
{
	bool hasLaunch;
	float endRotation;
	float smoothTime;
	float duration;
	float speed;
	Vector2f targetCoordinate;

public:
	FORCEINLINE void SetTargetPos(const Vector2f& _targetPos)
	{
		targetCoordinate = _targetPos;
	}

public:
	RotateToTargetComponent(AActor* _owner, const float _speed = 10.0f, const float _smoothTime = 0.15f);
	RotateToTargetComponent(AActor* _owner, const RotateToTargetComponent* _other);

private:
	Vector2f ComputeTargetDirection();
	float ComputeRotation();

public:
	void Launch();
	virtual UComponent* Clone(AActor* _owner) const;
	virtual void Tick(const float _deltaTime) override;
};

