// Copyright 2016 Chris Conway (Koderz). All Rights Reserved.

#include "RMC_Examples.h"
#include "RuntimeMeshObjectBase.h"


// Sets default values
ARuntimeMeshObjectBase::ARuntimeMeshObjectBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RuntimeMesh = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("Runtime Mesh"));
	RootComponent = RuntimeMesh;
}

// Called when the game starts or when spawned
void ARuntimeMeshObjectBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARuntimeMeshObjectBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

