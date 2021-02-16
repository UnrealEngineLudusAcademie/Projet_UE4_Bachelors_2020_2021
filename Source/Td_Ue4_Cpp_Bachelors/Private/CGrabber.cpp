// Copyright @ Ludus Académie


#include "CGrabber.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties

/****************************************************************************************************
Description : Constructor, Sets default values for this component's properties
Input : None

Output : None

Note ://

******************************************************************************************************/
UCGrabber::UCGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	fltreach = 200.f;

	PhysicsHandle=NULL;

	InputComponent=NULL;
	// ...
}


/****************************************************************************************************
Description : Call when game start
Input : None

Output : None

Note ://

******************************************************************************************************/

// Called when the game starts
void UCGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandleComponent();
	SetInputComponent();

	if (InputComponent) {
		InputComponent->BindAction("Grab", IE_Pressed, this, &UCGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UCGrabber::Release);

	}

	

	
}


/****************************************************************************************************
Description : Call every frame
Input : DeltaTime,TickType, ThisFunctionTick

Output : ThisFunctionTick

Note :Delta time is the time between two frames

******************************************************************************************************/

// Called every frame
void UCGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);



	if (PhysicsHandle->GrabbedComponent) {

		PhysicsHandle->SetTargetLocation(EndLineTrace());
	}
	// ...
}


/****************************************************************************************************
Description : This function return the Hit result of the component that is hit by the ray tracing in case of
collision withe an object having as collision channel ECC:TYPE PhysicsBody

Input : None

Output : None

Note ://

******************************************************************************************************/
FHitResult UCGrabber::GetFirstPhysicsBodyInReach()
{
	FHitResult OUT Hit;

	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	/*if (GetWorld()->LineTraceSingleByObjectType(OUT Hit, StartLineTrace(),EndLineTrace(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParameters)) {

		//Draw Debug line green
		DrawDebugLine(GetWorld(), StartLineTrace(), EndLineTrace(), FColor::Green, false, 5.f);

	}
	else {

		//Draw Debug line red
		DrawDebugLine(GetWorld(), StartLineTrace(), EndLineTrace(), FColor::Red, false, 5.f);
	}*/

	GetWorld()->LineTraceSingleByObjectType(OUT Hit, StartLineTrace(), EndLineTrace(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParameters);


	return Hit;
}
/****************************************************************************************************
Description : This function return the position of line trace start point

Input : None

Output : None

Note :Private function

******************************************************************************************************/
FVector UCGrabber::StartLineTrace()
{
	FVector PlayerViewPointVector;
	FRotator PlayerViewPointRotator;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointVector, PlayerViewPointRotator);

	return PlayerViewPointVector;
}


/****************************************************************************************************
Description : This function return the position of line trace end point

Input : None

Output : None

Note :Private function

******************************************************************************************************/
FVector UCGrabber::EndLineTrace()
{
	
	FVector PlayerViewPointVector;
	FRotator PlayerViewPointRotator;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointVector, PlayerViewPointRotator);


	FVector LineEnd = PlayerViewPointVector + PlayerViewPointRotator.Vector() * fltreach;


	return LineEnd;
}
/****************************************************************************************************
Description : This function get physicsHandle component from Blueprint, if you find it! Caution!! Always
do be carfull to secure your pointer!

Input : None

Output : None

Note ://

******************************************************************************************************/
void UCGrabber::FindPhysicsHandleComponent()
{

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle) {

		UE_LOG(LogTemp, Warning, TEXT("Component PhysicsHandle found"))
	}



}

/****************************************************************************************************
Description : This function Grab component from the scene, if you find it! Caution!! Always
to be carfull to secure your pointer!

Input : None

Output : None

Note ://

******************************************************************************************************/

void UCGrabber::Grab()
{
	FHitResult Hit = GetFirstPhysicsBodyInReach();

	UPrimitiveComponent* ComponentToGrab = Hit.GetComponent();

	AActor* ActorHit = Hit.GetActor();
	// ...
	if (ActorHit) {

		PhysicsHandle->GrabComponentAtLocation(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation());

		UE_LOG(LogTemp, Warning, TEXT("Actor hit : %s"), *ActorHit->GetName());
	}


}

/****************************************************************************************************
Description : This function set  physicsHandle (Loose Component)

Input : None

Output : None

Note ://
******************************************************************************************************/

void UCGrabber::Release()
{
	PhysicsHandle->ReleaseComponent();
}


/****************************************************************************************************
Description : Set input Component

Input : None

Output : None

Note ://

******************************************************************************************************/
void UCGrabber::SetInputComponent()
{


	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent) {

		UE_LOG(LogTemp, Warning, TEXT("Input Component found"))
	}

}

