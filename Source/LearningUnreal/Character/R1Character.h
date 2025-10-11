

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/R1HighlightInterface.h"
#include "R1Character.generated.h"

UCLASS()
class LEARNINGUNREAL_API AR1Character : public ACharacter, public IR1HighlightInterface
{
	GENERATED_BODY()

public:
	AR1Character();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




public:
	virtual void Highlight() override;
	virtual void UnHighlight() override;



protected:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;














protected:
#if 0 // R1Player 로 이동
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> Camera;
#endif
};