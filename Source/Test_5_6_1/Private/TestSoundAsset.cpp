// TestSoundAsset.cpp
#include "TestSoundAsset.h"

void UTestSoundAsset::PostLoad()
{
	Super::PostLoad();
    
	UE_LOG(LogTemp, Error, TEXT(">>> [ASSET LOADED] %s"), *GetName());
}