// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_ST_AbilitySystemComponent.h"

#include "Characters/GAS_Character_Base.h"


// Sets default values for this component's properties
UGAS_ST_AbilitySystemComponent::UGAS_ST_AbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGAS_ST_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UGAS_ST_AbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();

	AGAS_Character_Base *Character =  Cast<AGAS_Character_Base>(GetOwner());
	if (!Character) return;


	bool bAbilitiesChanged = false;
	
	if (LastActivatableAbilities.Num() != ActivatableAbilities.Items.Num())
	{
		bAbilitiesChanged = true;
	}
	else
	{
		for (int32 i = 0; i < LastActivatableAbilities.Num(); i++)
		{
			if (LastActivatableAbilities[i].Ability != ActivatableAbilities.Items[i].Ability)
			{
				bAbilitiesChanged = true;
				break;
			}
		}
	}
	if (bAbilitiesChanged)
	{
		Character->SendAbilitiesChangedEvent();
		LastActivatableAbilities = ActivatableAbilities.Items;
	}
	
}




// Called every frame
void UGAS_ST_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

