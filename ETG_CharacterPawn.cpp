#include "ETG_CharacterPawn.h"
#include "Level.h"
#include "InputManager.h"
using namespace Input;

ETG_CharacterPawn::ETG_CharacterPawn(Level* _level, const string& _name) : APawn(_level, _name)
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(RectangleShapeData(Vector2f(50.0f, 50.0f)));
	camera = CreateDefaultSubobject<UCameraComponent>(_level->GetWindowSize() / 2.0f, _level->GetWindowSize());
	_level->GetCameraManager().Register(camera);
}

ETG_CharacterPawn::ETG_CharacterPawn(const ETG_CharacterPawn& _other) :APawn(_other)
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(*_other.mesh);
	camera = CreateDefaultSubobject<UCameraComponent>(*_other.camera);
}

void ETG_CharacterPawn::SetupInputController(Input::InputManager& _inputManager)
{
	ActionMap* _moveInputs = _inputManager.CreateActionMap("PlayerMovement");

	_moveInputs->AddActions(
		{
			new Action("Up", ActionData(KeyPressed, Z), [&]()
			{
				LOG(Warning, "Z");
				//movement->AddVelocity(Vector2f(0.0f, 1.0f));
			}),
			new Action("Down", ActionData(KeyHold, S), [&]()
			{
				LOG(Warning, "S");
				//movement->AddVelocity(Vector2f(0.0f, -1.0f));
			}),
			new Action("Left", ActionData(KeyHold, Q), [&]()
			{
				LOG(Warning, "Q");
				//movement->AddVelocity(Vector2f(-1.0f, 0.0f));
			}),
			new Action("Right", ActionData(KeyHold, D), [&]()
			{
				LOG(Warning, "D");
				//movement->AddVelocity(Vector2f(1.0f, 0.0f));
			}),
		});

	_moveInputs->Enable();

}
