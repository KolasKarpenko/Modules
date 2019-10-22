#pragma once

#include "IApplicationModule.h"

class ApplicationModule : public IApplicationModule
{
public:
	virtual void PrintText(const std::string& text) override;
};