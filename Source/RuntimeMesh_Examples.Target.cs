// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RuntimeMesh_ExamplesTarget : TargetRules
{
	public RuntimeMesh_ExamplesTarget(TargetInfo Target)
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
		OutExtraModuleNames.AddRange( new string[] { "RuntimeMesh_Examples" } );
	}
}
