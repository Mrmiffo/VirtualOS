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


	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File properties")
		FString path;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File properties")
		TArray<FString> content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File properties")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File properties")
		bool isDirectory;

	UFUNCTION(BlueprintImplementableEvent, Category = "File functions")
		void FolderOpening();

		void FolderOpening_Implementation();

	UFUNCTION(BlueprintCallable, Category = "File functions")
		void OpenFile();

	UFUNCTION(BlueprintCallable, Category = "File functions")
		void InitializeFile(FString filePath, FString fileName, bool fileIsDirectory);

	UFUNCTION(BlueprintImplementableEvent, Category = "File functions")
		void FileInteract();

	void FileInteract_Implementation();

	UFUNCTION(BlueprintImplementableEvent, Category = "File functions")
		void NameChanged();

	void NameChanged_Implementation();

	UFUNCTION(BlueprintCallable, Category = "File functions")
		void ChangeName(FString newName);


};	
