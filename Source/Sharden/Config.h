#pragma once

#include <Curves/CurveFloat.h>
#include <Engine/DataTable.h>

#include "Config.generated.h"

USTRUCT()
struct SHARDEN_API FObstacleSpawnData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MovementSpeed = 1.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MinHeightDelta = 0.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MaxHeightDelta = 100.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MinSizeDelta = 0.75f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MaxSizeDelta = 1.25f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MinAngleDelta = 0.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float MaxAngleDelta = 45.0f;
};

UCLASS()
class SHARDEN_API USpawnData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = Obstacle)
    UCurveFloat* DifficultyCurve;
    
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float PlayTime = 60.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    int32 TotalHitPoints = 100;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    int32 DamageValue = 20;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float SpawnTime = 2.5f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    float Width = 500.0f;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    int32 MinCount = 1;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    int32 MaxCount = 3;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    TArray <TSubclassOf<class AObstacle>> Obstacles;
    UPROPERTY(EditAnywhere, Category = Obstacle)
    TMap <TSubclassOf<class AObstacle>, FObstacleSpawnData> ObstaclesDataMap;
};
