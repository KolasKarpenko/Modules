#pragma once

#include <ModuleManager.h>
#include <string>

class IApplicationModule : public module::IModule
{
public:
	virtual void PrintText(const std::string& text) {}
};

REGISTER_MODULE_INTRFACE(IApplicationModule)
