


#include "Character/R1Monster.h"

AR1Monster::AR1Monster()
{
	PrimaryActorTick.bCanEverTick = true;


	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0, -90.f, 0));
}

void AR1Monster::BeginPlay()
{
	Super::BeginPlay();
}

void AR1Monster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}
