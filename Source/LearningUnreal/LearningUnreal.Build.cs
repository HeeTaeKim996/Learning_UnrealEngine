// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearningUnreal : ModuleRules
{
	public LearningUnreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",

		"EnhancedInput", "GameplayTags",

		"NavigationSystem"/*네비게이션(탑다운)*/, "AIModule"/*인공지능*/ , "Niagara"/*커서이펙트*/,



		"ModuleTest",
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] { "LearningUnreal" });
	}
}
