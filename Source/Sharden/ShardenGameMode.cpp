#include "ShardenGameMode.h"

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
        SpawnObstacle(Params);
    }
}

void AShardenGameMode::SpawnObstacle(const FSpawnParameters Parameters)
{
    FActorSpawnParameters SpawnInfo;

    const auto CurrentAngle = FMath::DegreesToRadians(-180.0f);
    const float X = Config::GroundRadius * FMath::Cos(CurrentAngle);
    const float Z = Config::GroundRadius * FMath::Sin(CurrentAngle);
    const auto Obstacle = GetWorld()->SpawnActor<AObstacle>(ObstacleClass, FVector(X, FMath::RandRange(-Parameters.Width, Parameters.Width), Z), FRotator(0, 0, 0), SpawnInfo);
    Obstacle->SetActorScale3D(Obstacle->GetActorScale() * Parameters.Size);
}