#include "ShardenGameMode.h"

#include "Sharden/Config.h"

void AShardenGameMode::Tick(float DeltaSeconds)
{
    SpawnTime += DeltaSeconds;
    if (SpawnTime > Config::SpawnTime)
    {
        SpawnTime /= Config::SpawnTime;
        //GetWorld()->SpawnActor(Obstacle);
    }
}