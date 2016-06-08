// Fill out your copyright notice in the Description page of Project Settings.

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

	float ScaleFactor = 1.0f;
	float AnimationSpeedX = 4.0f; 
	float AnimationSpeedY = 4.5f;
	
	CurrentAnimationFrameX += DeltaTime * AnimationSpeedX;
	CurrentAnimationFrameY += DeltaTime * AnimationSpeedY;
	

	int32 Index = 0;
	for (int32 YIndex = -HalfWidth; YIndex < HalfWidth; YIndex++)
	{
		for (int32 XIndex = -HalfWidth; XIndex < HalfWidth; XIndex++)
		{
			float ValueOne = FMath::Cos((XIndex + CurrentAnimationFrameX)*ScaleFactor) + FMath::Sin((YIndex + CurrentAnimationFrameY)*ScaleFactor);
			float ValueTwo = FMath::Cos((XIndex + CurrentAnimationFrameX*0.7f)*ScaleFactor*2.5f) + FMath::Sin((YIndex - CurrentAnimationFrameY*0.7f)*ScaleFactor*2.5f);


			Positions[Index++].Z = ((ValueOne + ValueTwo) / 2) * Height;
		}
	}


	// Update positions
	RuntimeMesh->UpdateMeshSectionPositionsImmediate(0, Positions, BoundingBox);
}



void AAnimatedTerrain::OnConstruction(const FTransform& Transform)
{
	Generate();
}

