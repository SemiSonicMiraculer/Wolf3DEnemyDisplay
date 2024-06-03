// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "TestEnemyDisplay.generated.h"

/**
 * 
 */
UCLASS()
class WOLF3DENEMYDISPLAY_API ATestEnemyDisplay : public APaperCharacter
{
	GENERATED_BODY()
	
public:

	ATestEnemyDisplay();

	UPROPERTY(EditAnywhere, Category = "Animation")
	class UPaperFlipbook* Front;
	UPROPERTY(EditAnywhere, Category = "Animation")
	class UPaperFlipbook* FrontRight;
	UPROPERTY(EditAnywhere, Category = "Animation")
	class UPaperFlipbook* Right;
	UPROPERTY(EditAnywhere, Category = "Animation")
	class UPaperFlipbook* RearRight;
	UPROPERTY(EditAnywhere, Category = "Animation")
	class UPaperFlipbook* Rear;
	UPROPERTY(EditAnywhere, Category = "Animation")
	class UPaperFlipbook* RearLeft;
	UPROPERTY(EditAnywhere, Category = "Animation")
	class UPaperFlipbook* Left;
	UPROPERTY(EditAnywhere, Category = "Animation")
	class UPaperFlipbook* FrontLeft;

protected:
	virtual void Tick (float DeltaTime) override;
};
