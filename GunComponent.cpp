#include "GunComponent.h"
#include "Bullet.h"
#include "Level.h"
#include "TimerManager.h"

GunComponent::GunComponent(AActor* _owner, GunData* _data)
	: UComponent(_owner)
{
	data = _data;

}

GunComponent::GunComponent(AActor* _owner, const GunComponent* _other) : UComponent(_owner)
{
	data = _other->data;
}

GunComponent::~GunComponent()
{
}

void GunComponent::BeginPlay()
{
	for (int _index = 0; _index < data->magazineSize; _index++)
	{
		Level* _currentLevel = owner->GetLevel();
		Bullet* _bullet = _currentLevel->SpawnActor(bullet);
		_bullet->SetActive(false);
		bullets.push_back(_bullet);
	}
	current = bullets.begin();
	isInReload = false;
}

void GunComponent::Shoot(const Vector2f& _direction)
{
	Bullet* _currentBullet = (*current);
	if (_currentBullet->IsActive() == false && isInReload == false)
	{
		_currentBullet->SetPosition(owner->GetPosition());
		_currentBullet->SetDirection(_direction);
		_currentBullet->Launch();
	}
	if (current == bullets.end() - 1)
	{
		isInReload = true;
	}
	if (bullets.size() == 1) return;
	current++;
}

void GunComponent::Reload()
{
	new Timer([&]()
		{
			current = bullets.begin();
			isInReload = false;
		}, seconds(data->reloadTime), true, false);
}