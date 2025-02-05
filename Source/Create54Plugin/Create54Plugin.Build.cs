// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Create54Plugin : ModuleRules
{
	public Create54Plugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
