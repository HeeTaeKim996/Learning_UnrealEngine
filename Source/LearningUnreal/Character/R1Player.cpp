


#include "Character/R1Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


AR1Player::AR1Player()
{
	PrimaryActorTick.bCanEverTick = true;


	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->TargetArmLength = 700.f;
	SpringArm->bUsePawnControlRotation = true;
	//SpringArm->SetRelativeRotation(FRotator(-30.f, 0, 0));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -88.f), FRotator(0, -90.f, 0));

}

void AR1Player::BeginPlay()
{
	Super::BeginPlay();

	GetController()->SetControlRotation(FRotator(-30.f, 0, 0));
}

void AR1Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
