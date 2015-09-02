// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

UCLASS()
class SHOOTERGAME_API APickupActor : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//JoyControl
	UStaticMeshComponent* JoyfulControl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UStaticMesh * AssetSM_JoyControl;

	FORCEINLINE void SetupSMComponentsWithCollision(UStaticMeshComponent* Comp)
	{
		if (!Comp) return;
		//~~~~~~~~

		Comp->bOwnerNoSee = false;
		Comp->bCastDynamicShadow = true;
		Comp->CastShadow = true;
		Comp->BodyInstance.SetObjectType(ECC_WorldDynamic);
		Comp->BodyInstance.SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Comp->BodyInstance.SetResponseToAllChannels(ECR_Ignore);
		Comp->BodyInstance.SetResponseToChannel(ECC_WorldStatic, ECR_Block);
		Comp->BodyInstance.SetResponseToChannel(ECC_WorldDynamic, ECR_Block);
		Comp->BodyInstance.SetResponseToChannel(ECC_Pawn, ECR_Block);
		Comp->SetHiddenInGame(false);
	}
	
};
