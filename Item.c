#include "Core.h"

void DropItem(Map *ThisMap, COORD ThisPos, Item *ThisItem)
{
	ThisMap->MapTile[ThisPos.X][ThisPos.Y].TileItem = ThisItem;
}
void InitInv(Inventory *ThisInventory)
{
	short x;
	for(x = 0; x < INVSIZE; x++)
	{
		ThisInventory->ContainsItem[INVSIZE] = FALSE;
	};
}
void PickupItem(Player *ThisPlayer, Map *ThisMap)
{
	short x;
	x = 0;
	if(ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y].TileItem != NULL)
	{
		while(ThisPlayer->PInventory.ContainsItem[x] == TRUE)
		{
			if(x < INVSIZE)
			{
			x++;
			}
			else
			{
				mvprintw(MSGPOSX, MSGPOSY, "Inventory Full!");
				AfterMsg();
			};
		};
		 ThisPlayer->PInventory.InvItem[x] = *ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y].TileItem;
		 ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y].TileItem = NULL;
		 }
		 else
		 {
			mvprintw(MSGPOSX, MSGPOSY, "No item to pick up.");
			AfterMsg();
			};
}

void GenMapItem(Map *ThisMap, Item *ThisItem)
{
	COORD DropPos;
	RandVPos(ThisMap, &DropPos);
	DropItem(ThisMap, DropPos, ThisItem);
}

void DisplayInvSlot(Inventory *ThisInventory, short SlotNum)
{
	int Row = SlotNum % 15;
	int Col;
	char enumsel = SlotNum + LISTENUM;
	if(SlotNum >= 15)
	{
		Col = 20;
		Row++;
	}
	else{
		Col = 1;
		};
		mvprintw(Row, Col, "(%c), %s", enumsel, &ThisInventory->InvItem[SlotNum].ItemName);
		

}

void DisplayInv(Inventory *ThisInventory)
{
	int x;
	for(x = 1; x < INVSIZE;)
	{
		DisplayInvSlot(ThisInventory, x++);
		
	}
	refresh();
}

/*void SelItem(Inventory *ThisInventory, Item *SelectedItem)
{
	char ItemEnum;
	DisplayInv(ThisInventory);
	mvprintw(MSGPOSX, MSGPOSY, "Which item do you wish to select?");
	ItemEnum = getch() - LISTENUM;
	SelectedItem = &Inventory->ThisInventory[ItemEnum];
}


	*/
		