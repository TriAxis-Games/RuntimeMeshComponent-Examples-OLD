// Copyright 2016-2019 Chris Conway (Koderz). All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RuntimeMeshExamplesEditorTarget : TargetRules
{
	public RuntimeMeshExamplesEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("RuntimeMeshExamples");
	}
}
