#include "Core.h"

void PutTile(Map *ThisMap, COORD TilePos, char TileOut)
{
	ThisMap->MapTile[TilePos.X][TilePos.Y].TilePlayer = NULL;
	ThisMap->MapTile[TilePos.X][TilePos.Y].TileMob = NULL;
	ThisMap->MapTile[TilePos.X][TilePos.Y].TileItem = NULL;
	ClearTile(&ThisMap->MapTile[TilePos.X][TilePos.Y]);
	if(TileOut == FLOOR)
	{
	ThisMap->MapTile[TilePos.X][TilePos.Y].IsWalk = 1;
	}
	else
	{
		ThisMap->MapTile[TilePos.X][TilePos.Y].IsWalk = 0;
	};
	ThisMap->MapTile[TilePos.X][TilePos.Y].Base = TileOut;
	ThisMap->MapTile[TilePos.X][TilePos.Y].Out = TileOut;
	ThisMap->MapTile[TilePos.X][TilePos.Y].Pos = TilePos;
}

void ClearTile(Tile *ThisTile)
{
	ThisTile = NULL;
}

void OutTile(Tile *ThisTile)
{
	if(ThisTile->TilePlayer == NULL)
	{
		
		if(ThisTile->TileItem == NULL)
		{
			mvprintw(ThisTile->Pos.X, ThisTile->Pos.Y,"%c", ThisTile->Out);
		}
		else
		{
			mvprintw(ThisTile->Pos.X, ThisTile->Pos.Y, "%c", ThisTile->TileItem->ItemOut);
		}
	}
	else
	{
		mvprintw(ThisTile->Pos.X, ThisTile->Pos.Y, "%c", ThisTile->TilePlayer->PlayerOut);
	}
}

void PutRoom(Map *ThisMap, COORD TL, COORD BR)
{
	COORD Put;
	for(Put.X = TL.X; Put.X < BR.X; Put.X++)
		{
			
				for(Put.Y = TL.Y; Put.Y < BR.Y; Put.Y++)
				{
					PutTile(ThisMap, Put, FLOOR);
				}
		}
}		

void PutTunnel(Map *ThisMap, COORD Start, COORD Finish)
{
	COORD Put = Start;
	while(Put.X != Finish.X && Put.Y != Finish.Y)
	{
		while(Put.X != Finish.X)
		{
			PutTile(ThisMap, Put, FLOOR);
			if(Put.X < Finish.X)
			{
				Put.X++;
			}
			if(Put.X > Finish.X)
			{
				Put.X--;
			}
		};
		while(Put.Y != Finish.Y)
		{
			PutTile(ThisMap, Put, FLOOR);
			if(Put.Y < Finish.Y)
			{
				Put.Y++;
			}
			if(Put.Y > Finish.Y)
			{
				Put.Y--;
			}
		};
	};
}

void InitMap(Map *ThisMap)
{
	COORD Put;
	for(Put.X = 0; Put.X < MAP_SIZE_X;)
	{
		for(Put.Y = 0; Put.Y < MAP_SIZE_Y; )
		{
			PutTile(ThisMap, Put, '#');
			ThisMap->MapTile[Put.X][Put.Y].TileMob = NULL;
			
			Put.Y++;
		}
		Put.X++;
	}
}

void GenMap(Map *ThisMap, COORD RSize, int RCount)
{
	COORD Put;
	COORD Put2;
	COORD TargetRoom;
	int RoomSize;
	int RBuilt;
	InitMap(ThisMap);
	for(RBuilt = 0; RBuilt < RCount; RBuilt++)
	{
		if(RBuilt != 0)
		{
			TargetRoom = Put;
		};
		Put.X = getrand(MAP_SIZE_X - RSize.Y , 0);
		Put.Y = getrand(MAP_SIZE_Y - RSize.Y , 0);
		RoomSize = getrand(RSize.Y, RSize.X);
		Put2.X = Put.X + RoomSize;
		Put2.Y = Put.Y + RoomSize;
		PutRoom(ThisMap, Put, Put2);
		if(RBuilt >= 1)
		{
			PutTunnel(ThisMap, Put, TargetRoom);
		};
	};
			
}

void DrawMap(Map *ThisMap)
{
	short x;
	short y;
	for(x = 0; x < MAP_SIZE_X; x++)
	{
		for(y = 0; y < MAP_SIZE_Y; y++)
		{
			OutTile(&ThisMap->MapTile[x][y]);
			//GrabMob(ThisMap);
			//GrabItem(ThisMap);
		};
	};
}

void PutObj(Map *ThisMap, COORD TilePos, char Object)
{
	ThisMap->MapTile[TilePos.X][TilePos.Y].Out = Object;
}
void ReadMob(Map *ThisMap, COORD TilePos)
{
	if(ThisMap->MapTile[TilePos.X][TilePos.Y].TileMob != NULL)
	{
	ThisMap->MapTile[TilePos.X][TilePos.Y].Out = ThisMap->MapTile[TilePos.X][TilePos.Y].TileMob->MonOut;
	}
}
void MoveObj(Map *ThisMap, COORD Pos, COORD Put)
{
		ThisMap->MapTile[Put.X][Put.Y].Out = ThisMap->MapTile[Pos.X][Pos.Y].Out;
		ThisMap->MapTile[Pos.X][Pos.Y].Out = ThisMap->MapTile[Pos.X][Pos.Y].Base;
		OutTile(&ThisMap->MapTile[Put.X][Put.Y]);
		OutTile(&ThisMap->MapTile[Pos.X][Pos.Y]);
}
void RemoveObj(Map *ThisMap, COORD Put)
{
	ThisMap->MapTile[Put.X][Put.Y].Out = ThisMap->MapTile[Put.X][Put.Y].Base;
	ThisMap->MapTile[Put.X][Put.Y].IsWalk = 1;
	OutTile(&ThisMap->MapTile[Put.X][Put.Y]);
}
void RandVPos(Map *ThisMap, COORD *RandPos)
{
	while(ThisMap->MapTile[RandPos->X][RandPos->Y].IsWalk != 1)
	{
		RandPos->X = getrand(MAP_SIZE_X, 0);
		RandPos->Y = getrand(MAP_SIZE_Y, 0);
	};

}
void GrabMob(Map *ThisMap)
{
	int x;
	int y;
	COORD XY;
	for(x = 0; x < MAP_SIZE_X; x++)
	{
		for(y = 0; y < MAP_SIZE_Y; y++)
		{
			XY.X = x;
			XY.Y = y;
			ReadMob(ThisMap, XY);
		}
	}
}
/*void GrabItem(Map *ThisMap)
{
	COORD XY;
	for(XY.X = 0; XY.X < MAP_SIZE_X; XY.X++)
	{
		for(XY.Y = 0; XY.Y < MAP_SIZE_Y; XY.Y++)
		{
			ReadItem(ThisMap, XY);
		}
	}
}*/
/*void ReadItem(Map *ThisMap, COORD TilePos)
{
	if(ThisMap->MapTile[TilePos.X][TilePos.Y].TileItem != NULL)
	{
	ThisMap->MapTile[TilePos.X][TilePos.Y].Out = ThisMap->MapTile[TilePos.X][TilePos.Y].TileItem->ItemOut;
	}
}*/
