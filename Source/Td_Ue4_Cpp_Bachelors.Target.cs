// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Td_Ue4_Cpp_BachelorsTarget : TargetRules
{
	public Td_Ue4_Cpp_BachelorsTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Td_Ue4_Cpp_Bachelors" } );
	}
}
