#include "Obstacle.h"

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

void AObstacle::ProcessMovement(float DeltaTime)
{
	const auto CurrentLocation = GetActorLocation();
	const auto CurrentAngle = FMath::Acos(CurrentLocation.X / Config::GroundRadius);
    const float X = Config::GroundRadius * FMath::Cos(DeltaTime * Speed + CurrentAngle);
    const float Z = Config::GroundRadius * FMath::Sin(DeltaTime * Speed + CurrentAngle);
	SetActorLocation(FVector(X, CurrentLocation.Y, Z));
}
