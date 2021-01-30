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

    void SetHeightOffset(float Offset);

    void SetSpeed(float InSpeed);

    void SetRadius(float InRadius);

private:
    void ProcessMovement(float DeltaTime);

private:
    float Speed = 1.0f;
    float Radius = 0.0f;
    float HeightOffset = 0.0f;
};