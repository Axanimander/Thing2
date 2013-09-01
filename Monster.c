#include "Core.h"

void SetMonster(Map *ThisMap, Monster *ThisMonster)
{
	RandVPos(ThisMap, &ThisMonster->MonsterPos);
	ThisMap->MapTile[ThisMonster->MonsterPos.X][ThisMonster->MonsterPos.Y].TileMob = ThisMonster;
	ThisMap->MapTile[ThisMonster->MonsterPos.X][ThisMonster->MonsterPos.Y].IsWalk = 0;
}

void MonsterGen(Map *ThisMap, Monster *ThisMonster, short MonType)
{
	ThisMonster->MonsterPos.X = 0;
	ThisMonster->MonsterPos.Y = 0;
	switch(MonType)
	{
		case 1: // A rat
			ThisMonster->Health = getrand(7, 3);
			ThisMonster->HitDam = getrand(3, 2);
			ThisMonster->ToHit = getrand(30, 22);
			ThisMonster->MonOut = 'r';
			strcpy(ThisMonster->MonName, "Rat");
			break;
	}
	SetMonster(ThisMap, ThisMonster);
	ThisMonster->CurrHealth = ThisMonster->Health;
}

void MonsterDeath(Map *ThisMap, COORD MonPos)
{
	
	 ThisMap->MapTile[MonPos.X][MonPos.Y].TileMob = NULL;
	 RemoveObj(ThisMap, MonPos);
	 DrawMap(ThisMap);
	 //Item drop will be called here when it is implemented.
};
