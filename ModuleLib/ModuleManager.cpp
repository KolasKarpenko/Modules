#include "include/ModuleManager.h"

namespace module
{


void ModuleManager::StartModules()
{
	const module_private::ModuleRegistry& reg = module_private::getModuleRegistry();

	for (const auto& m : reg) {
		m->Init();
	}

	for (const auto& m : reg) {
		m->Startup();
	}
}

void ModuleManager::FinishModules()
{
	const module_private::ModuleRegistry& reg = module_private::getModuleRegistry();

	for (const auto& m : reg) {
		m->Finish();
	}
}

}
