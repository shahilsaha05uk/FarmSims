// Fill out your copyright notice in the Description page of Project Settings.


#include "SimController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionDataAsset.h"
#include "PlayerInputInterface.h"
#include "Kismet/KismetSystemLibrary.h"

class UEnhancedInputLocalPlayerSubsystem;

void ASimController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {

		// Set Destination
		EnhancedInputComponent->BindAction(InputData->IA_SetDestination, ETriggerEvent::Triggered, this, &ASimController::SetDestination);
	}

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(MappingContext, 0);
	}

}

void ASimController::SetDestination_Implementation(const FInputActionValue& InputActionValue)
{
	APawn* pawn = GetPawn();

	if(HasTheInterface(pawn, UPlayerInputInterface::StaticClass()))
	{
		IPlayerInputInterface::Execute_SetDestination(pawn, InputActionValue);
	}
}

bool ASimController::HasTheInterface(const UObject* Obj, TSubclassOf<UInterface> InterfaceClass)
{
	return UKismetSystemLibrary::DoesImplementInterface(Obj, InterfaceClass);
}

