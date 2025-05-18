#pragma once
#include "MeshActor.h"
#include "Rarity.h"
#include "GunData.h"
#include "GunComponent.h"

class Gun : AMeshActor
{
protected:
	GunComponent* gunComponent;
	Rarity rarity;
	GunData* data;

public:
	FORCEINLINE GunComponent* GetGunComponent() const
	{
		return gunComponent;
	}


public:
	Gun(Level* _level, const RectangleShapeData& _shapeData, const string& _name, const Rarity& _rarity, GunData* _data = new GunData());
	Gun(const Gun& _other);

	virtual ~Gun();

public:
	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void Shoot() = 0;
	virtual void Reload() = 0;
};

