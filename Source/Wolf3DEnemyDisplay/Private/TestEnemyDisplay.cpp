// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemyDisplay.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "PaperFlipbookComponent.h"



ATestEnemyDisplay::ATestEnemyDisplay()
{
	GetSprite()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
}

void ATestEnemyDisplay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator RawCamDir = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraRotation();
	FRotator CamDir	= FRotator(0.0f, RawCamDir.Yaw + 90.0f, 0.0f);
	GetSprite()->SetWorldRotation(CamDir);

	FVector RawEnemyLoc = this->GetActorLocation();
	FVector RawPlayerLoc = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation();

	FVector2D EnemyLoc = FVector2D(RawEnemyLoc.X, RawEnemyLoc.Y);
	FVector2D PlayerLoc = FVector2D(RawPlayerLoc.X, RawPlayerLoc.Y);

	FVector2D VectorToPlayer = PlayerLoc - EnemyLoc;
	VectorToPlayer.Normalize();

	FVector VTP = FVector(VectorToPlayer.X, VectorToPlayer.Y, 0.0f);

	float RawPEA = FMath::RadiansToDegrees(acosf(FVector::DotProduct(this->GetActorForwardVector(), VTP)));
	float PEA = (FVector::DotProduct(VTP, this->GetActorRightVector()) < 0) ? ((- 1 * RawPEA)) : (RawPEA);

	// Front view
	if (PEA > -22.5f && PEA < 22.5f)
	{
		GetSprite()->SetFlipbook(Front);
	}

	// Front-right view
	if (PEA > 22.5f && PEA < 67.5f)
	{
		GetSprite()->SetFlipbook(FrontRight);
	}

	// Right view
	if (PEA > 67.5f && PEA < 112.5f)
	{
		GetSprite()->SetFlipbook(Right);
	}

	// Rear-right view
	if (PEA > 112.5f && PEA < 157.5f)
	{
		GetSprite()->SetFlipbook(RearRight);
	}

	// Rear view
	if (PEA > 157.5f && PEA < 202.5f)
	{
		GetSprite()->SetFlipbook(Rear);
	}

	// Rear-left view
	if (PEA > -157.5f && PEA < -112.5f)
	{
		GetSprite()->SetFlipbook(RearLeft);
	}

	// Left view
	if (PEA > -112.5f && PEA < -67.5f)
	{
		GetSprite()->SetFlipbook(Left);
	}

	// Front-left view
	if (PEA > -67.5f && PEA < -22.5f)
	{
		GetSprite()->SetFlipbook(FrontLeft);
	}
}