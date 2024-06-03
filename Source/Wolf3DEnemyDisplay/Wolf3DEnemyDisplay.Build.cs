// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Wolf3DEnemyDisplay : ModuleRules
{
	public Wolf3DEnemyDisplay(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
