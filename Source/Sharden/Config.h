#pragma once

#include <Engine/DataTable.h>

#include "Config.generated.h"

class Config
{
public:
    static const float GroundRadius;
};

UCLASS()
class SHARDEN_API USpawnData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float SpawnTime = 2.5f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float Width = 500.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MinSizeDelta = 0.75f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MaxSizeDelta = 1.25f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    int32 MinCount = 1;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    int32 MaxCount = 3;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MinAngleDelta = 0.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MaxAngleDelta = 45.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    TArray <TSubclassOf<class AObstacle>> Obstacles;
};