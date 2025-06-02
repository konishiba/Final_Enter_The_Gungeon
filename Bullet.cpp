#include "Bullet.h"

Bullet::Bullet(Level* _level, const CircleShapeData& _data, const string& _name, const GunData* _gunData)
	: AMeshActor(_level, _data, _name)
{
	isFired = false;
	damage = _gunData->damage;
	speed = _gunData->shotSpeed * 10.0f;
	range = _gunData->range * 10.0f;
	movement = CreateDefaultSubobject<BulletMovementComponent>(speed, Vector2f());
	SetLayerType(PROJECTILE);
	//collision->SetInformation("Bullet", InteractStatus::IS_ALL, CT_OVERLAP, false);
}

Bullet::Bullet(Level* _level, const Bullet& _other) : AMeshActor(_other)
{
	isFired = _other.isFired;
	damage = _other.damage;
	speed = _other.speed;
	range = _other.range;
	movement = CreateDefaultSubobject<BulletMovementComponent>(*_other.movement);
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
			//TODO changer cette merde
			SetPosition({ 1000000,1000000 });
			SetActive(false);
		}
	}

}