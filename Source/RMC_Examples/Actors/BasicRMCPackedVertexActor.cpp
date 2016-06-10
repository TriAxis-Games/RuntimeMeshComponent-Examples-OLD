// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#include "RMC_Examples.h"
#include "BasicRMCPackedVertexActor.h"

#include "RuntimeMeshLibrary.h"


/* Helper to generate a box mesh and convert it to FRuntimeMeshVertexSimple */
void ABasicRMCPackedVertexActor::CreateBoxMesh(const FVector& Size, TArray<FRuntimeMeshVertexSimple>& Vertices, TArray<int32>& Triangles)
{
	Vertices.Empty();
	Triangles.Empty();

	TArray<FVector> Positions;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FRuntimeMeshTangent> Tangents;

	URuntimeMeshLibrary::CreateBoxMesh(Size, Positions, Triangles, Normals, UVs, Tangents);


	Vertices.SetNum(Positions.Num());
	for (int32 Index = 0; Index < Positions.Num(); Index++)
	{
		Vertices[Index].Position = Positions[Index];
		Vertices[Index].Normal = Normals[Index];
		Vertices[Index].Tangent = Tangents[Index].TangentX;
		Vertices[Index].UV0 = UVs[Index];
	}
}

void ABasicRMCPackedVertexActor::Generate()
{
	TArray<FRuntimeMeshVertexSimple> Vertices;
	TArray<int32> Triangles;

	CreateBoxMesh(FVector(100, 100, 100), Vertices, Triangles);

	// Create the mesh section  (also enables collision, and sets the section update frequency to infrequent)
	RuntimeMesh->CreateMeshSection(0, Vertices, Triangles, true, EUpdateFrequency::Infrequent);
}

void ABasicRMCPackedVertexActor::BeginPlay()
{
	// These types of sections can't be serialized currently.
	// So check if it was already created and if not create it now
	if (!RuntimeMesh->DoesSectionExist(0))
	{
		Generate();
	}
}

void ABasicRMCPackedVertexActor::OnConstruction(const FTransform& Transform)
{
	Generate();
}

