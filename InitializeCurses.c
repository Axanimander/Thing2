#include "Core.h"

void Init()
{
	initscr();
	cbreak();
	clear();
	keypad(stdscr, 1);
	noecho();
}
