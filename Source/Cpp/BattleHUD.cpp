// Fill out your copyright notice in the Description page of Project Settings.

#include "Cpp.h"
#include "BattleHUD.h"
#include "TargetActor.h"



void ABattleHUD::DrawHUD()
{
	const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());

	ViewportSizeX = ViewportSize.X;
	ViewportSizeY = ViewportSize.Y;

	ViewportCenter = FVector2D(ViewportSize.X / 2, ViewportSize.Y / 2);

	UE_LOG(LogTemp, Warning, TEXT("I am Battle HUD"));
	FoundActors.Reset();
	GetActorsInSelectionRectangle(GetSelectionPointA(), GetSelectionPointB(), FoundActors, bIncludeNonCollidingComponents, bActorMustBeFullyEnclosed);
	
	//gotta add this to a function!
	Draw2DLine(GetSelectionPointA().X, GetSelectionPointA().Y, GetSelectionPointA().X, GetSelectionPointB().Y, FColor::Red);
	Draw2DLine(GetSelectionPointA().X, GetSelectionPointA().Y, GetSelectionPointB().X, GetSelectionPointA().Y, FColor::Red);
	Draw2DLine(GetSelectionPointA().X, GetSelectionPointB().Y, GetSelectionPointB().X, GetSelectionPointB().Y, FColor::Red);
	Draw2DLine(GetSelectionPointB().X, GetSelectionPointA().Y, GetSelectionPointB().X, GetSelectionPointB().Y, FColor::Red);


}

FVector2D ABattleHUD::GetSelectionPointA() {
	const FVector2D Result = FVector2D(ViewportCenter.X - CrosshairSize*ViewportSizeX/10, ViewportCenter.Y - CrosshairSize*ViewportSizeX / 10);

	return Result;
}

FVector2D ABattleHUD::GetSelectionPointB() {
	const FVector2D Result = FVector2D(ViewportCenter.X + CrosshairSize*ViewportSizeX/10, ViewportCenter.Y + CrosshairSize*ViewportSizeX / 10);

	return Result;
}
