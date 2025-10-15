// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Test_5_6_1 : ModuleRules
{
	public Test_5_6_1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"ModelViewViewModel"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Test_5_6_1",
			"Test_5_6_1/Variant_Platforming",
			"Test_5_6_1/Variant_Platforming/Animation",
			"Test_5_6_1/Variant_Combat",
			"Test_5_6_1/Variant_Combat/AI",
			"Test_5_6_1/Variant_Combat/Animation",
			"Test_5_6_1/Variant_Combat/Gameplay",
			"Test_5_6_1/Variant_Combat/Interfaces",
			"Test_5_6_1/Variant_Combat/UI",
			"Test_5_6_1/Variant_SideScrolling",
			"Test_5_6_1/Variant_SideScrolling/AI",
			"Test_5_6_1/Variant_SideScrolling/Gameplay",
			"Test_5_6_1/Variant_SideScrolling/Interfaces",
			"Test_5_6_1/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
