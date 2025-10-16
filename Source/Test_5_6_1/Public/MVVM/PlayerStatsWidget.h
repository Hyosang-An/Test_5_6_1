// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatsWidget.generated.h"

class UPlayerStatsViewModel;
class UTextBlock;
class UProgressBar;
class UButton;

/**
 * 
 */
UCLASS()
class TEST_5_6_1_API UPlayerStatsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// ViewModel - WBP에서 바인딩용
	UPROPERTY(BlueprintReadWrite, Category = "MVVM")
	TObjectPtr<UPlayerStatsViewModel> ViewModel;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	// BindWidget 제거! 버튼만 남김
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> DamageButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> HealButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> AddScoreButton;

private:
	UFUNCTION()
	void OnDamageButtonClicked();

	UFUNCTION()
	void OnHealButtonClicked();

	UFUNCTION()
	void OnAddScoreButtonClicked();
};

// Commit, Push Test