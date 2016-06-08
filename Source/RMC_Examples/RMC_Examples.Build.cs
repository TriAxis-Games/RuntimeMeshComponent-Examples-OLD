// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

using UnrealBuildTool;

public class RMC_Examples : ModuleRules
{
	public RMC_Examples(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore"});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

	    PublicDependencyModuleNames.AddRange(new string[] { "ShaderCore", "RenderCore", "RHI", "RuntimeMeshComponent"});



	    // Uncomment if you are using Slate UI
	    // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

	    // Uncomment if you are using online features
	    // PrivateDependencyModuleNames.Add("OnlineSubsystem");
	    // if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
	    // {
	    //		if (UEBuildConfiguration.bCompileSteamOSS == true)
	    //		{
	    //			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
	    //		}
	    // }
	}
}
