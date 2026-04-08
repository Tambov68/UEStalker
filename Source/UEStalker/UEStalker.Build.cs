// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UEStalker : ModuleRules
{
	public UEStalker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"Paper2D", 
			"EnhancedInput",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { 
			"Slate",
			"SlateCore"
		});
		
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(new string[]
			{
				"UnrealEd",
				"PropertyEditor",
				"AssetRegistry",
				"AnimationBlueprintLibrary"
			});
		}
	}
}
