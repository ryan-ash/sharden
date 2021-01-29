#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShardenGameMode.generated.h"

USTRUCT(BlueprintType)
struct SHARDEN_API FSpawnParameters
{
    GENERATED_BODY()

    float Width;
    float Size;
};

UCLASS()
class SHARDEN_API AShardenGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void Tick_Impl(float DeltaSeconds);

    UFUNCTION(BlueprintCallable)
    void SpawnObstacle(const FSpawnParameters Parameters);
public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<class AObstacle> ObstacleClass;

private:
    float SpawnTime = 0.0f;
};