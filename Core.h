#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAP_SIZE_X 20
#define MAP_SIZE_Y 64
#define TRUE 1
#define FALSE 0
#define FLOOR '.'
#define INVSIZE 27
#define LISTENUM 'a' - 1 //What the hell is this?
typedef unsigned char byte;
struct COORD
{
	short X;
	short Y;
} typedef COORD;
#include "ItemDefs.h"
#include "Typedefs.h"
#include "RandomGen.h"
#include "InitializeCurses.h"
#include "Map.h"
#include "KeyDefs.h"
#include "Control.h"
#include "Message.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
