// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);

class UTestSoundAsset;

UCLASS()
class TEST_5_6_1_API ATestActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 하드 참조
	UPROPERTY(EditDefaultsOnly, Category = "Test")
	TObjectPtr<UTestSoundAsset> MySoundAsset;

	UPROPERTY(BLueprintCallable)
	FOnHealthChanged OnHealthChanged;
};
