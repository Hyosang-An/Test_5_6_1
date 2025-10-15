// TestSoundAsset.h
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TestSoundAsset.generated.h"

UCLASS(BlueprintType)
class TEST_5_6_1_API UTestSoundAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundWave* SoundData;

	virtual void PostLoad() override;
};