#include "pch.h"
#include "player_ins.h"
#include "memory_util.h"
#include "databaseaddress.h"
#include "GameDebugClasses/world_chr_man.h"

namespace hoodie_script {

	PlayerIns::PlayerIns(uintptr_t address) : ChrIns::ChrIns(address)
	{
	}

	PlayerGameData PlayerIns::getPlayerGameData()
	{
		return PlayerGameData(*accessMultilevelPointer<uintptr_t>(getAddress() + 0x1FA0));
	}

	uintptr_t* PlayerIns::getNetworkPointer()
	{
		return accessMultilevelPointer<uintptr_t>(getAddress() + 0x1FD0, 8);
	}

	bool PlayerIns::hasPlayerGameData()
	{
		return accessMultilevelPointer<uintptr_t>(getAddress() + 0x1FA0) != nullptr;
	}

	bool PlayerIns::isNoGoodsConsume() const
	{
		bool value = (*accessMultilevelPointer<uint8_t>(getAddress() + 0x1EEA) & static_cast<uint8_t>(pow(2, 3))) == pow(2, 3);
		return value;
	}

	void PlayerIns::setNoGoodsConsume(const bool& value)
	{
		uint8_t* newByte = accessMultilevelPointer<uint8_t>(getAddress() + 0x1EEA);
		if (value) *newByte = *newByte | static_cast<uint8_t>(pow(2, 3));
		else *newByte = (*newByte & ~static_cast<uint8_t>(pow(2, 3)));
	}

	uintptr_t PlayerIns::getPlayerCtrl()
	{
		return *accessMultilevelPointer<uintptr_t>(getAddress() + 0x50);
	}

	uintptr_t* PlayerIns::getNetworkHandle()
	{
		return accessMultilevelPointer<uintptr_t>(getAddress() + 0x1FD0, 0x8);
	}

	uintptr_t PlayerIns::getAddressByOffsetNumber(const OffsetNumber& offsetNumber)
	{
		return *accessMultilevelPointer<uintptr_t>(DataBaseAddress::WorldChrMan, 0x40, static_cast<uint32_t>(offsetNumber) * 0x38);
	}

	bool PlayerIns::isChrWithOffsetNumber(const OffsetNumber& offsetNumber)
	{
		const uintptr_t* chrAddress = accessMultilevelPointer<uintptr_t>(DataBaseAddress::WorldChrMan, 0x40, static_cast<uint32_t>(offsetNumber) * 0x38);
		return chrAddress != nullptr && isPlayer(*chrAddress);
	}

	bool PlayerIns::isPlayer(const uintptr_t& address)
	{
		bool isPlayer = false;
		for (int i = 0; i < 5; i++) if (getAddressByOffsetNumber(static_cast<OffsetNumber>(i)) == address) isPlayer = true;
		return isChrIns(address) && isPlayer && accessMultilevelPointer<uint32_t>(address + 0x1FA0, 0xFC);
	}

	bool PlayerIns::isValid() const
	{
		bool isPlayer = false;
		if (getAddress() == 0)
			return false;
		for (int i = 0; i < 5; i++) if (getAddressByOffsetNumber(static_cast<OffsetNumber>(i)) == getAddress()) isPlayer = true;
		return isPlayer && accessMultilevelPointer<uint32_t>(getAddress() + 0x1FA0, 0xFC);
	}

	PlayerIns PlayerIns::getMainChr()
	{
		return WorldChrMan::getMainChr();
	}

	bool PlayerIns::isMainChr(const uintptr_t& address)
	{
		return isChrIns(address) && address == reinterpret_cast<uintptr_t>(accessMultilevelPointer<uintptr_t>(DataBaseAddress::WorldChrMan, 0x80, 0));
	}

	bool PlayerIns::isMainChrLoaded()
	{
		return WorldChrMan::isMainChrLoaded();
	}

};
