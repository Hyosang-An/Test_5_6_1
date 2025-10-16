// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "PlayerStatsViewModel.generated.h"

/**
 * 
 */
UCLASS()
class TEST_5_6_1_API UPlayerStatsViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UPlayerStatsViewModel();

	// Health 속성
	UFUNCTION(BlueprintPure, FieldNotify)
	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable)
	void SetHealth(float NewHealth);

	// MaxHealth 속성
	UFUNCTION(BlueprintPure, FieldNotify)
	float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float NewMaxHealth);

	// Score 속성
	UFUNCTION(BlueprintPure, FieldNotify)
	int32 GetScore() const
	{
		UE_LOG(LogTemp, Warning, TEXT("C++ GetScore!!"))
		return Score;
	}

	//UFUNCTION(BlueprintCallable)
	void SettingScore(int32 NewScore);

	// PlayerName 속성
	UFUNCTION(BlueprintPure, FieldNotify)
	FText GetPlayerName() const { return PlayerName; }

	UFUNCTION(BlueprintCallable)
	void SetPlayerName(const FText& NewName);

	// 계산된 속성 (Health 퍼센트)
	UFUNCTION(BlueprintPure, FieldNotify)
	float GetHealthPercent() const;

	// 플레이어가 살아있는지 확인
	UFUNCTION(BlueprintPure, FieldNotify)
	bool IsAlive() const { return Health > 0.0f; }

	// 점수 추가 액션
	UFUNCTION(BlueprintCallable)
	void AddScore(int32 Points);

	// 데미지 받기 액션
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float DamageAmount);

	// 힐 받기 액션
	UFUNCTION(BlueprintCallable)
	void Heal(float HealAmount);

private:
	// FieldNotify를 사용하여 자동으로 UI에 알림
	UPROPERTY(FieldNotify, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float Health;

	UPROPERTY(FieldNotify, Setter, Getter)
	float MaxHealth;

	UPROPERTY(FieldNotify, Setter=SettingScore, BlueprintReadWrite, meta = (AllowPrivateAccess))
	int32 Score;

	UPROPERTY(FieldNotify, Setter, Getter)
	FText PlayerName;
};
