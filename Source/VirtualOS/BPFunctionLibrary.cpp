// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualOS.h"
#include "BPFunctionLibrary.h"

FString UBPFunctionLibrary::getMonthFromInt(int monthNr)
{
	TArray<FString> months = { "January", "February", "March", "April", "May", 
		"June", "July", "August", "September", "October", "November", "December" };

	return months[monthNr - 1];
}
