// Fill out your copyright notice in the Description page of Project Settings.


#include "MVVM/PlayerStatsWidget.h"

#include "MVVM/PlayerStatsViewModel.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"

void UPlayerStatsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 버튼 이벤트 바인딩
	if (DamageButton)
	{
		DamageButton->OnClicked.AddDynamic(this, &UPlayerStatsWidget::OnDamageButtonClicked);
	}

	if (HealButton)
	{
		HealButton->OnClicked.AddDynamic(this, &UPlayerStatsWidget::OnHealButtonClicked);
	}

	if (AddScoreButton)
	{
		AddScoreButton->OnClicked.AddDynamic(this, &UPlayerStatsWidget::OnAddScoreButtonClicked);
	}
}

void UPlayerStatsWidget::NativeDestruct()
{
	// 버튼 이벤트 언바인딩
	if (DamageButton)
	{
		DamageButton->OnClicked.RemoveDynamic(this, &UPlayerStatsWidget::OnDamageButtonClicked);
	}

	if (HealButton)
	{
		HealButton->OnClicked.RemoveDynamic(this, &UPlayerStatsWidget::OnHealButtonClicked);
	}

	if (AddScoreButton)
	{
		AddScoreButton->OnClicked.RemoveDynamic(this, &UPlayerStatsWidget::OnAddScoreButtonClicked);
	}

	Super::NativeDestruct();
}

void UPlayerStatsWidget::OnDamageButtonClicked()
{
	if (ViewModel)
	{
		ViewModel->TakeDamage(10.0f);
		// MVVM 바인딩 덕분에 UI 자동 업데이트
	}
}

void UPlayerStatsWidget::OnHealButtonClicked()
{
	if (ViewModel)
	{
		ViewModel->Heal(15.0f);
	}
}

void UPlayerStatsWidget::OnAddScoreButtonClicked()
{
	if (ViewModel)
	{
		ViewModel->AddScore(100);
	}
}