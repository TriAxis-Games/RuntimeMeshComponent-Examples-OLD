// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeMeshBasic.h"
#include "RuntimeMeshComponent.h"
#include "RuntimeMeshShapeGenerator.h"
#include "RuntimeMeshBuilder.h"
#include "RuntimeMeshLibrary.h"
#include "RuntimeMeshData.h"
#include "RuntimeMesh.h"


// Sets default values
ARuntimeMeshBasic::ARuntimeMeshBasic()
	: BoxSize(100.0f, 100.0f, 100.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



void ARuntimeMeshBasic::GenerateMeshes_Implementation()
{
/*	TSharedPtr<FRuntimeMeshBuilder> Builder = MakeRuntimeMeshBuilder<FRuntimeMeshTangentsHighPrecision, FRuntimeMeshDualUV, uint16>();*/

FRuntimeMeshDataPtr Data = GetRuntimeMeshComponent()->GetOrCreateRuntimeMesh()->GetRuntimeMeshData();

Data->CreateMeshSection(0, false, false, 1, false, true, EUpdateFrequency::Average);

auto Section = Data->BeginSectionUpdate(0);

URuntimeMeshShapeGenerator::CreateBoxMesh(BoxSize, *Section.Get());

Section->Commit();


TArray<FRuntimeMeshVertexSimple> Vertices;
TArray<int32> Triangles;
URuntimeMeshShapeGenerator::CreateBoxMesh(BoxSize, Vertices, Triangles);

Data->CreateMeshSection(0, Vertices, Triangles, true);


Data->UpdateMeshSection(0, Vertices, Triangles);

// 	URuntimeMeshShapeGenerator::CreateBoxMesh(BoxSize, Builder);
// 
// 	FVector4 TestNormal = Builder->GetNormal(0);
// 	FVector TestTangent = Builder->GetTangent(0);
// 
// 	GetRuntimeMeshComponent()->CreateMeshSection(0, Builder, true, EUpdateFrequency::Infrequent);


// 	TSharedPtr<FRuntimeMeshBuilder> Builder2 = MakeRuntimeMeshBuilder<FVector, FRuntimeMeshVertexNoPosition, uint16>();
// 	URuntimeMeshShapeGenerator::CreateBoxMesh(BoxSize * 0.75, Builder2);
// 
// 
// 	GetRuntimeMeshComponent()->GetOrCreateRuntimeMesh()->GetRuntimeMeshData()->CreateMeshSectionDualBuffer<FVector, FRuntimeMeshVertexNoPosition, uint16>(0, false, EUpdateFrequency::Infrequent, 2);
// 	GetRuntimeMeshComponent()->GetRuntimeMesh()->GetRuntimeMeshData()->UpdateMeshSectionLOD(0, 0, Builder);
// 	GetRuntimeMeshComponent()->GetRuntimeMesh()->GetRuntimeMeshData()->UpdateMeshSectionLOD(0, 1, Builder2);

//GetRuntimeMeshComponent()->GetRuntimeMesh()->GetRuntimeMeshData()->CreateMeshSection(0, Builder, true, EUpdateFrequency::Infrequent, ESectionUpdateFlags::CalculateNormalTangentHard
}

