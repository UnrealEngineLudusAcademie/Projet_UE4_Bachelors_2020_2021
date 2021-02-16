// Copyright @ Ludus Académie

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPosition.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_UE4_CPP_BACHELORS_API UCPosition : public UActorComponent
{
	GENERATED_BODY()

private :

	

public:	
	// Sets default values for this component's properties
	UCPosition();

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Float")
		float flt_value = 100.f;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable,Category ="Log")
	void print_log();

		
};
