// Copyright @ Ludus Académie


#include "COpenDoor.h"
#include "Components/StaticMeshComponent.h"


/****************************************************************************************************
Description : Constructor, Sets default values for this component's properties
Input : None

Output : None

Note ://

******************************************************************************************************/
// Sets default values for this component's properties
UCOpenDoor::UCOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	flt_LastDoorOpenTime = 0.f;

	bl_IsOpen = false;
}

/****************************************************************************************************
Description : Call when game start
Input : None

Output : None

Note ://

******************************************************************************************************/
// Called when the game starts
void UCOpenDoor::BeginPlay()
{
	Super::BeginPlay();


	
	
	// ...
	
}


/****************************************************************************************************
Description : Call every frame ,exec openDoor/closeDoor fct
Input : DeltaTime,TickType, ThisFunctionTick

Output : ThisFunctionTick

Note :Delta time is the time between two frames

******************************************************************************************************/
void UCOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	bool bl_IsOverlap = PressurePlate->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PressurePlate) {

		if (bl_IsOverlap)
		{
			
			//UE_LOG(LogTemp, Warning, TEXT("On Trigger Volume"))
			//OpenDoor();

		}
		else {
			//UE_LOG(LogTemp, Warning, TEXT("Out Trigger Volume"))
			//CloseDoor();
		}

		if (getTotalMassOfActors() >= flt_MassTest) {

			OpenDoor();
			flt_LastDoorOpenTime = GetWorld()->GetTimeSeconds();
			bl_IsOpen = true;
		}
		else if ((flt_TimeLastDoorOpen = GetWorld()->GetTimeSeconds() - flt_LastDoorOpenTime) > flt_Delay && bl_IsOpen) {
			CloseDoor();
			bl_IsOpen = false;

		}

	
			
	}

	// ...
}

/****************************************************************************************************
Description : This function calculates the total of the Actors Mass
Input : None

Output : None

Note ://

******************************************************************************************************/
float UCOpenDoor::getTotalMassOfActors()
{
	float flt_totalMass=0.f;
	TArray<AActor*> MyArray;

	PressurePlate->GetOverlappingActors(MyArray);
	for (class AActor* Actors :MyArray) {

		flt_totalMass = flt_totalMass + Actors->FindComponentByClass<UStaticMeshComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT(" Total Mass actors : %f"), flt_totalMass);

	}

	return  flt_totalMass;
}


/****************************************************************************************************
Description : Multicast Delegates OnCloseDoor event 
Input : None

Output : None

Note ://

******************************************************************************************************/
void UCOpenDoor::CloseDoor()
{

	//GetOwner()->SetActorRotation(FRotator(0, 0, 0));
	OnCloseRequest.Broadcast();
}

/****************************************************************************************************
Description : Multicast Delegates OnOpenDoor event 
Input : None

Output : None

Note ://

******************************************************************************************************/
void UCOpenDoor::OpenDoor()
{

	//GetOwner()->SetActorRotation(FRotator(0, 90, 0));
	OnOpenRequest.Broadcast();
}

