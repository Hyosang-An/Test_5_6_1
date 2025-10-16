// ============================================
// PlayerStatsWidget.h (Manual 방식)
// ============================================
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatsWidget.generated.h"

class UPlayerStatsViewModel;
class UButton;

UCLASS()
class TEST_5_6_1_API UPlayerStatsWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // Manual 방식: SetViewModelByClass 사용
    //UFUNCTION(BlueprintCallable, Category = "MVVM")
    void SetPlayerStatsViewModel(UPlayerStatsViewModel* InViewModel);

protected:
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UPROPERTY()
    TObjectPtr<UPlayerStatsViewModel> CachedViewModel;

    // 버튼들만 BindWidget
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> DamageButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> HealButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> AddScoreButton;

private:
    // ViewModel 변수 선언 불필요!
    // MVVMView Extension이 관리함

    UFUNCTION()
    void OnDamageButtonClicked();

    UFUNCTION()
    void OnHealButtonClicked();

    UFUNCTION()
    void OnAddScoreButtonClicked();
};
