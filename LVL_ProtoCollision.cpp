#include "LVL_ProtoCollision.h"
#include "PlayerController.h"
#include "ACursorProtoCollision.h"

LVL_ProtoCollision::LVL_ProtoCollision(const string& _name) : Level(_name)
{
	canvas = nullptr;
	image = nullptr;
	label = nullptr;
	cursor = nullptr;
}

void LVL_ProtoCollision::InitLevel()
{
	Super::InitLevel();

	HUD* _hud = GetGameMode()->GetHUD();

	UI::CanvasWidget* canvas = _hud->SpawnWidget<UI::CanvasWidget>();
	canvas->SetSize(CAST(Vector2f, GetWindowSize()));

	//AMeshActor* _meshActor = SpawnActor<AMeshActor>(RectangleShapeData({50.0f,50.0f}));

	GetCameraManager().GetCurrent()->SetCenter(Vector2f{ 0.0f,0.0f });

	//cameraProto = SpawnActor<ACameraActor>(Vector2f(GetWindowSize() / 2.0f), Vector2f(GetWindowSize()), "CameraProtoCollision");

	cursor = SpawnActor<ACursorProtoCollision>(RectangleShapeData({20.0f,20.0f}));
	ACursorProtoCollision* _other = SpawnActor<ACursorProtoCollision>(RectangleShapeData({50.0f,50.0f}));

	_other->SetCanMove(false);
	//cursor->GetMesh()->GetShape()->GetDrawable()->setFillColor(sf::Color::Green);

	_other->SetPosition(Vector2f{});
	cursor->SetPosition(Vector2f{ 100.0f,100.0f });
	GetGameMode()->GetHUD()->AddToViewport(canvas);
}
