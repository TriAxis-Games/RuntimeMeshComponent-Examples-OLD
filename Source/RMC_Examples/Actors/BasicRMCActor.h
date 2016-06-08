// Fill out your copyright notice in the Description page of Project Settings.

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
