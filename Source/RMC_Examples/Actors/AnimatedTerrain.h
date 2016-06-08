// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RuntimeMeshObjectBase.h"
#include "AnimatedTerrain.generated.h"

UCLASS()
class RMC_EXAMPLES_API AAnimatedTerrain : public ARuntimeMeshObjectBase
{
	GENERATED_BODY()
	
public:	
	FBox BoundingBox;
	TArray<FVector> Positions;
	TArray<FRuntimeMeshVertexNoPosition> VertexData;
	TArray<int32> Triangles;

	// Sets default values for this actor's properties
	AAnimatedTerrain();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void OnConstruction(const FTransform& Transform) override;
	
	void Generate();

	float CurrentAnimationFrameX = 0.0f;
	float CurrentAnimationFrameY = 0.0f;

	int32 HalfWidth = 20;

	float CellSize = 50;
	float Height = 20;
};
