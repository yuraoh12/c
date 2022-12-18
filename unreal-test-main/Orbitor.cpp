// Fill out your copyright notice in the Description page of Project Settings.


#include "Orbitor.h"

// Sets default values
AOrbitor::AOrbitor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OrbitWidth = 50.0f;
	OrbitVelocity = 5.0f;
	OrbitRotation = FRotator(40.f, 0.f, 0.f);

}

// Called when the game starts or when spawned
void AOrbitor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrbitor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	float y = FMath::Sin(RunningTime + DeltaTime) * 500.f;
	float x = FMath::Cos(RunningTime + DeltaTime) * 500.f;
	
	FVector loc = GetActorLocation();
	loc.X = x;
	loc.Y = y;

	SetActorLocation(loc);
}

