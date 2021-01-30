#include "ShardenGameMode.h"

#include <Kismet/GameplayStatics.h>

#include "Sharden/Config.h"
#include "Sharden/Obstacles/Obstacle.h"

void AShardenGameMode::Tick_Impl(float DeltaSeconds)
{
    SpawnTime += DeltaSeconds;
    if (SpawnTime > Config::SpawnTime)
    {
        SpawnTime /= Config::SpawnTime;
        FSpawnParameters Params;
        Params.Size = 1.0f;
        Params.Width = 500.0f;
        Params.MinCount = 1;
        Params.MaxCount = 3;
        Params.MinAngleDelta = 0.0f;
        Params.MaxAngleDelta = 45.0f;
        SpawnObstacle(Params);
    }
}

void AShardenGameMode::SetObstaclesSpawnable(bool Spawnable)
{
    ObstaclesSpawnable = Spawnable;
}

void AShardenGameMode::RegisterPlayerHit()
{
    PlayEnd();
    PlayStart();
}

void AShardenGameMode::PlayStart()
{
    SetObstaclesSpawnable(true);
}

void AShardenGameMode::PlayEnd()
{
    SetObstaclesSpawnable(false);
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ObstacleClass, FoundActors);
    for (const auto Actor : FoundActors)
    {
        Actor->Destroy();
    }
}

void AShardenGameMode::SpawnObstacle(const FSpawnParameters Parameters)
{
    if (!ObstaclesSpawnable)
    {
        return;
    }

    const int32 SpawnCount = FMath::RandRange(Parameters.MinCount, Parameters.MaxCount);

    for (int i = 0; i < SpawnCount; ++i)
    {
        FActorSpawnParameters SpawnInfo;
        const auto CurrentAngle = FMath::DegreesToRadians(FMath::RandRange(Parameters.MinAngleDelta, Parameters.MaxAngleDelta));
        const float X = Config::GroundRadius * FMath::Cos(CurrentAngle);
        const float Z = Config::GroundRadius * FMath::Sin(CurrentAngle);
        const auto Obstacle = GetWorld()->SpawnActor<AObstacle>(ObstacleClass, FVector(X, FMath::RandRange(-Parameters.Width, Parameters.Width), Z), FRotator(0, 0, 0), SpawnInfo);
        Obstacle->SetActorScale3D(Obstacle->GetActorScale() * Parameters.Size);
    }
}