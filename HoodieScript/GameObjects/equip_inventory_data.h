/*
	* DS3RuntimeScripting
	* Contributers: Amir
*/

#include <GameObjects/InventoryItem.h>

namespace hoodie_script {

class EquipInventoryData
{
public:
	EquipInventoryData(uintptr_t address);
	void discardInventoryItems(int32_t inventoryItemId, int32_t quantity);
	void addItem(ItemParamIdPrefix paramIdPrefix, int32_t paramId, uint32_t quantity, int32_t durability);
	InventoryItemInternal* getInventoryItemById(int32_t inventoryItemId);
	int32_t getInventoryItemCount();
	std::vector<InventoryItem> GetInventoryItems();
	static ItemParamIdPrefix getItemParamIdPrefixFromGiveId(int32_t giveId);
	bool isHiddenItem(const uint32_t itemId);

	/**
	* Gets the item in the specified left weapon slot of this PlayerIns in the game's memory.
	*
	* @param slotNumber The weapon slot to get the weapon from, must be a integer ranging 1-3.
	* @return equipParamId of the weapon in this slot.
	*/
	int32_t getLeftHandWeapon(const uint32_t& slotNumber) const;

	/**
	* Gets the item in the active left weapon slot of this PlayerIns in the game's memory.
	*https://youtu.be/EOy0f_fGKAg
	* @return equipParamId of the weapon in this slot.
	*/
	int32_t getLeftHandWeaponActive() const;
	/**
	* Sets the item in the specified left hand weapon slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.https://youtu.be/EOy0f_fGKAg
	*
	* @param slotNumber The weapon slot to put the weapon in, must be an integer ranging 0-2.
	* @param equipParamWeaponId equipParamId of the weapon to put in this slot.
	*/
	void setLeftHandWeapon(const uint32_t& slotNumber, const int32_t& equipParamWeaponId);

	/**
	* Sets the item in the active left hand weapon slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @param equipParamWeaponId equipParamId of the weapon to put in this slot.
	*/
	void setLeftHandWeaponActive(const int32_t& equipParamWeaponId);

	/**
	* gets the active right weapon slot index of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	*  at the top of the file.
	*/
	uint32_t GetActiveWeaponSlotRightHand() const;

	/**
	* gets the active left weapon slot index of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	*  at the top of the file.
	*/
	uint32_t GetActiveWeaponSlotLeftHand() const;

	/**
	* Gets the item in the specified right weapon slot of this PlayerIns in the game's memory.
	*
	* @param slotNumber The weapon slot to get the weapon from, must be a integer ranging 0-2.
	* @return equipParamId of the weapon in this slot.
	*/
	int32_t getRightHandWeapon(const uint32_t& slotNumber) const;

	/**
	* Gets the item in the active right weapon slot of this PlayerIns in the game's memory.
	*
	* @return equipParamId of the weapon in this slot.
	*/
	int32_t getRightHandWeaponActive() const;

	/**
	* Sets the item in the specified right hand weapon slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @param slotNumber The weapon slot to put the weapon in, must be an integer ranging 1-3.
	* @param equipParamWeaponId equipParamId of the weapon to put in this slot.
	*/
	void setRightHandWeapon(const uint32_t& slotNumber, const int32_t& equipParamWeaponId);

	/**
	* Sets the item in the active right hand weapon slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @param equipParamWeaponId equipParamId of the weapon to put in this slot.
	*/
	void setRightHandWeaponActive(const int32_t& equipParamWeaponId);


	/**
	* Sets the item in the active right hand weapon slot of this PlayerIns in the game's memory.
	* Differs from the standard for being networked, important notes:
	* If the item is not in the inventory it will be given to the player. That is necessary in order for the set to be successful.
	* @param equipParamWeaponId equipParamId of the weapon to put in this slot.
	*/

	/**
	* Gets the item in the head slot of this PlayerIns in the game's memory.
	*
	* @return equipParamId of the protector(Armor) in the head slot.
	*/
	int32_t getHead() const;

	/**
	* Sets the item in the head slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @param equipParamProtectorId equipParamId of the protector(Armor) to put into the head slot.
	*/
	void setHead(const int32_t& equipParamProtectorId);

	/**
	* Gets the item in the chest slot of this PlayerIns in the game's memory.
	*
	* @return equipParamId of the protector(Armor) in the chest slot.
	*/
	int32_t getChest() const;

	/**
	* Sets the item in the chest slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @param equipParamProtectorId equipParamId of the protector(Armor) to put into the chest slot.
	*/
	void setChest(const int32_t& equipParamProtectorId);

	/**
	* Gets the item in the hands slot of this PlayerIns in the game's memory.
	*
	* @return equipParamId of the protector(Armor) in the hands slot.
	*/
	int32_t getHands() const;

	/**
	* Sets the item in the hands slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @param equipParamProtectorId equipParamId of the protector(Armor) to put into the hands slot.
	*/
	void setHands(const int32_t& equipParamProtectorId);

	/**
	* Gets the item in the legs slot of this PlayerIns in the game's memory.
	*
	* @return equipParamId of the protector(Armor) in the legs slot.
	*/
	int32_t getLegs() const;

	/**
	* Sets the item in the legs slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @param equipParamProtectorId equipParamId of the protector(Armor) to put into the legs slot.
	*/
	void setLegs(const int32_t& equipParamProtectorId);

	/**
	* Gets the item in the specified ring slot of this PlayerIns in the game's memory.
	*
	* @param slotNumber The ring slot to get the ring from, must be a integer ranging 1-4.
	* @return equipParamId of the ring in this slot.
	*/
	int32_t getRing(const uint32_t& slotNumber) const;

	/**
	* Sets the item in the specified ring slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @param slotNumber The ammo slot to put the ring in, must be an integer ranging 1-4.
	* @param equipParamAccessoryId equipParamId of the ring to put in this slot.
	*/
	void setRing(const uint32_t& slotNumber, const int32_t& equipParamAccessoryId);

	/**
	* Gets the item in the specified ammo slot of this PlayerIns in the game's memory.
	*
	* @param slotNumber The ammo slot to get the ring from, must be a integer ranging 1-4.
	* @return equipParamId of the ammo in this slot.
	*/
	int32_t getAmmo(const uint32_t& slotNumber) const;

	/**
	* Sets the item in the specified ammo slot of this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	at the top of the file.
	*
	* @param slotNumber The ammo slot to put the ammo in, must be an integer ranging 1-4.
	* @param equipParamWeaponId equipParamId of the ammo to put in this slot.
	*/
	void setAmmo(const uint32_t& slotNumber, const int32_t& equipParamWeaponId);

	/**
	* Gets the covenant item of this PlayerIns in the game's memory.
	*
	* @return equipParamId of this player's covenant.
	*/
	int32_t getCovenant() const;

	/**
	* Sets the covenant item for this PlayerIns in the game's memory.
	*
	* Setting this value may not result in expected behaivor, to learn more read this header's documentation
	  at the top of the file.
	*
	* @papram equipParamAccessoryId equipParamId of the new covenant to give this player.
	*/
	void setCovenant(const int32_t& equipParamAccessoryId);
private:
	uintptr_t address;
};

}