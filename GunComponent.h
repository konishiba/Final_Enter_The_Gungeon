#pragma once
#include "Component.h"
#include "SubclassOf.h"
#include "Bullet.h"
#include "GunData.h"

class GunComponent : public UComponent
{
	using Iterator = vector<Bullet*>::iterator;

	bool isInReload;
	SubclassOf<Bullet> bullet;
	vector<Bullet*> bullets;
	Iterator current;
	GunData* data;

public:
	FORCEINLINE void SetBulletRef(const Bullet& _ref)
	{
		bullet = _ref;
	}
	FORCEINLINE virtual UComponent* Clone(AActor* _owner) const
	{
		return new GunComponent(_owner, *this);
	}


public:
	GunComponent(AActor* _owner, GunData* _data, Bullet _bulletRef);
	GunComponent(AActor* _owner, const GunComponent& _other);

	virtual ~GunComponent();

public:
	virtual void BeginPlay() override;
	virtual void Shoot(const Vector2f& _direction, const Vector2f& _ownerSize);
	virtual void Reload();
	Vector2f ComputeFinalDirectionWithSpread(const int _index, const Vector2f& _direction, const float _principalAngle);
};

