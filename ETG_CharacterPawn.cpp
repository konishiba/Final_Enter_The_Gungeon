#include "ETG_CharacterPawn.h"
#include "Level.h"
#include "InputManager.h"
using namespace Input;

ETG_CharacterPawn::ETG_CharacterPawn(Level* _level, const string& _name) : APawn(_level, _name)
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(RectangleShapeData(Vector2f(50.0f, 50.0f)));
	camera = CreateDefaultSubobject<UCameraComponent>(_level->GetWindowSize() / 2.0f, _level->GetWindowSize());
	movement = CreateDefaultSubobject<ETG_PlayerMovementComponent>();
	_level->GetCameraManager().Register(camera);

	mesh->SetupAttachment(root);
}

ETG_CharacterPawn::ETG_CharacterPawn(const ETG_CharacterPawn& _other) :APawn(_other)
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(*_other.mesh);
	camera = CreateDefaultSubobject<UCameraComponent>(*_other.camera);
	movement = CreateDefaultSubobject<ETG_PlayerMovementComponent>(*_other.movement);
}

void ETG_CharacterPawn::SetupInputController(Input::InputManager& _inputManager)
{
	ActionMap* _moveInputs = _inputManager.CreateActionMap("PlayerMovement");

	_moveInputs->AddActions(
		{
			new Action("Up", ActionData(KeyHold, Z), [&]()
			{
				movement->ProcessInput(Vector2f(0.f,-1.0f));
			}),
			new Action("UpRelease", ActionData(KeyReleased, Z), [&]()
			{
				movement->Reset();
			}),

			new Action("Down", ActionData(KeyHold, S), [&]()
			{
				movement->ProcessInput(Vector2f(0.f, 1.0f));
			}),
			new Action("DownRelease", ActionData(KeyReleased, S), [&]()
			{
				movement->Reset();
			}),

			new Action("Left", ActionData(KeyHold, Q), [&]()
			{
				movement->ProcessInput(Vector2f(-1.f, 0.f));
			}),
			new Action("LeftRelease", ActionData(KeyReleased, Q), [&]()
			{
				movement->Reset();
			}),

			new Action("Right", ActionData(KeyHold, D), [&]()
			{
				movement->ProcessInput(Vector2f(1.f, 0.f));
			}),
			new Action("RightRelease", ActionData(KeyReleased, D), [&]()
			{
				movement->Reset();
			}),

			new Action("Dodge", ActionData(KeyHold, Space), [&]()
			{
				movement->Dodge();
			}),
		});

	_moveInputs->Enable();

}
