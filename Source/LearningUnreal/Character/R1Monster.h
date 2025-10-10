

#pragma once

#include "CoreMinimal.h"
#include "Character/R1Character.h"
#include "R1Monster.generated.h"

/**
 * 
 */
UCLASS()
class LEARNINGUNREAL_API AR1Monster : public AR1Character
{
	GENERATED_BODY()
	
public:
	AR1Monster();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
