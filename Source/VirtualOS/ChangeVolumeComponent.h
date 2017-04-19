// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ChangeVolumeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIRTUALOS_API UChangeVolumeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UChangeVolumeComponent();

	//Custom function to change the sound of Windows
	UFUNCTION(BlueprintCallable, Category = "Custom functions")
		void changeMasterVolume(float newSoundLevel);

	UFUNCTION(BlueprintCallable, Category = "Custom functions")
		void getMasterVolume(float& currentSoundLevel);

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
