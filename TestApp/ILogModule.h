#pragma once

#include <ModuleManager.h>
#include <string>

class ILogModule : public module::IModule
{
public:
	virtual void Log(const std::string& /*message*/) {}
};

REGISTER_MODULE_INTRFACE(ILogModule)
