// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RuntimeMeshComponent.h"
#include "RuntimeMeshObjectBase.generated.h"

UCLASS()
class RMC_EXAMPLES_API ARuntimeMeshObjectBase : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere)
	URuntimeMeshComponent* RuntimeMesh;
	
	// Sets default values for this actor's properties
	ARuntimeMeshObjectBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

};
