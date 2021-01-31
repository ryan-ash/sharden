#include "ShardenGameMode.h"

#include <Kismet/GameplayStatics.h>

#include "Sharden/Obstacles/Obstacle.h"

void AShardenGameMode::Tick_Impl(float DeltaSeconds)
{
    SpawnTime += DeltaSeconds;

    if (!CurrentSpawnParameters)
    {
        UE_LOG(LogTemp, Error, TEXT("Spawn parameters nullptr!"));
        return;
    }
    if (SpawnTime > CurrentSpawnParameters->SpawnTime)
    {
        SpawnTime /= CurrentSpawnParameters->SpawnTime;
        SpawnObstacle();
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

void AShardenGameMode::SpawnObstacle()
{
    if (!ObstaclesSpawnable)
    {
        return;
    }

    if (!CurrentSpawnParameters)
    {
        UE_LOG(LogTemp, Error, TEXT("Spawn parameters nullptr!"));
        return;
    }

    const int32 SpawnCount = FMath::RandRange(CurrentSpawnParameters->MinCount, CurrentSpawnParameters->MaxCount);

    for (int i = 0; i < SpawnCount; ++i)
    {
        const int32 SelectedObstacleI = FMath::RandRange(0, CurrentSpawnParameters->Obstacles.Num() - 1);
        const auto SelectedObstacle = CurrentSpawnParameters->Obstacles[SelectedObstacleI];
        if (!CurrentSpawnParameters->Obstacles.Contains(SelectedObstacle))
        {
            UE_LOG(LogTemp, Error, TEXT("Obstacle doesn't have params struct!"));
            return;
        }
        const auto ObstacleData = CurrentSpawnParameters->ObstaclesDataMap[SelectedObstacle];
        const auto CurrentAngle = FMath::DegreesToRadians(FMath::RandRange(ObstacleData.MinAngleDelta, ObstacleData.MaxAngleDelta));
        const float X = GroundRadius * FMath::Cos(CurrentAngle);
        const float Z = GroundRadius * FMath::Sin(CurrentAngle);
        FActorSpawnParameters SpawnInfo;
        const auto Obstacle = GetWorld()->SpawnActor<AObstacle>(SelectedObstacle, FVector(X, FMath::RandRange(-CurrentSpawnParameters->Width, CurrentSpawnParameters->Width), Z), FRotator(0, 0, 0), SpawnInfo);
        Obstacle->SetActorScale3D(Obstacle->GetActorScale() * FMath::RandRange(ObstacleData.MinSizeDelta, ObstacleData.MaxSizeDelta));
        const float Offset = FMath::RandRange(ObstacleData.MinHeightDelta, ObstacleData.MaxHeightDelta);
        Obstacle->SetRadius(GroundRadius);
        Obstacle->SetHeightOffset(Offset);
        Obstacle->SetSpeed(ObstacleData.MovementSpeed);
    }
}

void AShardenGameMode::SetSpawnParameters(USpawnData* Params)
{
    CurrentSpawnParameters = Params;
}