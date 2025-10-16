// Fill out your copyright notice in the Description page of Project Settings.


#include "MVVM/PlayerStatsWidget.h"

#include "MVVM/PlayerStatsViewModel.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"
#include "View/MVVMView.h"  // 중요!

void UPlayerStatsWidget::NativeConstruct()
{
    Super::NativeConstruct();

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

void UPlayerStatsWidget::SetPlayerStatsViewModel(UPlayerStatsViewModel* InViewModel)
{
    // MVVMView Extension 가져오기
    UMVVMView* View = GetExtension<UMVVMView>();
    check(View);

    // ViewModel 설정
    View->SetViewModelByClass(InViewModel);

    // 바인딩 강제 업데이트
    SynchronizeProperties();

    CachedViewModel = InViewModel;
}

void UPlayerStatsWidget::OnDamageButtonClicked()
{
    if (CachedViewModel)
    {
        CachedViewModel->TakeDamage(10.0f);
    }
}

void UPlayerStatsWidget::OnHealButtonClicked()
{
    if (CachedViewModel)
    {
        CachedViewModel->Heal(10.0f);
    }
}

void UPlayerStatsWidget::OnAddScoreButtonClicked()
{
    if (CachedViewModel)
    {
        CachedViewModel->AddScore(10.0f);
    }
}