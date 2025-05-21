#include "ETG_PlayerMovementComponent.h"
#include "PlayerController.h"
#include "TimerManager.h"

ETG_PlayerMovementComponent::ETG_PlayerMovementComponent(AActor* _owner) :ETG_MovementComponent(_owner)
{
	canMove = false;
	isOnDodge = false;
	dodgeMultiplicater = 1.5f;
}

ETG_PlayerMovementComponent::ETG_PlayerMovementComponent(AActor* _owner, const ETG_PlayerMovementComponent& _other) : ETG_MovementComponent(_owner, _other)
{
	canMove = _other.canMove;
	isOnDodge = _other.isOnDodge;
	dodgeMultiplicater = _other.dodgeMultiplicater;
}

void ETG_PlayerMovementComponent::Move(const float _deltaTime)
{
	if (canMove)
	{
		Super::Move(_deltaTime);
	}
	if (isOnDodge)
	{
		const Vector2f& _offset = direction * speed * _deltaTime * dodgeMultiplicater;
		owner->Move(_offset);
	}
}

void ETG_PlayerMovementComponent::Dodge()
{
	if (!isOnDodge && !IsDirectionNull())
	{
		isOnDodge = true;
		canMove = false;
		speed = speed * dodgeMultiplicater;
		new Timer([&]()
			{
				isOnDodge = false;
				canMove = true;
				Reset();
				LOG(Warning, "DODGE END");
			}, seconds(0.7f), true, false);
	}
}

void ETG_PlayerMovementComponent::ProcessInput(const Vector2f& _inputOffSet)
{
	if (isOnDodge)return;
	direction += _inputOffSet;

	direction.x = direction.x < -1.0f ? -1.0f : direction.x;
	direction.x = direction.x > 1.0f ? 1.0f : direction.x;

	direction.y = direction.y < -1.0f ? -1.0f : direction.y;
	direction.y = direction.y > 1.0f ? 1.0f : direction.y;

	if (!IsVector2fNull(direction))
	{
		direction = direction.normalized();
	} 

	canMove = true;
}

UComponent* ETG_PlayerMovementComponent::Clone(AActor* _owner) const
{
	return new ETG_PlayerMovementComponent(_owner, *this);
}


