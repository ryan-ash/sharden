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
    void SpawnObstacle(int32 MaxCount);

    UFUNCTION(BlueprintCallable)
    void SetObstaclesSpawnable(bool Spawnable);

    UFUNCTION(BlueprintCallable)
    void SetSpawnParameters(USpawnData* Params);

    UFUNCTION(BlueprintCallable)
    void RegisterPlayerHit();

    UFUNCTION(BlueprintCallable)
    void RegisterPlayerHeal();

    UFUNCTION(BlueprintCallable)
    void ResetHitpoints();

    UFUNCTION(BlueprintCallable)
    int32 GetMaxHitpoint() const;

    UFUNCTION(BlueprintCallable)
    int32 GetCurrentHitpoint() const;

    UFUNCTION(BlueprintCallable)
    int32 GetMaxFragments() const;

    UFUNCTION(BlueprintCallable)
    void ReceiveDamage(int32 InDamage);

    UFUNCTION(BlueprintCallable)
    void HealUp(int32 InHeal);

    UFUNCTION(BlueprintImplementableEvent)
    void OnGameLost();

    UFUNCTION(BlueprintImplementableEvent)
    void OnGameWon();

protected:

    UFUNCTION(BlueprintImplementableEvent)
    void NewHitpoints(const int32& Hippoints);

public:

    UPROPERTY(EditAnywhere)
    TSubclassOf<class AObstacle> ObstacleClass;

    UPROPERTY(EditAnywhere)
    float GroundRadius = 3000.0f;

private:

    int32 HitPoints = 100;
    clock_t TimeAtTheStart = 0.f;
    clock_t LastSpawnTime = 0.f;
    bool GameRunning = false;
    bool ObstaclesSpawnable = false;
    USpawnData* CurrentSpawnParameters;
};