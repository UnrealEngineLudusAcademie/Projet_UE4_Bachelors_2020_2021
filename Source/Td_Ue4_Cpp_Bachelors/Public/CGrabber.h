// Copyright @ Ludus Académie

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CGrabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_UE4_CPP_BACHELORS_API UCGrabber : public UActorComponent
{
	GENERATED_BODY()

private :

	UPROPERTY(EditAnywhere,Category="Line trace property")
	float fltreach;

	UPhysicsHandleComponent* PhysicsHandle;

	UInputComponent* InputComponent;

public:	
	// Sets default values for this component's properties
	UCGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Line Trace
	FHitResult GetFirstPhysicsBodyInReach();


	//Set start point line trace
	FVector StartLineTrace();

	//Set end point line trace
	FVector EndLineTrace();


	//Attach physics handle
	void FindPhysicsHandleComponent();


	void Grab();

	void Release();

	void SetInputComponent();

};
