// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectGameMode.h"
#include "StarterProjectPlayerController.h"
#include "StarterProjectGameStateBase.h"
#include "StarterProjectPlayerState.h"
#include "UObject/ConstructorHelpers.h"

#include "EngineClasses/SpatialNetConnection.h"
#include "EngineClasses/SpatialNetDriver.h"
#include "Engine/World.h"
#include "Interop/Connection/SpatialWorkerConnection.h"

AStarterProjectGameMode::AStarterProjectGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	//set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/EntityBlueprints/StarterProjectCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AStarterProjectPlayerController::StaticClass();
	GameStateClass = AStarterProjectGameStateBase::StaticClass();
	PlayerStateClass = AStarterProjectPlayerState::StaticClass();
}

//void AStarterProjectGameMode::Tick(float DeltaSeconds)
//{
//	if (GetNetMode() == NM_DedicatedServer && !bHasUpdatedMaxActorsToReplicate)
//	{
//		if (USpatialNetDriver* SND = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver()))
//		{
//			if (SND->Connection && SND->Connection->IsConnected())
//			{
//				if (USpatialNetConnection* SNC = SND->GetSpatialOSNetConnection())
//				{
//					SNC->SetMaxActorsToReplicatePerFrame(MaxActorsToReplicate);
//					bHasUpdatedMaxActorsToReplicate = true;
//				}
//			}
//		}
//	}
//}
