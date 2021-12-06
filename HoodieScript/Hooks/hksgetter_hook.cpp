#include "pch.h"
#include "hksgetter_hook.h"
#include "GameExtensions/GameExtensionsManager.h"
//#include "script_runtime.h"

namespace hoodie_script {
	hksEnvGetter_hook* hksEnvGetter_hook::_instance = nullptr;

	hksEnvGetter_hook::hksEnvGetter_hook() : jump_hook(0x14098f3d0, (uintptr_t)on_invoke)
	{
		_instance = this;
	}

	uint64_t hksEnvGetter_hook::on_invoke(uintptr_t* ptrToChrIns, uint32_t envId, int64_t luaStatePtr)
	{
		//0x14112df50
		long long secondArgLua;
		ChrIns characterInstance(*ptrToChrIns);
		LuaArgs luaArgs(luaStatePtr);
		auto extension = GameExtensionManager::tryGetHksEnvExpansionLambda(envId);
		if (extension.has_value())
		{
			return extension.value()(characterInstance, luaArgs, envId);
		}
		else
		{
			uint64_t(*originalFunction)(uintptr_t * ptrToChrIns, uint32_t envId, int64_t luaStatePtr);
			*(uintptr_t*)&originalFunction = _instance->get_original();
			return originalFunction(ptrToChrIns, envId, luaStatePtr);
		}
		return NULL;
	}
}
