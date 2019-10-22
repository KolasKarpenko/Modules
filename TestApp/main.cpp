#include <ModuleManager.h>

#include "LogModule.h"
#include "ApplicationModule.h"

#include <stdexcept>

int main(int argc, char* argv[])
{
	module::ModuleManager::AddModule<ApplicationModule, IApplicationModule>();
	module::ModuleManager::AddModule<LogModule, ILogModule>();

	module::ModuleManager::StartModules();

	try {
		throw std::runtime_error("test error");
	}
	catch (const std::exception& e) {
		auto logModule = module::ModuleManager::GetModule<ILogModule>();
		logModule->Log(e.what());
	}

	module::ModuleManager::FinishModules();

	return 0;
}

