#include "Core.h"
void SetClass(Player *ThisPlayer, short Choice)
{
	switch(Choice)
	{
		case 1: //Warrior
			ThisPlayer->PClass.ModHealthMinMax.X = 7;
			ThisPlayer->PClass.ModHealthMinMax.Y = 12;
			ThisPlayer->PClass.ModStrMinMax.X = 3;
			ThisPlayer->PClass.ModStrMinMax.Y = 6;
			ThisPlayer->PClass.ModDexMinMax.X = 1;
			ThisPlayer->PClass.ModDexMinMax.Y = 2;
			ThisPlayer->PClass.ModIntMinMax.X = 1;
			ThisPlayer->PClass.ModIntMinMax.Y = 2;
			strcpy(ThisPlayer->PClass.ClassString, "Warrior");
			break;
	}
}
void SetRace(Player *ThisPlayer, short Choice)
{
	switch(Choice)
	{
		case 1: //Human
			ThisPlayer->PRace.HealthMinMax.X = 15;
			ThisPlayer->PRace.HealthMinMax.Y = 30;
			ThisPlayer->PRace.StrMinMax.X  = 7;
			ThisPlayer->PRace.StrMinMax.Y = 15;
			ThisPlayer->PRace.DexMinMax.X = 9;
			ThisPlayer->PRace.DexMinMax.Y = 18;
			ThisPlayer->PRace.IntMinMax.X = 8;
			ThisPlayer->PRace.IntMinMax.Y = 18;
			strcpy(ThisPlayer->PRace.RaceString, "Human");
			printw("You chose human\n");
			break;
	}
}
void GetRace(Player *ThisPlayer)
{
	printw("Select Your Race:\n\n\n");
	printw("(a) Human\n");
	switch(getch())
	{
		case 'a':
			SetRace(ThisPlayer, 1);
			break;
	}
}
void GetClass(Player *ThisPlayer)
{
	printw("Select your class \n");
	printw("(a) Warrior");
	switch(getch())
	{
		case 'a':
			SetClass(ThisPlayer, 1);
			break;
	}
}


void RollPlayer(Player *ThisPlayer)
{
	short ModHealth = 0;
	short ModStrength = 0;
	short ModDex = 0;
	short ModInt = 0;
	//printw("Rolling Mods\n");
	//refresh();
	ModHealth = getrand(ThisPlayer->PClass.ModHealthMinMax.X, ThisPlayer->PClass.ModHealthMinMax.Y);
	//printw("Mod Health Complete %d\n", ModHealth);
	//refresh();
	ModStrength = getrand(ThisPlayer->PClass.ModStrMinMax.X, ThisPlayer->PClass.ModStrMinMax.Y);
	//printw("Mod Strength Complete %d\n", ModStrength);
	//refresh();
	ModDex = getrand(ThisPlayer->PClass.ModDexMinMax.X, ThisPlayer->PClass.ModDexMinMax.Y);
	//printw("Mod Dex Complete %d\n", ModDex);
	//refresh();
	ModInt = getrand(ThisPlayer->PClass.ModIntMinMax.X, ThisPlayer->PClass.ModIntMinMax.Y);
	//printw("Mod Int Complete %d\n", ModInt);
	//refresh();
	ThisPlayer->Strength = getrand(ThisPlayer->PRace.StrMinMax.X + ModStrength, ThisPlayer->PRace.StrMinMax.Y + ModStrength);
	ThisPlayer->Health = getrand(ThisPlayer->PRace.HealthMinMax.X + ModHealth, ThisPlayer->PRace.HealthMinMax.Y + ModHealth);
	ThisPlayer->Dex = getrand(ThisPlayer->PRace.DexMinMax.X + ModDex, ThisPlayer->PRace.DexMinMax.Y + ModDex);
	ThisPlayer->Int = getrand(ThisPlayer->PRace.IntMinMax.X + ModInt, ThisPlayer->PRace.IntMinMax.Y + ModInt);
	//printw("Character Rolled\n");
	ThisPlayer->CurrHealth = ThisPlayer->Health;
}

void DescribePlayer(Player *ThisPlayer)
{
	strcpy(ThisPlayer->PDescript, "\n You were born a ");
	strcat(ThisPlayer->PDescript, ThisPlayer->PRace.RaceString);
	strcat(ThisPlayer->PDescript, ", You decided to train as a ");
	strcat(ThisPlayer->PDescript, ThisPlayer->PClass.ClassString);
	strcat(ThisPlayer->PDescript, ", Your parents named you ");
	strcat(ThisPlayer->PDescript, ThisPlayer->PName);
}

