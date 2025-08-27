// Fill out your copyright notice in the Description page of Project Settings.


#include "Hockeypuck.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EngineUtils.h"
#include "PlayerPawn.h"


// Sets default values
AHockeypuck::AHockeypuck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Test"));
	SetRootComponent(sphereComp);
	sphereComp->InitSphereRadius(30.0f);

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	meshComp->SetupAttachment(sphereComp);
	meshComp->SetWorldScale3D(FVector(0.6f));

	sphereComp->SetCollisionProfileName(TEXT("Puck"));
}

// Called when the game starts or when spawn.ed
void AHockeypuck::BeginPlay()
{
	Super::BeginPlay();
	sphereComp->OnComponentHit.AddDynamic(this, &AHockeypuck::OnPlayerHit);
}

// Called every frame
void AHockeypuck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	puckdirection = FVector(direction_x, direction_y, 0);
	puckdirection.Normalize();
	FVector newLocation = GetActorLocation() + puckdirection * normalSpeed * DeltaTime;
	SetActorLocation(newLocation);
}

void AHockeypuck::OnPlayerHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	APlayerPawn* player = Cast<APlayerPawn>(OtherActor);

	if (player != nullptr)
	{
		increase_dirX(player->GetMouseX());
		increase_dirY(player->GetMouseY());
		UE_LOG(LogTemp, Log, TEXT("check"));
	}
}

void AHockeypuck::increase_dirX(float _amount)
{
	direction_x = _amount;
}

void AHockeypuck::increase_dirY(float _amount)
{
	direction_y = _amount;
}

