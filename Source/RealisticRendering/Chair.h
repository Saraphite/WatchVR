// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Chair.generated.h"

UCLASS()
class REALISTICRENDERING_API AChair : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AChair();
	AChair(int numberOfSeats);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		int32 seatCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		TArray<FVector> seatLocs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		TArray<bool> seatAvailability;

	//Returns the vector position that the player camera would sit.
	UFUNCTION(BlueprintCallable, Category = Functionality)
	virtual FVector SitOnChair();

	UFUNCTION(BlueprintCallable, Category = Functionality)
	virtual FVector SitOnClosestChair(FVector selectionPoint);


};
