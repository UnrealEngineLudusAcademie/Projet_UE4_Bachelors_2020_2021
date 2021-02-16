// Fill out your copyright notice in the Description page of Project Settings.


#include "CPosition.h"

// Sets default values for this component's properties
UCPosition::UCPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	


	// ...
}


// Called when the game starts
void UCPosition::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG
	UE_LOG(LogTemp, Warning, TEXT("Dans le BeginPlay"))

	// ...
	
}


// Called every frame
void UCPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	//UE_LOG
	FString FName=GetOwner()->GetName();
	FString FPosition=GetOwner()->GetTransform().GetLocation().ToString();

	//UE_LOG(LogTemp, Warning, TEXT("Nom : %s , Position : %s"), *FName, *FPosition);

	


}

void UCPosition::print_log()
{
	UE_LOG(LogTemp, Warning, TEXT("flt value : %f"), flt_value);

}

