// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Runtime/Engine/Public/EngineUtils.h" 

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	
	ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshRes(TEXT("SkeletalMesh'/Game/SCK_Casual01/Models/Premade_Characters/MESH_PC_03.MESH_PC_03'"));
	GetMesh() -> SetSkeletalMesh(MeshRes.Object);
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	//RootComponent = GetMesh();
	FString str = RootComponent->GetName();
	
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(-280.f, 80.f, 470.f), FRotator(-45.f, 0.f, 0.f));
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->TargetArmLength = 400.f;

	OurCamera = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	OurCamera->SetupAttachment(OurCameraSpringArm);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	AutoPossessPlayer = EAutoReceiveInput::Player1;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsTurn) {
		Turn();
	}
	FRotator rot = GetMesh()->GetRelativeRotation();
	//UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), rot.Roll, rot.Pitch, rot.Yaw);
	rot += FRotator(0, 0.1f, 0);
	//UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), rot.Roll, rot.Pitch, rot.Yaw);
	GetMesh()->SetRelativeRotation(rot);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("change"), EInputEvent::IE_Pressed, this, &AMyCharacter::ChangePlayer);
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("RightLeft"), this, &AMyCharacter::RightLeft);
	PlayerInputComponent->BindAxis(TEXT("YAW"), this, &AMyCharacter::Yaw);
	PlayerInputComponent->BindAction(TEXT("Turn Start"), EInputEvent::IE_Pressed,this, &AMyCharacter::TurnStart);
	PlayerInputComponent->BindAction(TEXT("Turn Start"), EInputEvent::IE_Released,this, &AMyCharacter::TurnEnd);
}

void AMyCharacter::Yaw(float val) {
	AddControllerYawInput(val * 0.5f);
}
void AMyCharacter::UpDown(float val)
{
	//AddMovementInput(FVector(1.f, 0.f, 0.f), val);
	AddMovementInput(GetActorForwardVector(), val);
}

void AMyCharacter::RightLeft(float val)
{
	//AddMovementInput(FVector(0.f, 1.f, 0.f), val);
	AddMovementInput(GetActorRightVector(), val);
}

void AMyCharacter::TurnStart()
{
	IsTurn = true;
}
void AMyCharacter::TurnEnd()
{
	IsTurn = false;
}
void AMyCharacter::Turn() {
	FRotator rot = GetMesh()->GetRelativeRotation();
		
	// direction
	FVector loc = GetMesh()->GetRelativeLocation();
	FVector axisY = FVector::YAxisVector;
	
	FVector norm_loc = loc.GetSafeNormal();
	float tan = norm_loc.Y / norm_loc.X;
	float angle = FMath::Atan(tan);
	FVector norm_axisY = axisY.GetSafeNormal();
	float tan2 = norm_axisY.Y / norm_axisY.X;
	float angle2 = FMath::Atan(tan2);
	// magnitude
	angle = angle * 180 / 3.141592;
	UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), norm_loc.X, norm_loc.Y, norm_loc.Z);
	UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), loc.X, loc.Y, loc.Z);
	UE_LOG(LogTemp, Warning, TEXT("%f"), angle);
	rot += FRotator(0.f, 10.f, 0.f);
	GetMesh()->SetRelativeRotation(rot);

}
void AMyCharacter::ChangePlayer() {
	
	AController* con = GetController();
	if (target == nullptr && player1 == nullptr) {
		UWorld* CurrentWorld = GetWorld();
		TActorIterator<AMyCharacter> iter(CurrentWorld);
		for (; iter; ++iter) {
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *iter->GetName());
			if (iter->GetName() == TEXT("MyCharacter_11")) {
				target = *iter;
				break;
			}
		}
		player1 = con->GetCharacter();
	}

	con->Possess(target);
	if (target != nullptr && player1 != nullptr) {
		
		UE_LOG(LogTemp, Warning, TEXT("%s"), *player1->GetName());
		UE_LOG(LogTemp, Warning, TEXT("%s"), *target->GetName());
	}


}
