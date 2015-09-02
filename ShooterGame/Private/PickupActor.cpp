// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "PickupActor.h"


// Sets default values
APickupActor::APickupActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//Asset, Reference Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshOb_AW2(TEXT("StaticMesh'/Game/'"));

	AssetSM_JoyControl = StaticMeshOb_AW2.Object;

	//Create
	JoyfulControl = ObjectInitializer.CreateDefaultSubobject < UStaticMeshComponent >(this, TEXT("JoyfulControlYay"));

	//Set Mesh
	JoyfulControl->SetStaticMesh(AssetSM_JoyControl);

	//Setup (see .h)
	SetupSMComponentsWithCollision(JoyfulControl);

	//Deferred Attachment (Ty Nick W.! Actual attach gets done after blueprint stuff)
	JoyfulControl->AttachParent = RootComponent;
	JoyfulControl->AttachSocketName = "JoyControl";

	//JoyfulControl->AttachParent = RootComponent;
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

