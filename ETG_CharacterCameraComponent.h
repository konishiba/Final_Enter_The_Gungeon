#pragma once
#include "CameraComponent.h"
namespace Camera
{
	class ETG_CharacterCameraComponent : public UCameraComponent
	{
		Vector2f mousePos;
		Vector2f targetPos;
		Vector2f refVel;
		float smoothTime;
		float maxRange;
		float minRange;

	public:
		FORCEINLINE void CaptureMousePos(const Vector2f& _mousePos)
		{
			mousePos = _mousePos;
		}

	public:
		ETG_CharacterCameraComponent(AActor* _owner);
		ETG_CharacterCameraComponent(AActor* _owner, const ETG_CharacterCameraComponent& _other);


	private:
		void ComputeCameraPos(const float _deltaTime);
		Vector2f UpdateTargetPos();
		void UpdateCameraPosition(const float _delta);

	public:
		virtual void Tick(const float _deltaTime) override;
		virtual UComponent* Clone(AActor* _owner) const;
	};
}

