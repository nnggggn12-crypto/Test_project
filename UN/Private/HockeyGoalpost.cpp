// Fill out your copyright notice in the Description page of Project Settings.


#include "HockeyGoalpost.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Hockeypuck.h"

// Sets default values
AHockeyGoalpost::AHockeyGoalpost()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("WallComp"));
	FVector boxsize = FVector(10, 150, 10);
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(boxsize);

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wallstaticmesh"));
	meshComp->SetupAttachment(boxComp);
	meshComp->SetWorldScale3D(FVector(0.2, 3.0, 0.2));
}

// Called when the game starts or when spawned
void AHockeyGoalpost::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHockeyGoalpost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHockeyGoalpost::OnGoalOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AHockeypuck* puck = Cast<AHockeypuck>(OtherActor);

	if (puck != nullptr)
	{
		OtherActor->Destroy();
	}
}

