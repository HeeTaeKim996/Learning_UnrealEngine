


#include "Character/R1Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Player/R1PlayerController.h"

AR1Player::AR1Player()
{
	PrimaryActorTick.bCanEverTick = true;

#ifdef USE_TPS_CONTROLL
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
#endif

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCharacterMovement()->RotationRate = FRotator(0, 640.f, 0);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->TargetArmLength = 800.f;
	SpringArm->SetRelativeRotation(FRotator(-60, 0, 0));

	
	{ // ※ 이걸 해야 화면 안돌아감
		SpringArm->bUsePawnControlRotation = false;
		SpringArm->bInheritPitch = false;
		SpringArm->bInheritYaw = false;
		SpringArm->bInheritRoll = false;
	}




	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -88.f), FRotator(0, -90.f, 0));


	UCapsuleComponent* capsule = GetCapsuleComponent();
	capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
}

void AR1Player::BeginPlay()
{
	Super::BeginPlay();

#ifdef USE_TPS_CONTROLL
	GetController()->SetControlRotation(FRotator(-30.f, 0, 0));
#endif


	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);

	PlayerController = Cast<AR1PlayerController>(GetController());
} 

void AR1Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AR1Player::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("OnBeginOverlap"));
}

void AR1Player::HandleGameplayEvent(FGameplayTag EventTag)
{
	if (PlayerController)
	{
		PlayerController->HandleGameplayEvent(EventTag);
	}
}
