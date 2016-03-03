// Fill out your copyright notice in the Description page of Project Settings.

#include "RealisticRendering.h"
#include "Seat.h"


// Sets default values
ASeat::ASeat()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	seatCount = 1;
	seatLocs.Add(FVector::ZeroVector);
	seatAvailability.Add(false);
}

ASeat::ASeat(int numberOfSeats) {
	PrimaryActorTick.bCanEverTick = true;
	seatCount = numberOfSeats;
	for (int i = 0; i < numberOfSeats; i++) {
		seatLocs.Add(FVector::ZeroVector);
		seatAvailability.Add(false);
	}
}

// Called when the game starts or when spawned
void ASeat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASeat::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

FVector ASeat::GetAvailableSeatVector() {
	for (int i = 0; i < seatAvailability.Num(); i++) {
		if (!seatAvailability[i]) {
			return seatLocs[i];
		}
	}
	return FVector::ZeroVector;
}


