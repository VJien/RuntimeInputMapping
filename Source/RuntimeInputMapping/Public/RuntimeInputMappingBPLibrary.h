// Copyright 2020. By V&J.Dong

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "RuntimeInputMappingTypes.h"
#include "GameFramework/PlayerInput.h"
#include "RuntimeInputMappingBPLibrary.generated.h"



UCLASS()
class  RUNTIMEINPUTMAPPING_API URuntimeInputMappingBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping")
		static TArray<FInputActionKeyMapping> GetActionMappings();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping")
		static TArray<FInputAxisKeyMapping> GetAxisMappings();
	UFUNCTION(BlueprintCallable,BlueprintPure ,Category = "RuntimeInputMapping")
		static void GetAllKeys(TArray<FKey>& OutKeys);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping", meta = (AutoCreateRefTerm = "Categories"))
		static void GetAllKeysWithCategories(TArray<ERIMKeyCategory> Categories, TArray<FKey>& OutKeys);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping")
		static FName GetKeyFName(FKey key);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping")
		static FKey GetKeyByFName(FName name);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping")
		static FKey GetKeyByDisplayName(FText name);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping")
		static FName GetKeyMenuCategory(FKey key);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping")
		static FString GetKeyCategoryEnumString(ERIMKeyCategory category = ERIMKeyCategory::None, bool bShortName = true);
	UFUNCTION(BlueprintCallable,  Category = "RuntimeInputMapping")
		static bool ReplaceActionInputKey(const FInputActionKeyMapping& NewMapping, const FInputActionKeyMapping& OldMapping,bool bForceRebuildKeymaps = true, bool bCanRepeat = false);
	UFUNCTION(BlueprintCallable, Category = "RuntimeInputMapping")
		static bool ReplaceAxisInputKey(const FInputAxisKeyMapping& NewMapping, const FInputAxisKeyMapping& OldMapping, bool bForceRebuildKeymaps = true, bool bCanRepeat = false);



	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RuntimeInputMapping")
		static ERIMKeyCategory GetKeyCategoryFromString(FString name);
	
};
