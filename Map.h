struct Tile
{
	COORD Pos;
	char Out;
	char Base; //What the tile looks like when it is empty
	short IsWalk;
	Item *TileItem;
	Monster *TileMob;
	Player *TilePlayer;
} typedef Tile;

struct Map
{
	Tile MapTile[MAP_SIZE_X][MAP_SIZE_Y];
} typedef Map;

void PutTile(Map *ThisMap, COORD TilePos, char TileOut); 
void ClearTile(Tile *ThisTile);
void OutTile(Tile *ThisTile);
void PutRoom(Map *ThisMap, COORD TL, COORD BR); //All rooms will be square initially
void PutTunnel(Map *ThisMap, COORD Start, COORD Finish);
void InitMap(Map *ThisMap);
void GenMap(Map *ThisMap, COORD RSize, int RCount);
void DrawMap(Map *ThisMap);
void PutObj(Map *ThisMap, COORD TilePos, char Object);
void MoveObj(Map *ThisMap, COORD Pos, COORD Put);
void RandVPos(Map *ThisMap, COORD *RandPos);
void ReadMob(Map *ThisMap, COORD TilePos);
void GrabMob(Map *ThisMap);
void RemoveObj(Map *ThisMap, COORD Put);
//void GrabItem(Map *ThisMap);
//void ReadItem(Map *ThisMap, COORD TilePos);
