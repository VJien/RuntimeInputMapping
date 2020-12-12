// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RuntimeInputMappingBPLibrary.h"
#include "RuntimeInputMapping.h"
#include "InputCoreTypes.h"
#include "UObject/UObjectGlobals.h"
#include "Kismet/KismetStringLibrary.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/KismetTextLibrary.h"

URuntimeInputMappingBPLibrary::URuntimeInputMappingBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}




TArray<FInputActionKeyMapping> URuntimeInputMappingBPLibrary::GetActionMappings()
{
	return UInputSettings::GetInputSettings()->GetActionMappings();
}

TArray<FInputAxisKeyMapping> URuntimeInputMappingBPLibrary::GetAxisMappings()
{
	return UInputSettings::GetInputSettings()->GetAxisMappings();
}

void URuntimeInputMappingBPLibrary::GetAllKeys(TArray<FKey>& OutKeys)
{
	EKeys::GetAllKeys(OutKeys);
}

void URuntimeInputMappingBPLibrary::GetAllKeysWithCategories(TArray<ERIMKeyCategory> Categories, TArray<FKey>& OutKeys)
{
	TArray<FKey> keys;
	GetAllKeys(keys);
	TArray<FName> names;
	for (auto c : Categories)
	{
		FString str = GetKeyCategoryEnumString(c);
		names.Add(FName(*str));

	}
	for (FKey k: keys)
	{
		if (names.Contains(GetKeyMenuCategory(k)))
		{
			OutKeys.Add(k);
		}
	}
}

FName URuntimeInputMappingBPLibrary::GetKeyFName(FKey key)
{
	return key.GetFName();
}

FKey URuntimeInputMappingBPLibrary::GetKeyByFName(FName name)
{
	TArray<FKey> keys;
	GetAllKeys(keys);
	for (FKey k : keys)
	{
		if (k.GetFName()==name)
		{
			return k;
		}
	}
	return FKey();
}

FKey URuntimeInputMappingBPLibrary::GetKeyByDisplayName(FText name)
{

	TArray<FKey> keys;
	GetAllKeys(keys);
	for (FKey k : keys)
	{
		if (UKismetTextLibrary::EqualEqual_TextText(name,k.GetDisplayName()))
		{
			return k;
		}
	}
	return FKey();
}

FName URuntimeInputMappingBPLibrary::GetKeyMenuCategory(FKey key)
{
	return key.GetMenuCategory();
}

FString URuntimeInputMappingBPLibrary::GetKeyCategoryEnumString(ERIMKeyCategory category, bool bShortName)
{
	UEnum* ep = FindObject<UEnum>(ANY_PACKAGE, TEXT("ERIMKeyCategory"), true);
	if (ep)
	{
		if (bShortName)
		{
			FString tempStr = ep->GetNameByValue((int)category).ToString();
			TArray<FString> arr = UKismetStringLibrary::ParseIntoArray(tempStr, TEXT("::"));
			if (arr.Num()>0)
			{
				return arr.Last();
			}
		}

		return ep->GetNameByValue((int)category).ToString();
	
		
	}
	return TEXT("");
}

bool URuntimeInputMappingBPLibrary::ReplaceActionInputKey(const FInputActionKeyMapping& NewMapping, const FInputActionKeyMapping& OldMapping, bool bForceRebuildKeymaps /*= true*/, bool bCanRepeat )
{
	TArray<FName> names;
	UInputSettings* setting = UInputSettings::GetInputSettings();

	TArray <FInputActionKeyMapping> map = setting->GetActionMappings();
	if (map.Num() > 0)
	{
		if (map.Contains(OldMapping))
		{
			if (!bCanRepeat)
			{
				for (auto i : map)
				{
					if (i.Key == NewMapping.Key)
					{
						return false;
					}
				}
			}
			
			setting->RemoveActionMapping(OldMapping);
			setting->AddActionMapping(NewMapping);
			setting->SaveKeyMappings();
			return true;
		}

	}


	return false;
}

bool URuntimeInputMappingBPLibrary::ReplaceAxisInputKey(const FInputAxisKeyMapping& NewMapping, const FInputAxisKeyMapping& OldMapping, bool bForceRebuildKeymaps /*= true*/, bool bCanRepeat /*= false*/)
{
	TArray<FName> names;
	UInputSettings* setting = UInputSettings::GetInputSettings();

	TArray <FInputAxisKeyMapping> map = setting->GetAxisMappings();
	if (map.Num() > 0)
	{
		if (map.Contains(OldMapping))
		{
			if (!bCanRepeat)
			{
				for (auto i : map)
				{
					if (i.Key == NewMapping.Key)
					{
						return false;
					}
				}
			}

			setting->RemoveAxisMapping(OldMapping);
			setting->AddAxisMapping(NewMapping);
			setting->SaveKeyMappings();
			return true;
		}

	}


	return false;
}

ERIMKeyCategory URuntimeInputMappingBPLibrary::GetKeyCategoryFromString(FString name)
{
	const UEnum* ep= FindObject<UEnum>(ANY_PACKAGE, TEXT("ERIMKeyCategory"), true);
	if (ep)
	{
		return (ERIMKeyCategory)ep->GetIndexByName(FName(*name));
	}
	return ERIMKeyCategory::None;
}


