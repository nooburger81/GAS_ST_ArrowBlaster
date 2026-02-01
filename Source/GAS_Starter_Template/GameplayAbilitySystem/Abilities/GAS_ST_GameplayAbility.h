// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GAS_ST_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_STARTER_TEMPLATE_API UGAS_ST_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS|UI")
	bool ShouldShowInAbilitiesBar = false;
};
