#pragma once

#include "IModule.h"
#include <vector>
#include <memory>

namespace module_private {

inline size_t getLastId()
{
	static size_t lastId = 0;
	return lastId++;
}

template<typename T> 
size_t getModuleId()
{
	static size_t id = getLastId();
	return id;
}

typedef std::shared_ptr<module::IModule> ModulePtr;
typedef std::vector<ModulePtr> ModuleRegistry;

inline ModuleRegistry& getModuleRegistry()
{
	static ModuleRegistry reg;
	return reg;
}

template<class T>
struct ModuleRegistryEntry
{
public:
	static ModuleRegistryEntry<T>& Instance()
	{
		static ModuleRegistryEntry<T> inst;
		return inst;
	}

private:
	ModuleRegistryEntry()
	{
		getModuleId<T>();//autoincrement module id
		ModuleRegistry& reg = getModuleRegistry();
		reg.push_back(ModulePtr(new T));
	}

	ModuleRegistryEntry(const ModuleRegistryEntry<T>&) = delete;
	ModuleRegistryEntry& operator=(const ModuleRegistryEntry<T>&) = delete;
};
}

namespace module
{

class ModuleManager
{
public:
	static void StartModules();
	static void FinishModules();

	template<class TModule, class TModuleInterface>
	static void AddModule()
	{
		TModuleInterface* modulePtr = new TModule();
		module_private::ModuleRegistry& reg = module_private::getModuleRegistry();
		reg[module_private::getModuleId<TModuleInterface>()].reset(modulePtr);
	}

	template<class TModuleInterface>
	static TModuleInterface* GetModule()
	{
		const module_private::ModuleRegistry& reg = module_private::getModuleRegistry();
		return static_cast<TModuleInterface*>(reg[module_private::getModuleId<TModuleInterface>()].get());
	}
};

}

#define REGISTER_MODULE_INTRFACE(TYPE)\
namespace\
{\
	template<class T>\
	class ModuleRegistration;\
	\
	template<>\
	class ModuleRegistration<TYPE>\
	{\
		static const module_private::ModuleRegistryEntry<TYPE>& reg;\
	};\
	\
	const module_private::ModuleRegistryEntry<TYPE>&\
		ModuleRegistration<TYPE>::reg =\
			module_private::ModuleRegistryEntry<TYPE>::Instance();\
}
