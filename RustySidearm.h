#pragma once
#include "Gun.h"
#include "GunComponent.h"

class RustySidearm : public Gun
{
	bool canShoot;

public:
	FORCEINLINE GunComponent* GetGunComponent() const
	{
		return gunComponent;
	}

public:
	RustySidearm(Level* _level);
	RustySidearm(const RustySidearm& _other);

public:
	virtual void Construct() override;
	virtual void Deconstruct() override;
	virtual void Shoot() override;
	virtual void Reload() override;

private:
	void SetupInput();

};


