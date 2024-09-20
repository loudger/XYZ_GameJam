// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class XYZ_GameJam_Project : ModuleRules
{
	public XYZ_GameJam_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
