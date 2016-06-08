// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RMC_ExamplesTarget : TargetRules
{
	public RMC_ExamplesTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "RMC_Examples" } );
	}
}
