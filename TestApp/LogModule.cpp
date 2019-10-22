#include "LogModule.h"

#include "IApplicationModule.h"
#include <ModuleManager.h>


void LogModule::Log(const std::string& message) //dummy
{
	auto appModule = module::ModuleManager::GetModule<IApplicationModule>();
	appModule->PrintText(message);
}
