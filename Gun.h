#pragma once
#include "MeshActor.h"
#include "Rarity.h"
#include "GunData.h"
#include "GunComponent.h"
#include "InputManager.h"

class Gun : public AMeshActor
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
	virtual void Tick(const float _deltaTime) override;
	virtual void Shoot() = 0;
	virtual void Reload() = 0;
	virtual void SetupInputController(Input::InputManager& _inputManager);
};

