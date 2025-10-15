// ============================================
// Test_5_6_1PlayerController.h
// ============================================
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Test_5_6_1PlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;
class UPlayerStatsViewModel;  // 추가
class UPlayerStatsWidget;     // 추가

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UCLASS(abstract)
class ATest_5_6_1PlayerController : public APlayerController
{
    GENERATED_BODY()
    
protected:

    /** Input Mapping Contexts */
    UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
    TArray<UInputMappingContext*> DefaultMappingContexts;

    /** Input Mapping Contexts */
    UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
    TArray<UInputMappingContext*> MobileExcludedMappingContexts;

    /** Mobile controls widget to spawn */
    UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
    TSubclassOf<UUserWidget> MobileControlsWidgetClass;

    /** Pointer to the mobile controls widget */
    TObjectPtr<UUserWidget> MobileControlsWidget;

    // ========== MVVM 관련 추가 ==========
    
    /** ViewModel 인스턴스 */
    UPROPERTY(BlueprintReadOnly, Category = "MVVM")
    TObjectPtr<UPlayerStatsViewModel> PlayerStatsViewModel;

    /** PlayerStats Widget 클래스 (에디터에서 WBP_PlayerStats 할당) */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UPlayerStatsWidget> PlayerStatsWidgetClass;

    /** PlayerStats Widget 인스턴스 */
    UPROPERTY()
    TObjectPtr<UPlayerStatsWidget> PlayerStatsWidget;

    // ====================================

    /** Gameplay initialization */
    virtual void BeginPlay() override;

    /** Input mapping context setup */
    virtual void SetupInputComponent() override;

private:
    /** PlayerStats UI 생성 함수 */
    void CreatePlayerStatsUI();

public:
    /** 외부에서 ViewModel 접근용 */
    UFUNCTION(BlueprintCallable, Category = "MVVM")
    UPlayerStatsViewModel* GetPlayerStatsViewModel() const { return PlayerStatsViewModel; }
};