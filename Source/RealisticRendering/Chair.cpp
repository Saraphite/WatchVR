// Fill out your copyright notice in the Description page of Project Settings.

#include "RealisticRendering.h"
#include "Chair.h"

// Sets default values
AChair::AChair()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	seatCount = 1;
	seatLocs.Add(FVector::ZeroVector);
	seatAvailability.Add(false);
}

AChair::AChair(int numberOfSeats) {
	PrimaryActorTick.bCanEverTick = true;
	seatCount = numberOfSeats;
	for (int i = 0; i < numberOfSeats; i++) {
		seatLocs.Add(FVector::ZeroVector);
		seatAvailability.Add(false);
	}
}

// Called when the game starts or when spawned
void AChair::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AChair::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector AChair::SitOnChair() {
	for (int i = 0; i < seatAvailability.Num(); i++) {
		if (!seatAvailability[i]) {
			return seatLocs[i];
		}
	}
	return FVector::ZeroVector;
}

FVector AChair::SitOnClosestChair(FVector selectionPoint) {
	float lowestDist = 20000.0f;
	FVector seatLoc = FVector::ZeroVector;
	for (int i = 0; i < seatAvailability.Num(); i++) {
		if (seatAvailability[i])
		{
			float dist = FVector::DistSquared(selectionPoint, seatLocs[i]);
			if (lowestDist > dist) {
				lowestDist = dist;
				seatLoc = seatLocs[i];
			}
		}
	}
	return seatLoc;
}


