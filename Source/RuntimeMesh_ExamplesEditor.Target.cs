// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RuntimeMesh_ExamplesEditorTarget : TargetRules
{
	public RuntimeMesh_ExamplesEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
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
