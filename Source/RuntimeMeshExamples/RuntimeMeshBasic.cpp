// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeMeshBasic.h"
#include "RuntimeMeshComponent.h"
#include "RuntimeMeshShapeGenerator.h"
#include "RuntimeMeshBuilder.h"


// Sets default values
ARuntimeMeshBasic::ARuntimeMeshBasic()
	: BoxSize(100.0f, 100.0f, 100.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARuntimeMeshBasic::OnConstruction(const FTransform& Transform)
{
	FRuntimeMeshBuilder Builder = MakeRuntimeMeshBuilder<FVector, FRuntimeMeshVertexNoPosition, uint16>();
	
	URuntimeMeshShapeGenerator::CreateBoxMesh(BoxSize, Builder);

	GetRuntimeMeshComponent()->CreateMeshSection(0, Builder, true, EUpdateFrequency::Infrequent);

// 	TArray<FRuntimeMeshVertexSimple> Vertices;
// 	TArray<int32> Triangles;
// 
// 	URuntimeMeshShapeGenerator::CreateBoxMesh(BoxSize, Vertices, Triangles);
// 
// 	GetRuntimeMeshComponent()->GetOrCreateRuntimeMesh()->CreateMeshSection<FRuntimeMeshVertexSimple, int32>(0, true, EUpdateFrequency::Infrequent);


	//GetRuntimeMeshComponent()->GetOrCreateRuntimeMesh()->CreateMeshSection(0, Vertices, Triangles, true, EUpdateFrequency::Infrequent);
}

DECLARE_RUNTIME_MESH_VERTEX(FTestVertex, false, true, true, false, 1, ERuntimeMeshVertexTangentBasisType::Default, ERuntimeMeshVertexUVType::Default);



// Called when the game starts or when spawned
void ARuntimeMeshBasic::BeginPlay()
{
// 	TArray<FRuntimeMeshVertexSimple> Vertices;
// 	TArray<int32> Triangles;
// 
// 	URuntimeMeshShapeGenerator::CreateBoxMesh(BoxSize * 2, Vertices, Triangles);
// 
// 	GetRuntimeMeshComponent()->GetRuntimeMesh()->UpdateMeshSection(0, Vertices, Triangles);

	FRuntimeMeshBuilder Builder = MakeRuntimeMeshBuilder<FVector, FRuntimeMeshVertexNoPosition, uint16>();

	URuntimeMeshShapeGenerator::CreateBoxMesh(BoxSize, Builder);

	GetRuntimeMeshComponent()->UpdateMeshSection(0, MoveTemp(Builder));


	FRuntimeMeshDataPtr MesHData = GetRuntimeMeshComponent()->GetRuntimeMesh()->GetRuntimeMeshData();

	// Open section 0 in a scoped update
	{	
// 		FRuntimeMeshScopedUpdater MeshSection(MesHData, 0);
// 				
// 		MeshSection.SetPosition(0, FVector(15, 0, 0));
// 		MeshSection.SetColor(12, FColor::Blue);

	}

	Super::BeginPlay();
	
}

// Called every frame
void ARuntimeMeshBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

