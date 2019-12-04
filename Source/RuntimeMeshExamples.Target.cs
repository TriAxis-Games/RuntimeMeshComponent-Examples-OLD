// Copyright 2016-2019 Chris Conway (Koderz). All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RuntimeMeshExamplesTarget : TargetRules
{
	public RuntimeMeshExamplesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("RuntimeMeshExamples");
	}
}
