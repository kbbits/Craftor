// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlaceableProxy.generated.h"

UCLASS()
class CRAFTOR_API APlaceableProxy : public AActor
{
	GENERATED_BODY()

public:

	/** Root component */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		USceneComponent* SceneRoot;

	/** StaticMesh component for the clickable block */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PlaceableMesh;
	
public:	
	// Sets default values for this actor's properties
	APlaceableProxy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
