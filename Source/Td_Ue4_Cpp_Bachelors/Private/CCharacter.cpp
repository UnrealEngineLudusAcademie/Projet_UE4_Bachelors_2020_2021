// Fill out your copyright notice in the Description page of Project Settings.


#include "CCharacter.h"


/****************************************************************************************************
Description : Constructor, Sets default values for this component's properties
Input : None

Output : None

Note ://

******************************************************************************************************/

// Sets default values
ACCharacter::ACCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/****************************************************************************************************
Description : Call when game start
Input : None

Output : None

Note ://

******************************************************************************************************/
// Called when the game starts or when spawned
void ACCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

/****************************************************************************************************
Description : Call every frame
Input : DeltaTime,TickType, ThisFunctionTick

Output : ThisFunctionTick

Note :Delta time is the time between two frames

******************************************************************************************************/

// Called every frame
void ACCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/****************************************************************************************************
Description : Set input component & bind action reference fonctions
Input : UInputComponent* PlayerInputComponent

Output : None

Note :// Delegates input event (Axix mapping and action mapping)

******************************************************************************************************/
// Called to bind functionality to input
void ACCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &ACCharacter::MoveForwarBackward);
	PlayerInputComponent->BindAxis("Left/Right", this, &ACCharacter::MoveLeftRight);
	PlayerInputComponent->BindAxis("Turn", this, &ACCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ACCharacter::LookUp);

	//Action
	PlayerInputComponent->BindAction("jump", IE_Pressed, this, &ACCharacter::Jump);
	



	

}
/****************************************************************************************************
Description : Function Move Forward/Backward
Input : float flt_scale

Output : None

Note ://

******************************************************************************************************/
void ACCharacter::MoveForwarBackward(float flt_scale)
{

	AActor* actor = GetOwner();
	AddMovementInput(actor->GetActorForwardVector(),flt_scale);

}

/****************************************************************************************************
Description : Function move left / Right
Input : float flt_scale

Output : None

Note ://

******************************************************************************************************/

void ACCharacter::MoveLeftRight(float flt_scale)
{

	AActor* actor = GetOwner();
	AddMovementInput(actor->GetActorRightVector(), flt_scale);
}


/****************************************************************************************************
Description : Function  azimuth (Yaw input)
Input : float flt_scale

Output : None

Note ://

******************************************************************************************************/
void ACCharacter::Turn(float flt_scale)
{

	AddControllerYawInput(flt_scale);
}
/****************************************************************************************************
Description : Function  azimuth (Pitch input)
Input : float flt_scale

Output : None

Note ://

******************************************************************************************************/
void ACCharacter::LookUp(float flt_scale)
{
	AddControllerPitchInput(flt_scale);
}

/****************************************************************************************************
Description : Function Jump action
Input : None

Output : None

Note ://

******************************************************************************************************/

void ACCharacter::Jump()
{
	UE_LOG(LogTemp, Warning, TEXT("Methode Jump classe CCharactere"))

	Super::Jump();

}








