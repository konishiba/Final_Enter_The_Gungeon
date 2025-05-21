#include "ETG_MovementComponent.h"
#include "Actor.h"

ETG_MovementComponent::ETG_MovementComponent(AActor* _owner) : UComponent(_owner)
{
	speed = 100.f;
	direction = Vector2f();
}

ETG_MovementComponent::ETG_MovementComponent(AActor* _owner, const ETG_MovementComponent& _other) : UComponent(_owner, _other)
{
	speed = _other.speed;
	direction = _other.direction;
}

void ETG_MovementComponent::Move(const float _deltaTime)
{
	const Vector2f& _offset = direction * speed * _deltaTime;
	owner->Move(_offset);
}


void ETG_MovementComponent::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}

UComponent* ETG_MovementComponent::Clone(AActor* _owner) const
{
	return new ETG_MovementComponent(_owner, *this);
}