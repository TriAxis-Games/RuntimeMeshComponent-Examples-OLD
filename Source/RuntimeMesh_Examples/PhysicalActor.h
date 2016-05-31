// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "RuntimeMeshComponent.h"
#include "PhysicalActor.generated.h"

typedef FRuntimeMeshVertex<1> MyVertex;
typedef FRuntimeMeshVertex<1, false, false> MyDualVertex;

UCLASS()
class RUNTIMEMESH_EXAMPLES_API APhysicalActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicalActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
	class URuntimeMeshComponent* MeshComponent;
	
	float Size;
	int Direction = 1;

	TArray<MyVertex> Vertices;
	TArray<FVector> Positions;
	TArray<MyDualVertex> VertexData;
	TArray<int32> Triangles;
};
