#pragma once

struct GunData
{
	int magazineSize;
	//if ammoCapacity == -1 infinite ammo
	int ammoCapacityMax;
	int currentAmmoCapity;
	int damage;
	float fireRate;
	float reloadTime;
	int shotSpeed;
	int range;
	int force;
	int spread;


	GunData() = default;
	GunData(const int _magazineSize, const int _ammoCapacityMax, const int _currentAmmoCapity, const int _damage,
		const float _fireRate, const float _reloadTime, const int _shotSpeed,
		const int _range, const int _force, const int _spread)
	{
		magazineSize = _magazineSize;
		ammoCapacityMax = _ammoCapacityMax;
		currentAmmoCapity = _currentAmmoCapity;
		damage = _damage;
		fireRate = _fireRate;
		reloadTime = _reloadTime;
		shotSpeed = _shotSpeed;
		range = _range;
		force = _force;
		spread = _spread;
	}

};