// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

void AGrid::ConstructGrid_Implementation()
{
	FVector StartLocation = GetActorLocation();
	for (int i= 0; i < Row; i++)
	{
		for (int j = 0; j < Col; ++j)
		{
			float x = StartLocation.X + (i * CellSize);
			float y = StartLocation.Y + (j * CellSize);
			float z = StartLocation.Z;

			FVector SpawnLocation = {x,y,z};

			FTransform TileTransform = FTransform(FRotator::ZeroRotator, SpawnLocation);
			SpawnTile(TileTransform);
		}
	}
}

void AGrid::SpawnTile_Implementation(FTransform TileTransform)
{
	FActorSpawnParameters spawnParam;
	spawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* tile = GetWorld()->SpawnActor<AActor>(TileClass, TileTransform, spawnParam);
	TileGrid.Add(tile);
}
