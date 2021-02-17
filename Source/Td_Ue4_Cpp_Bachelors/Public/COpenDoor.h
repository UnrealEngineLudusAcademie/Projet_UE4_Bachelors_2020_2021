// Copyright @ Ludus Académie

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "COpenDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_UE4_CPP_BACHELORS_API UCOpenDoor : public UActorComponent
{
	GENERATED_BODY()
private : 

	UPROPERTY(EditAnyWhere, Category = "Properties BP_OpenDoor")
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnyWhere,Category ="Properties BP_OpenDoor")
	float flt_MassTest;

	UPROPERTY(EditAnyWhere,Category = "Properties BP_OpenDoor")
	float flt_Delay;

	float flt_LastDoorOpenTime;

	bool bl_IsOpen;

	float flt_TimeLastDoorOpen;
	

public:	
	// Sets default values for this component's properties
	UCOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void OpenDoor();

	void CloseDoor();

	float getTotalMassOfActors();

	//Delegates
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpenRequest;

	//Delegates
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnCloseRequest;
};
