

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R2Actor.generated.h"

UCLASS()
class LEARNINGUNREAL_API AR2Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	AR2Actor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class UStaticMeshComponent> Box;
};
