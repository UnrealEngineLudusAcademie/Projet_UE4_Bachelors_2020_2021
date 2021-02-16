// Fill out your copyright notice in the Description page of Project Settings.


#include "CCharacter.h"

// Sets default values
ACCharacter::ACCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);




	

}

void ACCharacter::MoveForwarBackward(float flt_scale)
{

	AActor* actor = GetOwner();
	AddMovementInput(actor->GetActorForwardVector(),flt_scale);

}

void ACCharacter::MoveLeftRight(float flt_scale)
{

	AActor* actor = GetOwner();
	AddMovementInput(actor->GetActorRightVector(), flt_scale);
}

void ACCharacter::Turn(float flt_scale)
{

	AddControllerYawInput(flt_scale);
}

void ACCharacter::LookUp(float flt_scale)
{
	AddControllerPitchInput(flt_scale);
}

void ACCharacter::Jump()
{
	UE_LOG(LogTemp, Warning, TEXT("Methode Jump classe CCharactere"))

	Super::Jump();

}








