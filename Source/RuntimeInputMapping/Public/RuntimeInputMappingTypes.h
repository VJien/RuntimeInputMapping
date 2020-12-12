// Copyright 2020. By V&J.Dong.   All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeInputMappingTypes.generated.h"


/**
 * key category:
 */
UENUM(BlueprintType)
enum class ERIMKeyCategory :uint8
{
	None,
	Key,
	Mouse,
	Gamepad,
	Motion,
	Touch,
	Gesture,
	PS4,
	Steam,
	XBoxOne,
	Android,
	Daydream,
	Vive,
	MixedReality,
	OculusGo,
	OculusTouch,
	ValveIndex,
	MagicLeap,
	OculusRemote,
	Cosmos

	
};