#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Actor.h>

#include "Obstacle.generated.h"

UCLASS()
class SHARDEN_API AObstacle : public AActor
{
    GENERATED_BODY()

public:
    AObstacle();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    void OnOverlap(AActor* OtherActor);

private:
    void ProcessMovement(float DeltaTime);

private:
    float Speed = 1.0f;
};