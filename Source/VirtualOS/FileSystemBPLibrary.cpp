// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualOS.h"
#include "FileSystemBPLibrary.h"

TArray<FString> UFileSystemBPLibrary::GetFolderContent(FString path)
{
	class FFolderIterator : public IPlatformFile::FDirectoryVisitor
	{
	public:
		TArray<FString> ResultPaths;
		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) {
			ResultPaths.Add(FilenameOrDirectory);
			return true;
		}
	};
	FFolderIterator Iterator;

	if (IsDirectory(*path))
	{

		IFileManager& FileManager = IFileManager::Get();
		
		FileManager.IterateDirectory(*path, Iterator);
		
	}
	return Iterator.ResultPaths;
}

bool UFileSystemBPLibrary::IsDirectory(FString path)
{
	IFileManager& FileManager = IFileManager::Get();
	return FileManager.GetStatData(*path).bIsDirectory;
	
	
}

bool UFileSystemBPLibrary::IsValid(FString path)
{
	return IFileManager::Get().GetStatData(*path).bIsValid;

}

int32 UFileSystemBPLibrary::FileSize(FString path)
{
	IFileManager& Manager = IFileManager::Get();
	if (Manager.GetStatData(*path).bIsValid) {
		return Manager.GetStatData(*path).FileSize;
	}
		return -1;
}

FString UFileSystemBPLibrary::GetFileExtention(FString path)
{
	return FPaths::GetExtension(*path, true);
}

FString UFileSystemBPLibrary::GetCleanFileName(FString path)
{
	return FPaths::GetBaseFilename(*path, true);
}

bool UFileSystemBPLibrary::MakeDirectory(FString pathToCreate, bool makeNeededSubDir)
{
	IFileManager& Manager = IFileManager::Get();
	if (!Manager.DirectoryExists(*pathToCreate)) return Manager.MakeDirectory(*pathToCreate, makeNeededSubDir);
	return false;
}

bool UFileSystemBPLibrary::MoveFile(FString source, FString target, bool replaceIfExists)
{
	IFileManager& Manager = IFileManager::Get();
	if (Manager.FileExists(*source)) {
		return Manager.Move(*target, *source, replaceIfExists);
	}
	return false;
}

bool UFileSystemBPLibrary::CopyFile(FString sourceFile, FString targetFilePathName, bool replaceIfExists)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (PlatformFile.FileExists(*sourceFile)) {
		return PlatformFile.CopyFile(*targetFilePathName, *sourceFile);
	}
	return false;
}

bool UFileSystemBPLibrary::MoveFolder(FString rootToMove, FString destinationDir, bool overwriteExisting)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (PlatformFile.DirectoryExists(*rootToMove) && PlatformFile.DirectoryExists(*destinationDir) &&
		PlatformFile.CopyDirectoryTree(*destinationDir, *rootToMove, overwriteExisting)) {
		PlatformFile.DeleteDirectoryRecursively(*rootToMove);
	}
	return false;
}

bool UFileSystemBPLibrary::CopyFolder(FString rootToCopy, FString destinationDir, bool overwriteExisting)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (PlatformFile.DirectoryExists(*rootToCopy) && PlatformFile.DirectoryExists(*destinationDir)) {
		return PlatformFile.CopyDirectoryTree(*destinationDir, *rootToCopy, overwriteExisting);
	}
	else return false;
	
}

bool UFileSystemBPLibrary::RenameFile(FString source, FString newName)
{	
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (PlatformFile.FileExists(*source)) {
		int indexAt;
		if (source.FindLastChar('/', indexAt)) {
			FString rootOfFile = source.Left(indexAt);
			rootOfFile.Append(newName);
			return PlatformFile.MoveFile(*newName, *source);
		}
	}
	return false;
}

bool UFileSystemBPLibrary::DeleteFile(FString path)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (PlatformFile.FileExists(*path)) {
		return PlatformFile.DeleteFile(*path);
	}
	return false;
}

bool UFileSystemBPLibrary::DeleteFolder(FString path)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (PlatformFile.DirectoryExists(*path)) {
		return PlatformFile.DeleteDirectory(*path);
	}
	return false;
}

FString UFileSystemBPLibrary::GetPathToUserDir() 
{
	return FPlatformProcess::UserDir();
}

FString UFileSystemBPLibrary::GetContainingFolderPath(FString path) 
{

		if (IsDirectory(*path))
		{
			return FPaths::GetPath(FPaths::GetPath(*path));
		}
		else return FPaths::GetPath(*path);

}
