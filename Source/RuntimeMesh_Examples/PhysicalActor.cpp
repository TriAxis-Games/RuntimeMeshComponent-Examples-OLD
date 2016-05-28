// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#include "RuntimeMesh_Examples.h"
#include "PhysicalActor.h"
#include "RuntimeMeshLibrary.h"



void GenerateBoxMesh(const FVector& Size, TArray<MyVertex>& Vertices, TArray<int32>& Triangles)
{
	Vertices.Empty();
	Triangles.Empty();


	TArray<FVector> Positions;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FRuntimeMeshTangent> Tangents;

	URuntimeMeshLibrary::GenerateBoxMesh(Size, Positions, Triangles, Normals, UVs, Tangents);


	Vertices.SetNum(Positions.Num());
	for (int32 Index = 0; Index < Positions.Num(); Index++)
	{
		Vertices[Index].Position = Positions[Index];
		Vertices[Index].Normal = Normals[Index];
		Vertices[Index].Tangent = Tangents[Index].TangentX;
		//Vertices[Index].UV0 = UVs[Index];
	}

}


// Sets default values
APhysicalActor::APhysicalActor() : Size(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = MeshComponent = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("MeshObject"));

// 	TArray<MyVertex> Vertices;
// 	TArray<int32> Triangles;
// 
// 	GenerateBoxMesh(FVector(100, 100, 100), Vertices, Triangles);

	Vertices.SetNumZeroed(20000);
	Triangles.SetNum(30000);
	static FBox BoundingBox(FVector(-100, -100, -100), FVector(100, 100, 100));

	//MeshComponent->CreateMeshSection<MyVertex>(0, Vertices, Triangles, false, EUpdateFrequency::Frequent);



}

// Called when the game starts or when spawned
void APhysicalActor::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void APhysicalActor::Tick( float DeltaTime )
{
	Size += DeltaTime * Direction;
	if (Size > 1 || Size < 0)
		Direction *= -1;


	//GenerateBoxMesh(FVector(100 + (Size * 50), 100 + (Size * 50), 100 + (Size * 50)), Vertices, Triangles);

	TArray<MyVertex> TempVertices = Vertices;
	static FBox BoundingBox(FVector(-100, -100, -100), FVector(100, 100, 100));

	//MeshComponent->UpdateMeshSection<MyVertex>(0, TempVertices, BoundingBox, ESectionUpdateFlags::MoveArrays);


	Super::Tick( DeltaTime );
}

