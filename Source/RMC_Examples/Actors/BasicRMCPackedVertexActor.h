// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

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

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* Helper to generate a box mesh and convert it to FRuntimeMeshVertexSimple */
	void CreateBoxMesh(const FVector& Size, TArray<FRuntimeMeshVertexSimple>& Vertices, TArray<int32>& Triangles);
	
	void Generate();
	
};
