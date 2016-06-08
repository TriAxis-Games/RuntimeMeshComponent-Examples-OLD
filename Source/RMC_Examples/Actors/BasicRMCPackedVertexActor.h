// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RuntimeMeshObjectBase.h"
#include "BasicRMCPackedVertexActor.generated.h"

/**
 * 
 */
UCLASS()
class RMC_EXAMPLES_API ABasicRMCPackedVertexActor : public ARuntimeMeshObjectBase
{
	GENERATED_BODY()

		void OnConstruction(const FTransform& Transform) override;


	/* Helper to generate a box mesh and convert it to FRuntimeMeshVertexSimple */
	void CreateBoxMesh(const FVector& Size, TArray<FRuntimeMeshVertexSimple>& Vertices, TArray<int32>& Triangles);
	
	
};
