// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("WallComp"));
	FVector boxsize = FVector(10, 1920, 10);
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(boxsize);

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wallstaticmesh"));
	meshComp->SetupAttachment(boxComp);
	meshComp->SetWorldScale3D(FVector(0.2, 38.4, 0.2));
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

