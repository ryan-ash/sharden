#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShardenGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHARDEN_API AShardenGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    virtual void Tick(float DeltaSeconds) override;

public:
    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UObject> Obstacle;

private:
    float SpawnTime = 0.0f;
};
