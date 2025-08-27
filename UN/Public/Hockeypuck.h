// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hockeypuck.generated.h"

UCLASS()
class MINIGAME_API AHockeypuck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHockeypuck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class USphereComponent* sphereComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	float normalSpeed = 5.0f;
	UPROPERTY(EditAnywhere)
	float blockSpeed = 0.0f;

	UPROPERTY(EditAnywhere)
	FVector puckdirection = FVector(0, 0, 0);

	UFUNCTION()
	void OnPlayerHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	UPROPERTY(EditAnywhere)
	float direction_x = 0.0f;
	UPROPERTY(EditAnywhere)
	float direction_y = 0.0f;

	UFUNCTION()
	void increase_dirX(float _amount);
	UFUNCTION()
	void increase_dirY(float _amount);

};
