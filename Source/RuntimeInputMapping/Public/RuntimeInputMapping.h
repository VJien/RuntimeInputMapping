// Copyright 2020. By V&J.Dong.   All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FRuntimeInputMappingModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
