// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualOS.h"
#include "ChangeVolumeComponent.h"
#include "AllowWindowsPlatformTypes.h"
#include <Windows.h>
#include <tchar.h>
#include <endpointvolume.h>
#include <mmdeviceapi.h>
#include "HideWindowsPlatformTypes.h"

// Sets default values for this component's properties
UChangeVolumeComponent::UChangeVolumeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UChangeVolumeComponent::changeMasterVolume(float newSoundLevel) {
	UE_LOG(LogTemp, Warning, TEXT("New windows volume level... %f"), newSoundLevel);

	HRESULT hr;

	CoInitialize(NULL);
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	IMMDevice *defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	// -------------------------
	hr = endpointVolume->SetMasterVolumeLevelScalar(newSoundLevel, NULL);
	endpointVolume->Release();

	CoUninitialize();
}

// Called when the game starts
void UChangeVolumeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UChangeVolumeComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

