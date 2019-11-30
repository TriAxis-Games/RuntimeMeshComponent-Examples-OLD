// Fill out your copyright notice in the Description page of Project Settings.


#include "SmpleBoxRMC.h"
#include "Providers/RuntimeMeshProviderBox.h"
#include "Materials/Material.h"

// Sets default values
ASmpleBoxRMC::ASmpleBoxRMC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASmpleBoxRMC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASmpleBoxRMC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASmpleBoxRMC::GenerateMeshes_Implementation()
{
	URuntimeMeshProviderBox* CubeProvider = NewObject<URuntimeMeshProviderBox>(this);
	CubeProvider->BoxRadius = FVector(100, 100, 100);
	CubeProvider->Material = UMaterial::GetDefaultMaterial(MD_Surface);
	GetRuntimeMeshComponent()->GetOrCreateRuntimeMesh()->Initialize(CubeProvider);
}

