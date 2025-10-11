


#include "Character/R1Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "R1Define.h"

AR1Character::AR1Character()
{
	PrimaryActorTick.bCanEverTick = true;

#if 0 // R1Player 로 이동
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->TargetArmLength = 700.f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
#endif 

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Character"));
}

void AR1Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AR1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AR1Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AR1Character::Highlight()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);
}

void AR1Character::UnHighlight()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
}

void AR1Character::OnDamage(int32 Damage, TObjectPtr<AR1Character> from)
{
	Hp = FMath::Clamp(Hp - Damage, 0, MaxHp);

	if (Hp == 0)
	{
		OnDead(from);
	}

	D(FString::Printf(TEXT("%d"), Hp));
}

void AR1Character::OnDead(TObjectPtr<AR1Character> from)
{
	if (CreatureState == ECreatureState::Dead) return;

	CreatureState = ECreatureState::Dead;
}

