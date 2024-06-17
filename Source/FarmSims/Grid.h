// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

UCLASS()
class FARMSIMS_API AGrid : public AActor
{
	GENERATED_BODY()

private:

	
public:	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category ="Grid")
	int Row = 10;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category ="Grid")
	int Col = 10;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category ="Grid")
	int CellSize = 100;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category ="Grid")
	TSubclassOf<AActor> TileClass;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category ="Grid")
	TArray<AActor*> TileGrid;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ConstructGrid();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SpawnTile(FTransform TileTransform);
};
