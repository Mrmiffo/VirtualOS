// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileSystemBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALOS_API UFileSystemBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Folder Content")
		static TArray<FString> GetFolderContent(FString path);
	
	UFUNCTION(BlueprintCallable, Category = "File information")
		static bool IsDirectory(FString path);

	UFUNCTION(BlueprintCallable, Category = "File information")
		static bool IsValid(FString path);

	UFUNCTION(BlueprintCallable, Category = "File information")
		static int32 FileSize(FString path);

	UFUNCTION(BlueprintCallable, Category = "File information")
		static FString GetFileExtention(FString path);

	UFUNCTION(BlueprintCallable, Category = "File information")
		static FString GetCleanFileName(FString path);

	UFUNCTION(BlueprintCallable, Category = "File managemenet")
		static bool MakeDirectory(FString pathToCreate, bool makeNeededSubDir);

	UFUNCTION(BlueprintCallable, Category = "File managemenet")
		static bool MoveFile(FString source, FString target, bool replaceIfExists);

	UFUNCTION(BlueprintCallable, Category = "File managemenet")
		static bool CopyFile(FString sourceFile, FString targetFilePathName, bool replaceIfExists);

	UFUNCTION(BlueprintCallable, Category = "File managemenet")
		static bool MoveFolder(FString rootToMove, FString destinationDir, bool overwriteExisting);

	UFUNCTION(BlueprintCallable, Category = "File managemenet")
		static bool CopyFolder(FString rootToCopy, FString destinationDir, bool overwriteExisting);

	UFUNCTION(BlueprintCallable, Category = "File managemenet")
		static bool RenameFile(FString source, FString newName);

	UFUNCTION(BlueprintCallable, Category = "File managemenet")
		static bool DeleteFile(FString path);

	UFUNCTION(BlueprintCallable, Category = "File managemenet")
		static bool DeleteFolder(FString path);
	
	UFUNCTION(BlueprintPure, Category = "Filesystem navigation")
		static FString GetPathToUserDir();

	UFUNCTION(BlueprintPure, Category = "Filesystem navigation")
		static FString GetContainingFolderPath(FString path);
};
