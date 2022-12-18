// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class TRANSFORM_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private :
	UPROPERTY(Category = "Movement", EditAnywhere)
	class UFloatingPawnMovement* Movement;
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* OurCameraSpringArm;
	class UCameraComponent* OurCamera;
	bool IsTurn;
	ACharacter* player1;
	ACharacter* target;

	void UpDown(float val);
	void RightLeft(float val);
	void ChangePlayer();
	void TurnStart();
	void TurnEnd();
	void Turn();
	void Yaw(float val);
};
