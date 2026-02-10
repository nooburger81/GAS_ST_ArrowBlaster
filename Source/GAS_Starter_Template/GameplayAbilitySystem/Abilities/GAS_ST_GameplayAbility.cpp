// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_ST_GameplayAbility.h"

UGAS_ST_GameplayAbility::UGAS_ST_GameplayAbility()
{
	ActivationOwnedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("GASAB.Active")));
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag("State.Dead"));
}

bool UGAS_ST_GameplayAbility::HasPC() const
{
	const APawn* PawnObject = Cast<APawn>(GetAvatarActorFromActorInfo());
	if (!PawnObject)
	{
		return false;
	}
	return PawnObject->GetController()->IsA<APlayerController>();
}
