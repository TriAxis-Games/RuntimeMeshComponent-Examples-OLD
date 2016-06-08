// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#include "RMC_Examples.h"
#include "AnimatedTerrain.h"
#include "RuntimeMeshLibrary.h"

// Sets default values
AAnimatedTerrain::AAnimatedTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnimatedTerrain::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAnimatedTerrain::Generate()
{
	Positions.Empty();
	VertexData.Empty();
	Triangles.Empty();


	// Oversized bounding box so we don't have to update it
	BoundingBox = FBox(FVector(-HalfWidth * CellSize, -HalfWidth * CellSize, -100), FVector(HalfWidth * CellSize, HalfWidth * CellSize, 100));

	// Create the vertex array
	for (int32 YIndex = -HalfWidth; YIndex < HalfWidth; YIndex++)
	{
		for (int32 XIndex = -HalfWidth; XIndex < HalfWidth; XIndex++)
		{
			Positions.Add(FVector(XIndex * CellSize, YIndex * CellSize, 0));
			VertexData.Add(FRuntimeMeshVertexNoPosition(FVector(0, 0, 1), FRuntimeMeshTangent(-1, 0, 0), FVector2D(XIndex, YIndex)));
		}
	}

	// Create the triangle array
	URuntimeMeshLibrary::CreateGridMeshTriangles(HalfWidth * 2, HalfWidth * 2, true, Triangles);


	// Here we're going to use a dual buffer section for performance since we'll be updating positions only each frame
	RuntimeMesh->CreateMeshSectionDualBuffer(0, Positions, VertexData, Triangles, BoundingBox, false, EUpdateFrequency::Frequent);
}

// Called every frame
void AAnimatedTerrain::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (Positions.Num() <= 0)
	{
		Generate();
	}

	float AnimationStepX = 5; 
	float AnimationStepY = 6;
	
	AnimationOffsetX += DeltaTime * AnimationStepX;
	AnimationOffsetY += DeltaTime * AnimationStepY;
	

	int32 Index = 0;
	for (int32 YIndex = -HalfWidth; YIndex < HalfWidth; YIndex++)
	{
		for (int32 XIndex = -HalfWidth; XIndex < HalfWidth; XIndex++)
		{
			float Scale = FMath::Cos(XIndex + AnimationOffsetX) + FMath::Sin(YIndex + AnimationOffsetY);

			Positions[Index++].Z = Scale * Height;
		}
	}


	// Update positions
	RuntimeMesh->UpdateMeshSectionPositionsImmediate(0, Positions, BoundingBox);
}



void AAnimatedTerrain::OnConstruction(const FTransform& Transform)
{
	Generate();
}

