#include "GunComponent.h"
#include "Bullet.h"
#include "Level.h"
#include "LevelManager.h"
#include "TimerManager.h"

GunComponent::GunComponent(AActor* _owner, GunData* _data)
	: UComponent(_owner)
{
	data = _data;
	isInReload = false;
	data->magazineSize *= data->bulletPerShoot;
}
GunComponent::GunComponent(AActor* _owner, const GunComponent& _other) : UComponent(_owner)
{
	data = _other.data;
	isInReload = _other.isInReload;
}

GunComponent::~GunComponent()
{
}

void GunComponent::BeginPlay()
{
	for (int _index = 0; _index < data->magazineSize; _index++)
	{
		Level* _currentLevel = owner->GetLevel();
		Bullet* _bullet = _currentLevel->SpawnActor<Bullet>(CircleShapeData(5.0f, "Ball"), "Balle", data);
		_bullet->SetActive(false);
		bullets.push_back(_bullet);
	}
	current = bullets.begin();
	isInReload = false;
}

void GunComponent::Shoot(const Vector2f& _direction, const Vector2f& _ownerSize, const Vector2f& _spawnPosition)
{
	float _principalAngle = atan2(_direction.x, _direction.y);

	for (int _i = 0; _i < data->bulletPerShoot; _i++)
	{
		Bullet* _currentBullet = (*current);

		if (!_currentBullet->IsActive() && !isInReload)
		{
			Vector2f _finalDirection = _direction;

			if (data->bulletPerShoot > 1)
			{
				_finalDirection = ComputeFinalDirectionWithSpread(_i, _direction, _principalAngle);
			}
			_currentBullet->SetPosition(_spawnPosition);
			_currentBullet->SetDirection(_finalDirection);
			_currentBullet->Launch();
		}
		if (current == bullets.end() - 1)
		{
			isInReload = true;
			return;
		}
		current++;
	}
}

void GunComponent::Reload()
{
	new Timer([&]()
		{
			current = bullets.begin();
			isInReload = false;
		}, seconds(data->reloadTime), true, false);
}


Vector2f GunComponent::ComputeFinalDirectionWithSpread(const int _index, const Vector2f& _direction, const float _principalAngle)
{
	float _facteur = (_index - (data->bulletPerShoot - 1) / 2.0f);
	float _angleOffset = (_facteur * data->spread / (data->bulletPerShoot - 1)) * (3.14159265f / 180.0f);

	float _finalAngle = _principalAngle + _angleOffset;

	const Vector2f& _finalDirection = { _direction.x * cos(_angleOffset) - _direction.y * sin(_angleOffset),
		_direction.x * sin(_angleOffset) + _direction.y * cos(_angleOffset) };

	return _finalDirection;
}