#include "Obstacle.h"

#include <Engine/World.h>
#include <GameFramework/Pawn.h>
#include <Kismet/KismetMathLibrary.h>

#include "Sharden/ShardenGameMode.h"

#include "Sharden/Config.h"

AObstacle::AObstacle()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();
}

void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ProcessMovement(DeltaTime);
}

void AObstacle::OnOverlap(AActor* OtherActor)
{
	const APawn* Pawn = Cast<APawn>(OtherActor);
	if (Pawn)
	{
		const auto GM = GetWorld()->GetAuthGameMode<AShardenGameMode>();
		if (GM)
		{
			GM->RegisterPlayerHit();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("GameMode isn't set to ShardenGameMode!"));
		}
	}
}

void AObstacle::ProcessMovement(float DeltaTime)
{
	const auto CurrentLocation = GetActorLocation();
	const float CurrentAngle = FMath::Acos(CurrentLocation.X / Radius);
	float AddAngle = DeltaTime * Speed + CurrentAngle;
	if (AddAngle > PI)
	{
		Destroy();
		return;
    }
    const float X = Radius * FMath::Cos(AddAngle);
    const float Z = Radius * FMath::Sin(AddAngle);
	const FVector TargetLocation(X, CurrentLocation.Y, Z + HeightOffset);
	SetActorLocationAndRotation(TargetLocation, UKismetMathLibrary::FindLookAtRotation(CurrentLocation, TargetLocation));
}

void AObstacle::SetHeightOffset(float Offset)
{
	HeightOffset = Offset;
}

void AObstacle::SetSpeed(float InSpeed)
{
	Speed = InSpeed;
}

void AObstacle::SetRadius(float InRadius)
{
	Radius = InRadius;
}