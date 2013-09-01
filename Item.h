

struct Item
{
	byte ItemType;
	char ItemName[50];
	char ItemOut;
};
struct Inventory
{
	short ContainsItem[INVSIZE];
	Item InvItem[INVSIZE];
};
struct EquipSlot
{
	byte IsEmpty;
	byte ItemType;
	char SlotName[30];
	Item *EquippedItem;
};
struct Equipment
{
	 struct EquipSlot WeaponSlot;
	 struct EquipSlot ArmorSlot;
};
void DropItem(Map *ThisMap, COORD ThisPos, Item *ThisItem);
void PickupItem(Player *ThisPlayer, Map *ThisMap);
void InitInv(Inventory *ThisInventory);
void GenMapItem(Map *ThisMap, Item *ThisItem);
void DisplayInvSlot(Inventory *ThisInventory, short SlotNum);
void DisplayInv(Inventory *ThisInventory);
void InvDrop(Inventory *ThisInventory, Map *ThisMap);
void SelItem(Inventory *ThisInventory, Item *SelectedItem);

