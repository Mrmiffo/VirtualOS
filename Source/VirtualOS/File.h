// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "File.generated.h"

UCLASS()
class VIRTUALOS_API AFile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "File functions")
		TArray<FString> GetFolderContent(FString path);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File properties")
		FString FilePath;

	

};
