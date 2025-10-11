

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/R1HighlightInterface.h"
#include "R1Define.h"
#include "GameplayTagContainer.h"
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

	virtual void HandleGameplayEvent(FGameplayTag EventTag) {}


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




public:
	virtual void Highlight() override;
	virtual void UnHighlight() override;


	virtual void OnDamage(int32 Damage, TObjectPtr<AR1Character> from);
	virtual void OnDead(TObjectPtr<AR1Character> from);


protected:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
	

public:
	UPROPERTY(BlueprintReadWrite)
	ECreatureState CreatureState = ECreatureState::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Hp = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 FinalDamage = 10;


protected:
#if 0 // R1Player 로 이동
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> Camera;
#endif
};