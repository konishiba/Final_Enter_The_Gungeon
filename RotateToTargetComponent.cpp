#include "RotateToTargetComponent.h"
#include "Actor.h"


RotateToTargetComponent::RotateToTargetComponent(AActor* _owner, const float _speed, const float _smoothTime)
	:UComponent(_owner)
{
	hasLaunch = false;
	endRotation = 0.0f;
	duration = 0.0f;
	targetCoordinate = { 0.0f, 0.0f };

	smoothTime = _smoothTime;
	speed = _speed;
}

RotateToTargetComponent::RotateToTargetComponent(AActor* _owner, const RotateToTargetComponent* _other)
	:UComponent(*_other)
{
	hasLaunch = _other->hasLaunch;
	endRotation = _other->endRotation;
	duration = _other->duration;
	targetCoordinate = _other->targetCoordinate;

	smoothTime = _other->smoothTime;
	speed = _other->speed;
}

UComponent* RotateToTargetComponent::Clone(AActor* _owner) const
{
	return new RotateToTargetComponent(_owner, this);
}

void RotateToTargetComponent::Tick(const float _deltaTime)
{
	if (hasLaunch)
	{
		owner->SetRotation(radians(endRotation));
	}
}

void RotateToTargetComponent::Launch()
{
	duration = 0.0f;
	const Vector2f& _vector = owner->GetForwardVector();
	const float _atan = atan2f(_vector.y, _vector.x);
	endRotation = ComputeRotation();
	hasLaunch = true;
}

Vector2f RotateToTargetComponent::ComputeTargetDirection()
{
	const Vector2f& _ownerCoords = owner->GetPosition();
	const float _x = targetCoordinate.x - _ownerCoords.x;
	const float _y = targetCoordinate.y - _ownerCoords.y;
	return { _x, _y };
}

float RotateToTargetComponent::ComputeRotation()
{
	const Vector2f& _vector = ComputeTargetDirection().normalized();
	const float _atan = atan2f(_vector.y, _vector.x);
	return _atan;
}