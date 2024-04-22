// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerInputInterface.h"
#include "GameFramework/Character.h"
#include "FarmPlayer.generated.h"

UCLASS()
class TOPDOWNPLAYERCONTROLSPLUGIN_API AFarmPlayer : public ACharacter, public IPlayerInputInterface
{
	GENERATED_BODY()

public:
	AFarmPlayer();

	virtual void SetDestination_Implementation(const FInputActionValue& InputActionValue) override;

};
