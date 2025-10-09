

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "R1Character.generated.h"

UCLASS()
class LEARNINGUNREAL_API AR1Character : public ACharacter
{
	GENERATED_BODY()

public:
	AR1Character();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> Camera;
};