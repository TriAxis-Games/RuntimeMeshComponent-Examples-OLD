// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#pragma once

#include "RuntimeMeshObjectBase.h"
#include "BasicRMCActor.generated.h"

/**
 * 
 */
UCLASS()
class RMC_EXAMPLES_API ABasicRMCActor : public ARuntimeMeshObjectBase
{
	GENERATED_BODY()

	void OnConstruction(const FTransform& Transform) override;
	
	
};
