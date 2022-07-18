// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaceableProxy.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlaceableProxy::APlaceableProxy()
{
 	PrimaryActorTick.bCanEverTick = false;

	// Create root scene component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	// Create static mesh component
	PlaceableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaceableMesh"));
	//PlaceableMesh->SetStaticMesh();
	PlaceableMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	PlaceableMesh->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void APlaceableProxy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlaceableProxy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

