#pragma once

struct GunData
{
	int magazineSize;
	//if ammoCapacity == -1 infinite ammo
	int maxAmmo;
	int currentAmmo;
	int damage;
	float fireRate;
	float reloadTime;
	int shotSpeed;
	int range;
	int force;
	int spread;
	int bulletPerShoot;


	GunData() = default;
	GunData(const int _magazineSize, const int _maxAmmo, const int _currentAmmo, const int _damage,
		const float _fireRate, const float _reloadTime, const int _shotSpeed,
		const int _range, const int _force, const int _spread, const int _bulletPerShoot)
	{
		magazineSize = _magazineSize;
		maxAmmo = _maxAmmo;
		currentAmmo = _currentAmmo;
		damage = _damage;
		fireRate = _fireRate;
		reloadTime = _reloadTime;
		shotSpeed = _shotSpeed;
		range = _range;
		force = _force;
		spread = _spread;
		bulletPerShoot = _bulletPerShoot;
	}

};