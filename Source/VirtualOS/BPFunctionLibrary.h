// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class VIRTUALOS_API UBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

		UFUNCTION(BlueprintCallable, Category = "getMonthFromInt")
		static FString getMonthFromInt(int monthNr);
	
		UFUNCTION(BlueprintCallable, Category = "readTxtFile")
			static FString getTextFromTxt(FString path);
};
