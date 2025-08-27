// Fill out your copyright notice in the Description page of Project Settings.


#include "HockeyEnemy.h"

// Sets default values
AHockeyEnemy::AHockeyEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHockeyEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHockeyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

