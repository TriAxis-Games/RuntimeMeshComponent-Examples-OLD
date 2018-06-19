// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RuntimeMeshComponent.h"
#include "RuntimeMeshActor.h"
#include "RuntimeMeshBasic.generated.h"

UCLASS()
class RUNTIMEMESHEXAMPLES_API ARuntimeMeshBasic : public ARuntimeMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARuntimeMeshBasic();


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector BoxSize;

protected:

	virtual void GenerateMeshes_Implementation() override;
	
};