void GenPlayer(Player *ThisPlayer)
{
	printw("Please input your name\n");
	echo();
	getstr(ThisPlayer->PName);
	noecho();
	clear();
	GetRace(ThisPlayer);
	clear();
	GetClass(ThisPlayer);
	clear();
	RollPlayer(ThisPlayer);
	DescribePlayer(ThisPlayer);
	printw("%s ", ThisPlayer->PDescript);
	refresh();
	getch();
	InitInv(&ThisPlayer->PInventory);
	clear();
	ThisPlayer->PlayerOut = '@';
	ThisPlayer->PlayerPos.X = 15;
	ThisPlayer->PlayerPos.Y = 15;
};

void EndGame(Player *ThisPlayer)
{
	clear();
	mvprintw(0, 0, "Evil Won, Now Live");
	refresh();
	getch();
	endwin();
}
void MovePlayer(Map *ThisMap, Player *ThisPlayer, short Key)
{
	switch(Key)
	{
		case UP:
			if(ThisMap->MapTile[ThisPlayer->PlayerPos.X - 1][ThisPlayer->PlayerPos.Y].IsWalk == 1)
			{
			ThisMap->MapTile[ThisPlayer->PlayerPos.X - 1][ThisPlayer->PlayerPos.Y].TilePlayer = ThisPlayer;
			ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y].TilePlayer = NULL;
			}
			break;
		case DOWN:
			if(ThisMap->MapTile[ThisPlayer->PlayerPos.X + 1][ThisPlayer->PlayerPos.Y].IsWalk == 1)
			{
			ThisMap->MapTile[ThisPlayer->PlayerPos.X + 1][ThisPlayer->PlayerPos.Y].TilePlayer = ThisPlayer;
			ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y].TilePlayer = NULL;
			}
			break;
		case LEFT:
			if(ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y + 1].IsWalk == 1)
			{
			ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y + 1].TilePlayer = ThisPlayer;
			ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y].TilePlayer = NULL;
			}
			break;
		case RIGHT:
			if(ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y - 1].IsWalk)
			{
			ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y - 1].TilePlayer = ThisPlayer;
			ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y].TilePlayer = NULL;
			}
			break;
	};
	Move(ThisMap, &ThisPlayer->PlayerPos, Key);
}

void SetPlayer(Map *ThisMap, Player *ThisPlayer)
{
	RandVPos(ThisMap, &ThisPlayer->PlayerPos);
	ThisMap->MapTile[ThisPlayer->PlayerPos.X][ThisPlayer->PlayerPos.Y].TilePlayer = ThisPlayer;
	PutObj(ThisMap, ThisPlayer->PlayerPos, ThisPlayer->PlayerOut);
}

void PlayerHit(Monster *ThisMonster, Player *ThisPlayer)
{
	short HitDam;
	HitDam = 5;
	ThisMonster->CurrHealth -= HitDam;
}

void Attack(Map *ThisMap, Player *ThisPlayer, short AttackDir)
{
	COORD HitPos;
	HitPos = ThisPlayer->PlayerPos;
	Direction(&HitPos, AttackDir);
	if(ThisMap->MapTile[HitPos.X][HitPos.Y].TileMob)
	{
		PlayerHit(ThisMap->MapTile[HitPos.X][HitPos.Y].TileMob, ThisPlayer);
		if(ThisMap->MapTile[HitPos.X][HitPos.Y].TileMob->CurrHealth <= 0)
		{
			MonsterDeath(ThisMap, HitPos);
			mvprintw(MSGPOSX, MSGPOSY, "You killed it!");
			
		};
	}
	else
	{
		mvprintw(MSGPOSX, MSGPOSY, "Nothing to hit!");
	};
}

void DisplayStats(Player *ThisPlayer)
{
	mvprintw(2, 65, "Str: %d", ThisPlayer->Strength);
	mvprintw(3, 65, "Dex: %d", ThisPlayer->Dex);
	mvprintw(4, 65, "Int: %d", ThisPlayer->Int);
	mvprintw(5, 65, "HP:  %d / %d", ThisPlayer->Health, ThisPlayer->CurrHealth);
	refresh();
};
