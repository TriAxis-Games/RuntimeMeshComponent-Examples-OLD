// Copyright 2016-2019 Chris Conway (Koderz). All Rights Reserved.

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
