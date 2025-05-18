#include "BulletMovementComponent.h"
#include "Actor.h"

BulletMovementComponent::BulletMovementComponent(AActor* _owner, const float _speed,
	const Vector2f& _direction)
	: UComponent(_owner)
{
	speed = _speed;
	direction = _direction;
}

BulletMovementComponent::BulletMovementComponent(AActor* _owner, const BulletMovementComponent* _other)
	: UComponent(_owner)
{
	speed = _other->speed;
	direction = _other->direction;
}

BulletMovementComponent::~BulletMovementComponent()
{
}

void BulletMovementComponent::Move(const float _deltaTime)
{
	const Vector2f& _offset = direction * speed * _deltaTime;
	owner->Move(_offset);
}

void BulletMovementComponent::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}