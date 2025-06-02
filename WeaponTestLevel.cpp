#include "WeaponTestlevel.h"

#include "CUSTOMHUD.h"
#include "CUSTOMGameMode.h"
#include "CUSTOMLevel.h"
#include "CUSTOMMesh.h"
#include "CustomActor.h"

#include "GIFWidget.h"
#include "Particle.h"
#include "LevelManager.h"
#include "CUSTOMPlayerController.h"
#include "CUSTOMPawn.h"
#include "SliderWidget.h"
#include "CheckBoxWidget.h"
#include "PlayerController.h"
#include "RustySidearm.h"

WeaponTestlevel::WeaponTestlevel(const string& _name) : Level(_name)
{
	canvas = nullptr;
	image = nullptr;
	label = nullptr;
}


void WeaponTestlevel::InitLevel()
{
	Super::InitLevel();

	HUD* _hud = GetGameMode()->GetHUD();

	canvas = _hud->SpawnWidget<CanvasWidget>();
	canvas->SetDebugMode(true);
	canvas->SetSize(CAST(Vector2f, GetWindowSize()));

	if (RustySidearm* _sawedOff = SpawnActor<RustySidearm>())
	{
		_sawedOff->SetPosition({ 100.0f, 100.0f });
	}
	

	GetGameMode()->GetHUD()->AddToViewport(canvas);
}