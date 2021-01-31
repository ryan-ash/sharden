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

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndWhipeInteract);
    UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category = Event)
    FEndWhipeInteract EndWhipeInteract;

    UFUNCTION(BlueprintCallable)
    void OnSendDiraction(const FVector& Diraction);
    UFUNCTION(BlueprintCallable)
    void ResetCanInteract();

    UFUNCTION(BlueprintCallable)
    void Collapse();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event)
    bool Destructible = true;

protected:
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintImplementableEvent)
    void GetWhipDiraction(const FVector& Diraction);

    UFUNCTION(BlueprintImplementableEvent)
    void CollapseEvent();

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

    bool CanInteract = true;
};