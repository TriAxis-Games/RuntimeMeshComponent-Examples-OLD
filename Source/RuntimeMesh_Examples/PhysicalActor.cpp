// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#include "RuntimeMesh_Examples.h"
#include "PhysicalActor.h"
#include "RuntimeMeshLibrary.h"




	

struct FMyCustomVertex 
{
	DECLARE_RUNTIMEMESH_VERTEXTYPEINFO_SIMPLE(FMyCustomVertex, FGuid(0x2CB42002, 0x83734382, 0xA3A03D07, 0x3896C852))

	FMyCustomVertex() : Position(0.0f, 0.0f, 0.0f), Normal(FVector(0.0f, 0.0f, 1.0f)), Tangent(FVector(1.0f, 0.0f, 0.0f)), Color(255, 255, 255), TextureCoordinate(0, 0), TextureIndices(0, 0) { }

	FMyCustomVertex(const FVector& Position, const FVector& Normal, const FVector& Tangent, FColor Color, FVector2DHalf TextureCoordinate, FVector2DHalf TextureIndices)
		: Position(Position), Normal(Normal), Tangent(Tangent), Color(Color), TextureCoordinate(TextureCoordinate), TextureIndices(TextureIndices)
	{
		this->Normal.Vector.W = 255;
	}

	FMyCustomVertex(const FVector& Position, const FVector& Normal, const FVector& Tangent, bool bFlipTangentY, FColor Color, FVector2DHalf TextureCoordinate, FVector2DHalf TextureIndices)
		: Position(Position), Normal(Normal), Tangent(Tangent), Color(Color), TextureCoordinate(TextureCoordinate), TextureIndices(TextureIndices)
	{
		this->Normal.Vector.W = bFlipTangentY ? 0 : 255;
	}

	/** Vertex position */
	FVector Position;

	/** Vertex normal */
	FPackedNormal Normal;

	/** Vertex tangent */
	FPackedNormal Tangent;

	/** Vertex texture co-ordinate */
	FVector2DHalf TextureCoordinate;
	FVector2DHalf TextureIndices;

	/** Vertex color */
	FColor Color;

	static RuntimeMeshVertexStructure GetVertexStructure(const FRuntimeMeshVertexBuffer<FMyCustomVertex>& VertexBuffer)
	{
		RuntimeMeshVertexStructure VertexStructure;

		VertexStructure.PositionComponent = RUNTIMEMESH_VERTEXCOMPONENT(VertexBuffer, FMyCustomVertex, Position, VET_Float3);
		VertexStructure.TextureCoordinates.Add(RUNTIMEMESH_VERTEXCOMPONENT(VertexBuffer, FMyCustomVertex, TextureCoordinate, VET_Half4));
		VertexStructure.TangentBasisComponents[0] = RUNTIMEMESH_VERTEXCOMPONENT(VertexBuffer, FMyCustomVertex, Tangent, VET_PackedNormal);
		VertexStructure.TangentBasisComponents[1] = RUNTIMEMESH_VERTEXCOMPONENT(VertexBuffer, FMyCustomVertex, Normal, VET_PackedNormal);
		VertexStructure.ColorComponent = RUNTIMEMESH_VERTEXCOMPONENT(VertexBuffer, FMyCustomVertex, Color, VET_Color);

		return VertexStructure;
	}

};
DEFINE_RUNTIMEMESH_VERTEXTYPEINFO(FMyCustomVertex)



void GenerateBoxMesh(const FVector& Size, TArray<MyVertex>& Vertices, TArray<FVector>& VertexPositions, TArray<MyDualVertex>& VertexData, TArray<int32>& Triangles)
{
	Vertices.Empty();
	Triangles.Empty();

	TArray<FVector> Positions;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FRuntimeMeshTangent> Tangents;

	URuntimeMeshLibrary::GenerateBoxMesh(Size, Positions, Triangles, Normals, UVs, Tangents);


	Vertices.SetNum(Positions.Num());
	VertexData.SetNum(Positions.Num());
	VertexPositions.SetNum(Positions.Num());
	for (int32 Index = 0; Index < Positions.Num(); Index++)
	{
		Vertices[Index].Position = Positions[Index];
		Vertices[Index].Normal = Normals[Index];
		Vertices[Index].Tangent = Tangents[Index].TangentX;
		Vertices[Index].UV0 = UVs[Index];

		VertexData[Index].Normal = Normals[Index];
		VertexData[Index].Tangent = Tangents[Index].TangentX;
		VertexData[Index].UV0 = UVs[Index];

		VertexPositions[Index] = Positions[Index];
	}

}


// Sets default values
APhysicalActor::APhysicalActor() : Size(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = MeshComponent = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("MeshObject"));
	MeshComponent->bShouldSerializeMeshData = false;


// 	TArray<MyVertex> Vertices;
// 	TArray<int32> Triangles;
// 
 	GenerateBoxMesh(FVector(100, 100, 100), Vertices, Positions, VertexData, Triangles);
 
//   	Vertices.SetNumZeroed(20000);
//   	VertexData.SetNumZeroed(20000);
//   	Positions.SetNumZeroed(20000);
//   	Triangles.SetNum(30000);
  	static FBox BoundingBox(FVector(-100, -100, -100), FVector(100, 100, 100));


	//GenerateBoxMesh(FVector(100, 100, 100), Vertices, Positions, VertexData, Triangles);

	MeshComponent->CreateMeshSection<MyVertex>(0, Vertices, Triangles, false, EUpdateFrequency::Frequent);
	MeshComponent->CreateMeshSectionDualBuffer<MyDualVertex>(1, Positions, VertexData, Triangles, false, EUpdateFrequency::Frequent);


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


// 	GenerateBoxMesh(FVector(100 + (Size * 50), 100 + (Size * 50), 100 + (Size * 50)), Vertices, Positions, VertexData, Triangles);
// 
 	TArray<MyVertex> TempVertices = Vertices;
 	static FBox BoundingBox(FVector(-100, -100, -100), FVector(100, 100, 100));


	MeshComponent->UpdateMeshSection(0, TempVertices, BoundingBox, ESectionUpdateFlags::MoveArrays);
	MeshComponent->UpdateMeshSectionPositionsImmediate(1, Positions, BoundingBox);


	Super::Tick( DeltaTime );
}

