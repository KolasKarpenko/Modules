#pragma once

namespace module
{

class IModule
{
public:
	virtual ~IModule() {}

	virtual void Init() {}
	virtual void Startup() {}
	virtual void Finish() {}
};

}

