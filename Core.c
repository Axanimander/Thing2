#include "Core.h"

int main()
{
	//Monster Tmonster;
	//Item Titem;
	//Player Tplayer;
	COORD RSize;
	RSize.X = 3;
	RSize.Y = 15;
	//Titem.ItemOut = 'l';
	//strcpy(Tplayer.PInventory.InvItem[1].ItemName, "Lalk");
	Map Tmap;
	Init();	
	GenMap(&Tmap, RSize, 17);
	//MonsterGen(&Tmap, &Tmonster, 1);
	//GenPlayer(&Tplayer);
	//SetPlayer(&Tmap, &Tplayer);
	//DropItem(&Tmap, RSize, &Titem);
	DrawMap(&Tmap);
	//DisplayStats(&Tplayer);
	//while(1)
	//{
	//Command(&Tmap, &Tplayer, getch());
	//DisplayInv(&Tplayer.PInventory);
	DrawMap(&Tmap);
	refresh();
	//getch();
	//};
	endwin();
}
