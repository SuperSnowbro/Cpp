// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"

#include "BattleHUD.generated.h"


/**
 * 
 */

class ATargetActor;

UCLASS()
class CPP_API ABattleHUD : public AHUD
{
	GENERATED_BODY()

private:
	
	int ViewportSizeX;
	int ViewportSizeY; //currently not in use

	FVector2D ViewportCenter;

	FVector2D GetSelectionPointA();

	FVector2D GetSelectionPointB();

	UPROPERTY(EditAnywhere)
		bool bIncludeNonCollidingComponents;

	UPROPERTY(EditAnywhere)
		bool bActorMustBeFullyEnclosed;

protected:
	UPROPERTY(BlueprintReadOnly)
		TArray<ATargetActor*> FoundActors;

		virtual	void DrawHUD() override;

public:
	UPROPERTY(EditAnywhere)
		int CrosshairSize;
};
