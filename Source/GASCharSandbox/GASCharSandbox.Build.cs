// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASCharSandbox : ModuleRules
{
	public GASCharSandbox(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "EnhancedInput", "GameplayAbilities" });

        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" });
    }
}
