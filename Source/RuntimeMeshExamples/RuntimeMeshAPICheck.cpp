// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeMeshBasic.h"
#include "RuntimeMeshComponent.h"
#include "RuntimeMeshShapeGenerator.h"

DECLARE_RUNTIME_MESH_VERTEX(FRuntimeMeshVertexNoPositionOrColor, false, true, true, false, 1, ERuntimeMeshVertexTangentBasisType::Default, ERuntimeMeshVertexUVType::HighPrecision)

/*
*	This class's sole purpose is to instantiate all the variations of the template functions on the RM and RMC.
*	This is so that the compiler will actually validate it
*/
struct FRuntimeMeshComponentAPIChecker
{
	static void APITest()
	{
		URuntimeMesh* Mesh;

		TArray<FRuntimeMeshVertexSimple> SimpleVerts;
		TArray<FRuntimeMeshVertexNoPosition> NoPositionVerts;
		TArray<FRuntimeMeshVertexNoPositionOrColor> NoPositionOrColorVerts;
		TArray<FVector> Vectors;
		TArray<FColor> Colors;
		TArray<FRuntimeMeshTangent> Tangents;
		TArray<int32> Triangles;

		Mesh->CreateMeshSection<FRuntimeMeshVertexSimple, int32>(0);
		Mesh->CreateMeshSectionDualBuffer<FVector, FRuntimeMeshVertexNoPosition, int32>(0);
		Mesh->CreateMeshSectionTripleBuffer<FVector, FRuntimeMeshVertexNoPositionOrColor, FColor, int32>(0);


		Mesh->CreateMeshSection(0, SimpleVerts, Triangles);
		Mesh->CreateMeshSection(0, SimpleVerts, Triangles, FBox());
		Mesh->CreateMeshSectionDualBuffer(0, Vectors, NoPositionVerts, Triangles);
		Mesh->CreateMeshSectionDualBuffer(0, Vectors, NoPositionVerts, Triangles, FBox());
		Mesh->CreateMeshSectionTripleBuffer(0, Vectors, NoPositionOrColorVerts, Colors, Triangles);
		Mesh->CreateMeshSectionTripleBuffer(0, Vectors, NoPositionOrColorVerts, Colors, Triangles, FBox());


		Mesh->UpdateMeshSection(0, SimpleVerts);
		Mesh->UpdateMeshSection(0, SimpleVerts, FBox());
		Mesh->UpdateMeshSection(0, SimpleVerts, Triangles);
		Mesh->UpdateMeshSection(0, SimpleVerts, Triangles, FBox());
		Mesh->UpdateMeshSectionDualBuffer(0, Vectors, NoPositionVerts);
		Mesh->UpdateMeshSectionDualBuffer(0, Vectors, NoPositionVerts, FBox());
		Mesh->UpdateMeshSectionDualBuffer(0, Vectors, NoPositionVerts, Triangles);
		Mesh->UpdateMeshSectionDualBuffer(0, Vectors, NoPositionVerts, Triangles, FBox());
		Mesh->UpdateMeshSectionTripleBuffer(0, Vectors, NoPositionOrColorVerts, Colors);
		Mesh->UpdateMeshSectionTripleBuffer(0, Vectors, NoPositionOrColorVerts, Colors, FBox());
		Mesh->UpdateMeshSectionTripleBuffer(0, Vectors, NoPositionOrColorVerts, Colors, Triangles);
		Mesh->UpdateMeshSectionTripleBuffer(0, Vectors, NoPositionOrColorVerts, Colors, Triangles, FBox());


		Mesh->UpdateMeshSectionPrimaryBuffer(0, Vectors);
		Mesh->UpdateMeshSectionPrimaryBuffer(0, Vectors, FBox());
		Mesh->UpdateMeshSectionSecondaryBuffer(0, NoPositionVerts);
		Mesh->UpdateMeshSectionTertiaryBuffer(0, Colors);
		Mesh->UpdateMeshSectionTriangles(0, Triangles);

	}


};