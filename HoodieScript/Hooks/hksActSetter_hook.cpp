#include "pch.h"
#include "hksActSetter_hook.h"
#include "script_runtime.h"

namespace hoodie_script {
	hksActSetter_hook* hksActSetter_hook::_instance = nullptr;

	hksActSetter_hook::hksActSetter_hook() : jump_hook(0x14098C510, (uintptr_t)on_invoke)
	{
		_instance = this;
	}

	void hksActSetter_hook::on_invoke(uintptr_t* chrInsPtr, int32_t actId, uintptr_t luaStatePtr)
	{
		//0x14112df50
		uint64_t meme;
		const char* str;

		ChrIns characterInstance(*(uintptr_t*)((uintptr_t)chrInsPtr + 0x8));
		switch (actId)
		{
		case 421:
			meme = call(0x140d9cca0, luaStatePtr, 2, 0x5a); //get second argument from lua function
			if (meme != 0x5a)
			{
				logging::write_line(std::format("HKSAct Print = {0}", meme));
			}
			break;
		case 666:
			meme = call(0x140d9cca0, luaStatePtr, 2, 0x5a); //get second argument from lua function
			if (meme != 0x5a)
			{
				//std::wcout << characterInstance.getCharacterString() << "-HPAct = " << meme << std::endl;

				auto chrData = SprjChrDataModule(characterInstance.getSprjChrDataModule());
				chrData.setHealth((const uint32_t)meme);
			}
			break;
		case 9000:
			str = (const char*)call(0x140d9cd00, luaStatePtr, 2);
			logging::write_line(std::format("HKS Act9000 Print = {0}", str));
			break;
		default:
			uint64_t(*originalFunction)(uintptr_t * chrInsPtr, int32_t actId, uintptr_t luaStatePtr);
			*(uintptr_t*)&originalFunction = _instance->get_original();
			originalFunction(chrInsPtr, actId, luaStatePtr);
			break;
		}
	}
}
