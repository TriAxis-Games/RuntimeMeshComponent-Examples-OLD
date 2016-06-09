// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "RuntimeMeshObjectBase.h"
#include "AnimatedTerrain.generated.h"

UCLASS()
class RMC_EXAMPLES_API AAnimatedTerrain : public ARuntimeMeshObjectBase
{
	GENERATED_BODY()
	
public:	
	bool bGenerated;
	FBox BoundingBox;

	// Sets default values for this actor's properties
	AAnimatedTerrain();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void OnConstruction(const FTransform& Transform) override;
	
	void Generate();

	float AnimationOffsetX = 0.0f;
	float AnimationOffsetY = 0.0f;

	int32 HalfWidth = 400;

	float CellSize = 5;
	float Height = 20;
};
