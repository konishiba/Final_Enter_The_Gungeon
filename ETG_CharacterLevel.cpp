#include "ETG_CharacterLevel.h"
#include "ETG_GameplayGamemode.h"
#include "ETG_GameplayHud.h"
#include "ETG_GameplayPlayerController.h"
#include "ETG_CharacterPawn.h"
#include "PlayerController.h"
#include "RustySidearm.h"
ETG_CharacterLevel::ETG_CharacterLevel(const string& _name):Level(_name)
{


}

void ETG_CharacterLevel::InitLevel()
{
	Super::InitLevel();
	HUD* _hud = GetGameMode()->GetHUD();
	player = SpawnActor<ETG_CharacterPawn>();

	RustySidearm* _weapon = SpawnActor<RustySidearm>();

	if (_weapon && player)
	{
		AActor* _weaponSocket = player->GetChildByName("WeaponSocket");
		if (_weaponSocket)
		{
			_weaponSocket->AddChild(_weapon, AttachmentType::AT_SNAP_TO_TARGET);
		}
	}
}
