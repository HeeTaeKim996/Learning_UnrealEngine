


#include "R2Actor.h"
#include "Components/StaticMeshComponent.h"


AR2Actor::AR2Actor()
{
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));

	{ // BP 가 아닌, 에셋 할당 하드코딩 방법
#if 1
	
		ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT(
			"/Script/Engine.StaticMesh'/Game/_Arts/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
		// ※ 에셋 우클릭 후 CopyFilePath 하거나, 에셋 클릭후 Ctrl + C 하면 경로 복사됨
		if (FindMesh.Succeeded())
		{
			Box->SetStaticMesh(FindMesh.Object);
		}
#endif
	}
}

void AR2Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AR2Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

