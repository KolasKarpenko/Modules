#pragma once

#include "ILogModule.h"

class LogModule : public ILogModule
{
public:
	virtual void Log(const std::string& message) override;
};
