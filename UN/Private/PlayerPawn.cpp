// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Test"));
	SetRootComponent(sphereComp);
	sphereComp->InitSphereRadius(40.0f);

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	meshComp->SetupAttachment(sphereComp);
	meshComp->SetWorldScale3D(FVector(0.8f));

	sphereComp->SetCollisionProfileName(TEXT("Player"));
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	PController->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);
	MouseLocation.Z = 0;
	if (MouseLocation.X > 540)
	{
		MouseLocation.X = 540;
	}
	else if (MouseLocation.X < -540)
	{
		MouseLocation.X = -540;
	}

	/*FHitResult mouseHitResult;

	if (PlayerCanControl == true)
	{*/
		SetActorLocation(MouseLocation/*, true, &mouseHitResult*/);
	/*}
	

	if (mouseHitResult.IsValidBlockingHit())
	{
		SetActorLocation(GetActorLocation());
	}*/
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float APlayerPawn::GetMouseX()
{
	float MouseX = MouseLocation.X;
	return MouseX;
}

float APlayerPawn::GetMouseY()
{
	float MouseY = MouseLocation.Y;
	return MouseY;
}

