struct Monster
{
	short ToHit;
	short HitDam;
	short Health;
	short CurrHealth;
	char MonOut;
	COORD MonsterPos;
	char MonName[30];
};
void SetMonster(Map *ThisMap, Monster *ThisMonster);
void MonsterGen(Map *ThisMap, Monster *ThisMonster, short MonType);
void MonsterDeath(Map *ThisMap, COORD MonPos);
