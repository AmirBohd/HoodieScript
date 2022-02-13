/*
	* DS3RuntimeScripting
	* Contributers: Amir
	* Further notes on how to use this class:
	* 
	* -EquipData Setters- Online limitations.
	* Setting equipment values is only local and in online session will be reverted as
	* the PlayerIns's game regularly sends their actual equip data.
	* 
	* Changing your own PlayerIns's equipdata will not be reverted but not change 
	* on other's games unless you send a network packet with the updated data.
	* 
	* The game normally sends the equip data of your inventory items rather than 
	* the data on these pointers. However your game aside from durablity, UI and
	* other inventory specific things, your game renders and uses the data from the
	* item identified in this pointer.
	* 
	* Use this api's network utilites in your scripts to ensure intended behaivor and utilize possible work arounds.
*/

#pragma once
#include "chr_ins.h"
#include "GameObjects/player_game_data.h"

namespace hoodie_script {

class PlayerIns : public ChrIns
{
public:
	enum class OffsetNumber
	{
		MainCharacter = 0,
		Player1 = 1,
		Player2 = 2,
		Player3 = 3,
		Player4 = 4,
		Player5 = 5
	};

	PlayerIns(uintptr_t address);

	/**
	* Gets an instance of this Player's PlayerGameData object.
	* 
	* @return Virtual address of this Player's PlayerGameData object.
	*/
	PlayerGameData getPlayerGameData();


	/**
	* checks if this player or npc has a PlayerGameData object.
	*
	* @return true if the PlayerGameData is present, false if it isn't.
	*/
	bool hasPlayerGameData();

	/**
	* Gets the virtual address of this Player's NetworkPointer object.
	* 
	* @return Virtual address of this Player's NetworkPointer object.
	*/
	uintptr_t* getNetworkPointer();

	/**
	* Checks if the "No Goods Consume" debug flag is set for this Player. This flag prevents consumption of inventory goods which may allow them to be used 
	  infintely.
	* 
	* @return True if the "No Goods Consume" debug flag is set for this Player.
	*/
	bool isNoGoodsConsume() const;
	
	/**
	* Sets the "No Goods Consume" debug flag on or off for this Player. This flag prevents consumption of inventory goods which may allow them to be used 
	  infintely.
	* 
	* @param value The state to set for the flag.
	*/
	void setNoGoodsConsume(const bool& value);

	/**
	* Gets the virtual address of this Player's PlayerCtrl object.
	* 
	* @return Virtual address of this Player's PlayerCtrl object.
	*/
	uintptr_t getPlayerCtrl();


	/**
	* Gets a pointer to this player's network handle on the game's peer-to-peer network.
	* 
	* @return Pointer to this player's network handle on the game's peer-to-peer network.
	*/
	uintptr_t* getNetworkHandle();

	/**
	* Check if this refers to a valid PlayerIns object.
	* 
	* Peformes several multi-level pointer checks.
	* 
	* @return True if PlayerIns is valid.
	*/
	bool isValid() const;

	/**
	* Get the base address of PlayerIns by the offset multiplier in memory. 
	* 
	* 0 is the main character you control in the game, 1-5 are the PlayerInss 
	* that may appear in your game via online session.
	* 
	* @param offsetNumber The PlayerIns number to get the address of
	* @return The base address of the specified PlayerIns if they exist in memory, otherwise this returns 0.
	*/
	static uintptr_t getAddressByOffsetNumber(const OffsetNumber& offsetNumber);

	static bool isChrWithOffsetNumber(const OffsetNumber& offsetNumber);

	/**
	* Check if an address is the virtual address of a PlayerIns. 
	* 
	* @param address Virtual address to check.
	* @return True if address is the base address of a PlayerIns.
	*/
	static bool isPlayer(const uintptr_t& address);

	/**
	* Get an instance of the main chr(The player charater the game takes the perspective of and allows you to control).
	* 
	* @return Virtual address of the main chr.
	*/
	static PlayerIns getMainChr();

	/**
	* Check if an address matches the virtual address of the main chr. 
	* 
	* @param address Virtual address to check.
	* @return True if address is the virtual address of the main chr.
	*/
	static bool isMainChr(const uintptr_t& address);

	/**
	* Check if the main chr is loaded(The player charater the game takes the perspective of and allows you to control).
	* 
	* @return True if the main chr is loaded
	*/
	static bool isMainChrLoaded();
};

}
