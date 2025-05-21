#include "Proto_Map.h"
//#include "PlayerPawn.h"
#include "Room.h"
#include "CircleActor.h"
#include "CUSTOMGameMode.h"
#include "CanvasWidget.h"

Proto_Map::Proto_Map(const string& _name) : Level(_name)
{
}

void Proto_Map::InitLevel()
{
	Super::InitLevel();
	GetCameraManager().GetCurrent()->SetCenter(Vector2f{ 0.0f,0.0f });

	HUD* _hud = GetGameMode()->GetHUD();
	UI::CanvasWidget* canvas = _hud->SpawnWidget<UI::CanvasWidget>();
	//canvas->SetSize(CAST(Vector2f, GetWindowSize()));

	//ImageWidget* _image = _hud->SpawnWidget<ImageWidget>(CircleShapeData(50.0f));
	//canvas->AddChild(_image);

	//AActor* _actor = SpawnActor<ACircleActor>(50.0f);
	//_actor->SetPosition({ 500.0f,500.0f });
	Room* _room = SpawnActor<Room>();
	_room->SetPosition({ 10.0f,100.0f });

	//_actor->SetPosition(GetWindowSize() / 2.0f);

	//GetGameMode()->GetHUD()->AddToViewport(canvas);
}

void Proto_Map::Load()
{
	Super::Load();
}

void Proto_Map::Unload()
{
	Super::Unload();
}
