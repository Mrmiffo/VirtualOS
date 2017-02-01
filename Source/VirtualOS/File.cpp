// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualOS.h"
#include "File.h"
#include "FileManager.h"


// Sets default values
AFile::AFile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	content = TArray<FString>();
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AFile::BeginPlay()
{
	
	Super::BeginPlay();
	path = "C:/Users/anton/Desktop";
	isDirectory = true;
}

// Called every frame
void AFile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

/* Opens the selected file. If the file was a floder the paths to the content of the folder is located in the content variable */
void AFile::OpenFile()
{
	if (isDirectory) 
	{
		IFileManager& FileManager = IFileManager::Get();
		FileManager.FindFiles(content, *path);
		FolderOpening();
	}
	else 
	{

	}

}

void AFile::InitializeFile(FString filePath, FString fileName, bool fileIsDirectory)
{
	path = filePath;
	name = fileName;
	isDirectory = fileIsDirectory;
}

void AFile::FileInteract_Implementation()
{

}

void AFile::FolderOpening_Implementation()
{

}