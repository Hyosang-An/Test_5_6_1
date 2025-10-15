#include "Test_5_6_1PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "Test_5_6_1.h"
#include "Widgets/Input/SVirtualJoystick.h"
#include "MVVM/PlayerStatsViewModel.h"  // 추가
#include "MVVM/PlayerStatsWidget.h"     // 추가

void ATest_5_6_1PlayerController::BeginPlay()
{
    Super::BeginPlay();

    // ========== 기존 코드 ==========
    // only spawn touch controls on local player controllers
    if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
    {
       // spawn the mobile controls widget
       MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

       if (MobileControlsWidget)
       {
          // add the controls to the player screen
          MobileControlsWidget->AddToPlayerScreen(0);

       } else {

          UE_LOG(LogTest_5_6_1, Error, TEXT("Could not spawn mobile controls widget."));

       }
    }

    // ========== MVVM 코드 추가 ==========
    // ViewModel 생성
    PlayerStatsViewModel = NewObject<UPlayerStatsViewModel>(this);
    
    if (PlayerStatsViewModel)
    {
        // 초기 데이터 설정
        PlayerStatsViewModel->SetPlayerName(FText::FromString(TEXT("Hero")));
        PlayerStatsViewModel->SetHealth(100.0f);
        PlayerStatsViewModel->SetMaxHealth(100.0f);
        PlayerStatsViewModel->SetScore(0);

        UE_LOG(LogTest_5_6_1, Log, TEXT("PlayerStatsViewModel created"));
    }

    // PlayerStats UI 생성
    CreatePlayerStatsUI();
    // ===================================
}

void ATest_5_6_1PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // only add IMCs for local player controllers
    if (IsLocalPlayerController())
    {
       // Add Input Mapping Contexts
       if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
       {
          for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
          {
             Subsystem->AddMappingContext(CurrentContext, 0);
          }

          // only add these IMCs if we're not using mobile touch input
          if (!SVirtualJoystick::ShouldDisplayTouchInterface())
          {
             for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
             {
                Subsystem->AddMappingContext(CurrentContext, 0);
             }
          }
       }
    }
}

void ATest_5_6_1PlayerController::CreatePlayerStatsUI()
{
    if (!PlayerStatsWidgetClass)
    {
        UE_LOG(LogTest_5_6_1, Warning, TEXT("PlayerStatsWidgetClass is not set. Please assign WBP_PlayerStats in the editor."));
        return;
    }

    // Widget 생성
    PlayerStatsWidget = CreateWidget<UPlayerStatsWidget>(this, PlayerStatsWidgetClass);
    
    if (PlayerStatsWidget)
    {
        // ViewModel을 Widget에 할당
        PlayerStatsWidget->ViewModel = PlayerStatsViewModel;
        
        // 뷰포트에 추가
        PlayerStatsWidget->AddToViewport();
        
        UE_LOG(LogTest_5_6_1, Log, TEXT("PlayerStats UI created successfully"));
    }
    else
    {
        UE_LOG(LogTest_5_6_1, Error, TEXT("Failed to create PlayerStatsWidget"));
    }
}