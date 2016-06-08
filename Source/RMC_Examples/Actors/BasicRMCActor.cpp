// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#include "RMC_Examples.h"
#include "BasicRMCActor.h"

#include "RuntimeMeshLibrary.h"





void ABasicRMCActor::OnConstruction(const FTransform& Transform)
{
	TArray<FVector> Vertices;
	TArray<FVector> Normals;
	TArray<FRuntimeMeshTangent> Tangents;
	TArray<FVector2D> TextureCoordinates;
	TArray<int32> Triangles;

	URuntimeMeshLibrary::CreateBoxMesh(FVector(100, 100, 100), Vertices, Triangles, Normals, TextureCoordinates, Tangents);



	// Create the mesh section specifying collision
	RuntimeMesh->CreateMeshSection(0, Vertices, Triangles, Normals, TextureCoordinates, TArray<FColor>(), Tangents, true, EUpdateFrequency::Infrequent);
}
