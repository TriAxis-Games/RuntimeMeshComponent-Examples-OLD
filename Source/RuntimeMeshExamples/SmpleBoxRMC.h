// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RuntimeMeshActor.h"
#include "SmpleBoxRMC.generated.h"

UCLASS()
class RUNTIMEMESHEXAMPLES_API ASmpleBoxRMC : public ARuntimeMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASmpleBoxRMC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GenerateMeshes_Implementation() override;
};
