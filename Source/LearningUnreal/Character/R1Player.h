

#pragma once

#include "CoreMinimal.h"
#include "Character/R1Character.h"
#include "R1Player.generated.h"

/**
 * 
 */

//#define USE_TPS_CONTROLL

UCLASS()
class LEARNINGUNREAL_API AR1Player : public AR1Character
{
	GENERATED_BODY()
	
public:
	AR1Player();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	virtual void HandleGameplayEvent(FGameplayTag EventTag) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> Camera;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class AR1PlayerController> PlayerController;
};
