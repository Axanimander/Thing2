struct Race
{
	COORD HealthMinMax;
	COORD StrMinMax;
	COORD DexMinMax;
	COORD IntMinMax;
	char RaceString[30];
} typedef Race;
struct Class
{
	COORD ModHealthMinMax;
	COORD ModStrMinMax;
	COORD ModDexMinMax;
	COORD ModIntMinMax;
	char ClassString[30];
} typedef Class;
struct Player
{
	Inventory PInventory;
	Equipment PEquipment;
	char PName[30];
	char PDescript[1500];
	int Health;
	int CurrHealth;
	short Strength;
	short Dex;
	short Int;
	Race PRace;
	Class PClass;
	COORD PlayerPos;
	char PlayerOut;
};



void RollPlayer(Player *ThisPlayer);
void GetRace(Player *ThisPlayer);
void SetRace(Player *ThisPlayer, short Choice);
void GetClass(Player *ThisPlayer);
void SetClass(Player *ThisPlayer, short Choice);
void DescribePlayer(Player *ThisPlayer);
void GenPlayer(Player *ThisPlayer);
void EndGame(Player *ThisPlayer);
void MovePlayer(Map *ThisMap, Player *ThisPlayer, short Key);
void SetPlayer(Map *ThisMap, Player *ThisPlayer);
void PlayerHit(Monster *ThisMonster, Player *ThisPlayer);
void Attack(Map *ThisMap, Player *ThisPlayer, short AttackDir);
void DisplayStats(Player *ThisPlayer);
