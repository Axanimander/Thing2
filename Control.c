#include "Core.h"

void Move(Map *ThisMap, COORD *Pos, short Key)
{	
	COORD SPos = *Pos;
	Direction(Pos, Key);
	if(ThisMap->MapTile[Pos->X][Pos->Y].IsWalk == 1)
	{	
		MoveObj(ThisMap, SPos, *Pos);
	}
	else
	{
		*Pos = SPos;
	};
	
}

void Command(Map *ThisMap, Player *ThisPlayer, short Key)
{
	
	COORD SPos = ThisPlayer->PlayerPos; //Save Pos for when Pos is changed later
	switch(Key)
	{
		case UP:
			//Move(ThisMap, &ThisPlayer->PlayerPos, Key);
			MovePlayer(ThisMap, ThisPlayer, Key);
			break;
		case DOWN:
			//Move(ThisMap, &ThisPlayer->PlayerPos, Key);
			MovePlayer(ThisMap, ThisPlayer, Key);
			break;
		case LEFT:
			//Move(ThisMap, &ThisPlayer->PlayerPos, Key);
			MovePlayer(ThisMap, ThisPlayer, Key);
			break;
		case RIGHT:
			//Move(ThisMap, &ThisPlayer->PlayerPos, Key);
			MovePlayer(ThisMap, ThisPlayer, Key);
			break;
		/*case HELLOKEY:
			Message(MSGT_HELLO);*/
		case ATTACK:
			mvprintw(MSGPOSX, MSGPOSY, "Which direction is the monster you wish to attack?");
			Attack(ThisMap, ThisPlayer, getch());
			break;
		case PICKUP:
			PickupItem(ThisPlayer, ThisMap);
		case 10:
			endwin();
	}

}

void Direction(COORD *ThisCoord, short Key)
{
		switch(Key)
	{
		case UP:
			ThisCoord->X -= 1;
			break;
		case DOWN:
			ThisCoord->X += 1;
			break;
		case LEFT:
			ThisCoord->Y += 1;
			break;
		case RIGHT:
			ThisCoord->Y -= 1;
			break;
	};
}
