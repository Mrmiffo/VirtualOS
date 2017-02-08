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

/* Opens the selected file. If the file was a floder the paths to the content of the folder is located in the content variable */
void AFile::OpenFile()
{
	if (IsDirectory) 
	{
		class FFolderIterator : public IPlatformFile::FDirectoryVisitor
		{
		public:
			TArray<FString> ResultFiles;
			TArray<FString> ResultFolders;
			virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) {
				if (bIsDirectory) {
					ResultFolders.Add(FilenameOrDirectory);
				}
				else {
					ResultFiles.Add(FilenameOrDirectory);
				}
				return true;
			}
		};
		IFileManager& FileManager = IFileManager::Get();
		FFolderIterator Iterator;
		FileManager.IterateDirectory(*Path, Iterator);
		ContentFiles = Iterator.ResultFiles;
		ContentFolders = Iterator.ResultFolders;
		FolderOpening();
	}
	else 
	{

	}

}

void AFile::InitializeFile(FString filePath, FString fileName, bool fileIsDirectory)
{
	Path = filePath;
	ChangeName(fileName);
	IsDirectory = fileIsDirectory;
}

void AFile::FileInteract_Implementation()
{

}

void AFile::NameChanged_Implementation()
{
}

void AFile::ChangeName(FString newName)
{
	Name = newName;
	NameChanged();
}

void AFile::FolderOpening_Implementation()
{

}

