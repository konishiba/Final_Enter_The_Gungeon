#include "RustySidearm.h"
#include "Level.h"
#include "TimerManager.h"
#include "LevelManager.h"

using namespace Input;

RustySidearm::RustySidearm(Level* _level)
	: Gun(_level, RectangleShapeData({ 20.0f,20.0f }, "RustySidearm"), "RustySidearm", Rarity::R_NONE,
		new GunData(6, -1, -1, 6,
			0.20f, 1.2f, 16,
			16, 10, 7, 1))
{

}

RustySidearm::RustySidearm(const RustySidearm& _other)
	: Gun(_other)
{
}

void RustySidearm::Construct()
{
	Super::Construct();

	SetupInput();
}

void RustySidearm::Deconstruct()
{
	Super::Deconstruct();
}

void RustySidearm::Shoot()
{
	const RenderWindow& _window = M_LEVEL.GetCurrentLevel()->GetRenderWindow();
	const Vector2i& _pixelPos = Mouse::getPosition(_window);
	const Vector2f& _pixelToCoords = _window.mapPixelToCoords(_pixelPos, *M_LEVEL.GetCurrentLevel()->GetCameraManager().GetCurrent()->GetView());
	const Vector2f& _mousePos = _pixelToCoords;

	Vector2f _direction = _mousePos - GetPosition();
	if (_direction.x + _direction.y != 0)
	{
		_direction = _direction.normalized();
	}
	const Vector2f& _ownerSize = GetMesh()->GetShape()->GetDrawable()->getGlobalBounds().size;
	gunComponent->Shoot(_direction, _ownerSize);
}

void RustySidearm::Reload()
{
	gunComponent->Reload();
}

void RustySidearm::SetupInput()
{
	PlayerController* _controller = level->GetGameMode()->GetPlayerController();

	InputManager& _inputMap = _controller->GetInputManager();

	ActionMap* _actionMap = _inputMap.CreateActionMap("RustySidearm");

	_actionMap->AddAction("Shoot", ActionData(KeyHold, KeyType::Space), [&]() { Shoot(); });
	_actionMap->AddAction("Reload", ActionData(KeyHold, KeyType::R), [&]() { Reload(); });

	_actionMap->Enable();
}