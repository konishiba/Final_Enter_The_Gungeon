#include "ETG_CharacterCameraComponent.h"
#include "Actor.h"
#include "CameraManager.h"
#include "Level.h"

Camera::ETG_CharacterCameraComponent::ETG_CharacterCameraComponent(AActor* _owner) : UCameraComponent(_owner)
{
	smoothTime = 0.15f;
	mousePos = Vector2f();
	refVel = Vector2f();
	maxRange = 200;
	minRange = -200;
}

Camera::ETG_CharacterCameraComponent::ETG_CharacterCameraComponent(AActor* _owner, const ETG_CharacterCameraComponent& _other) : UCameraComponent(_owner, _other)
{
	mousePos = _other.mousePos;
	smoothTime = _other.smoothTime;
	maxRange = _other.maxRange;
	minRange = _other.minRange;
}

Vector2f Camera::ETG_CharacterCameraComponent::UpdateTargetPos()
{
	const Vector2f& _childPos = owner->GetPosition();
	Vector2f _ret = Vector2f(mousePos - _childPos) / 2.5f;
	_ret.x = clamp(_ret.x, minRange, maxRange);
	_ret.y = clamp(_ret.y, minRange / 2.0f, maxRange / 2.0f);
	return _ret;
}

void Camera::ETG_CharacterCameraComponent::UpdateCameraPosition(const float _delta)
{
	const Vector2f& _tempVector = SmoothDamp(view->getCenter(), owner->GetPosition() + targetPos,
		refVel, smoothTime, _delta);
	view->setCenter(_tempVector);
}

void Camera::ETG_CharacterCameraComponent::Tick(const float _deltaTime)
{
	ComputeCameraPos(_deltaTime);

}

UComponent* Camera::ETG_CharacterCameraComponent::Clone(AActor* _owner) const
{
	return nullptr;
}

void Camera::ETG_CharacterCameraComponent::ComputeCameraPos(const float _deltaTime)
{
	CaptureMousePos(owner->GetLevel()->GetPixelTooCoords());
	targetPos = UpdateTargetPos();
	UpdateCameraPosition(_deltaTime);
}
