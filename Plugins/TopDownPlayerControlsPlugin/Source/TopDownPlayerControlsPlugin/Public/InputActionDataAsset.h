// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Engine/DataAsset.h"
#include "InputActionDataAsset.generated.h"


UCLASS(Blueprintable, BlueprintType)
class TOPDOWNPLAYERCONTROLSPLUGIN_API UInputActionDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputAction* IA_SetDestination;
};
