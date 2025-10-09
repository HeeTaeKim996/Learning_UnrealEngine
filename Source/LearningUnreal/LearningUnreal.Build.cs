// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearningUnreal : ModuleRules
{
	public LearningUnreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",
		"EnhancedInput",
		"ModuleTest",
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] { "LearningUnreal" });
	}
}
