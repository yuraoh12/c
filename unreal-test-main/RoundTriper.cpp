// Fill out your copyright notice in the Description page of Project Settings.


#include "RoundTriper.h"

// Sets default values
ARoundTriper::ARoundTriper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TripTime = 3.0f;
	CumulativeTime = 0.0f;
	Direction = GetActorForwardVector();
}

// Called when the game starts or when spawned
void ARoundTriper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoundTriper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CumulativeTime += DeltaTime;
	if (CumulativeTime >= TripTime)
	{
		Direction = Direction * -1;
		CumulativeTime = 0;
	}

	FVector loc = GetActorLocation();
	loc += Direction;

	SetActorLocation(loc);
}

