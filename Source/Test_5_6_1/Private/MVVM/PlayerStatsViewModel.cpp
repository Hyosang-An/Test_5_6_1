// Fill out your copyright notice in the Description page of Project Settings.


#include "MVVM/PlayerStatsViewModel.h"

UPlayerStatsViewModel::UPlayerStatsViewModel()
{
	// 기본값 초기화
	Health = 100.0f;
	MaxHealth = 100.0f;
	Score = 0;
	PlayerName = FText::FromString(TEXT("Player"));
}

void UPlayerStatsViewModel::SetHealth(float NewHealth)
{
	// 값이 변경되었는지 확인
	if (Health != NewHealth)
	{
		// 0과 MaxHealth 사이로 제한
		float ClampedHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);

		// UE_MVVM_SET_PROPERTY_VALUE 매크로를 사용하여 변경 알림
		UE_MVVM_SET_PROPERTY_VALUE(Health, ClampedHealth);

		// HealthPercent와 IsAlive도 변경되었을 수 있으므로 알림
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealth);
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(IsAlive);
	}
}

void UPlayerStatsViewModel::SetMaxHealth(float NewMaxHealth)
{
	if (MaxHealth != NewMaxHealth && NewMaxHealth > 0.0f)
	{
		UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, NewMaxHealth);

		// MaxHealth가 변경되면 Health가 범위를 벗어날 수 있음
		if (Health > MaxHealth)
		{
			SetHealth(MaxHealth);
		}

		// HealthPercent도 변경됨
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
	}
}

void UPlayerStatsViewModel::SettingScore(int32 NewScore)
{
	UE_LOG(LogTemp,Warning, TEXT("SettingScore c++ called!!"))
	if (Score != NewScore)
	{
		UE_MVVM_SET_PROPERTY_VALUE(Score, NewScore);
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetScore);
	}
}

void UPlayerStatsViewModel::SetPlayerName(const FText& NewName)
{
	if (!PlayerName.EqualTo(NewName))
	{
		UE_MVVM_SET_PROPERTY_VALUE(PlayerName, NewName);
	}
}

float UPlayerStatsViewModel::GetHealthPercent() const
{
	if (MaxHealth > 0.0f)
	{
		return Health / MaxHealth;
	}
	return 0.0f;
}

void UPlayerStatsViewModel::AddScore(int32 Points)
{
	SettingScore(Score + Points);
}

void UPlayerStatsViewModel::TakeDamage(float DamageAmount)
{
	SetHealth(Health - DamageAmount);

	UE_LOG(LogTemp, Log, TEXT("Player took %f damage. Current Health: %f/%f"),
	       DamageAmount, Health, MaxHealth);
}

void UPlayerStatsViewModel::Heal(float HealAmount)
{
	SetHealth(Health + HealAmount);

	UE_LOG(LogTemp, Log, TEXT("Player healed %f. Current Health: %f/%f"),
	       HealAmount, Health, MaxHealth);
}
