// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualOS.h"
#include "File.h"
#include "FileManager.h"


// Sets default values
AFile::AFile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AFile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

TArray<FString> AFile::GetFolderContent(FString path)
{
	IFileManager& FileManager = IFileManager::Get();
	TArray<FString> toReturn = TArray<FString>();
	FileManager.FindFiles(toReturn, *path);
	return toReturn;
}


