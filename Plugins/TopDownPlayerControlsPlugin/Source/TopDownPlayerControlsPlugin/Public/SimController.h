// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "SimController.generated.h"


UCLASS()
class TOPDOWNPLAYERCONTROLSPLUGIN_API ASimController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	class UInputMappingContext* MappingContext;
	UPROPERTY(EditDefaultsOnly)
	class UInputActionDataAsset* InputData;

	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetDestination(const FInputActionValue& InputActionValue);

	UFUNCTION(BlueprintCallable)
	bool HasTheInterface(const UObject* Obj, TSubclassOf<UInterface> InterfaceClass);
};
