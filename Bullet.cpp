#include "Bullet.h"
#include "Actor.h"

Bullet::Bullet(Level* _level, const CircleShapeData& _data, const string& _name, const float _damage, const int _speed, const float _range, const Vector2f& _direction)

	: AMeshActor(_level, _data, _name)
{
	isFired = false;
	damage = _damage;
	speed = _speed * 10.0f;
	range = _range;

	movement = CreateDefaultSubobject<BulletMovementComponent>(speed, _direction);

}

Bullet::Bullet(const Bullet& _other) : AMeshActor(_other)
{
	isFired = _other.isFired;
	damage = _other.damage;
	speed = _other.speed;
	range = _other.range;
	movement = CreateDefaultSubobject<BulletMovementComponent>(_other.movement);
}


void Bullet::Launch()
{
	posInit = GetPosition();
	isFired = true;
	SetActive(true);
}

void Bullet::Construct()
{
	Super::Construct();
	//startPosition = GetPosition();
}

void Bullet::Deconstruct()
{
	Super::Deconstruct();
}

void Bullet::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	if (isFired)
	{
		if (range <= ComputeDistTraveled())
		{
			SetActive(false);
		}
	}
}