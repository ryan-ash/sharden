#pragma once

#include <CoreMinimal.h>
#include <Engine/DataTable.h>
#include <GameFramework/GameModeBase.h>

#include "Sharden/Config.h"

#include "ShardenGameMode.generated.h"

UCLASS()
class SHARDEN_API AShardenGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void Tick_Impl(float DeltaSeconds);

    UFUNCTION(BlueprintCallable)
    void PlayStart();

    UFUNCTION(BlueprintCallable)
    void PlayEnd();

    UFUNCTION(BlueprintCallable)
    void SpawnObstacle();

    UFUNCTION(BlueprintCallable)
    void SetObstaclesSpawnable(bool Spawnable);

    UFUNCTION(BlueprintCallable)
    void SetSpawnParameters(USpawnData* Params);

    void RegisterPlayerHit();

public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<class AObstacle> ObstacleClass;

    UPROPERTY(EditAnywhere)
    float GroundRadius = 3000.0f;

private:
    float PlayTime = 0.0f;
    float SpawnTime = 0.0f;
    bool ObstaclesSpawnable = false;
    USpawnData* CurrentSpawnParameters;
};