#pragma once
#include "Pawn.h"
#include "StaticMeshComponent.h"
#include "CameraComponent.h"
#include "ETG_PlayerMovementComponent.h"
#include "ETG_CharacterCameraComponent.h"

class ETG_CharacterPawn : public APawn
{
	UStaticMeshComponent* mesh;
	ETG_PlayerMovementComponent* movement;
	Camera::ETG_CharacterCameraComponent* camera;
public:
	ETG_CharacterPawn(Level* _level, const string& _name = " PlayerPawn");
	ETG_CharacterPawn(const ETG_CharacterPawn& _other);

protected:
	virtual void SetupInputController(Input::InputManager& _inputManager) override;
	virtual void BeginPlay() override;
	void Init();
};

