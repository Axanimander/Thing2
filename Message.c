#include "Core.h"



void Message(Msg *ThisMsg)
{
	switch(ThisMsg->MsgType)
	{
		case MSGT_GENERIC:
			mvprintw(MSGPOSX, MSGPOSY, "%s", ThisMsg->MsgString);
			refresh();
			getch();
			move(MSGPOSX, MSGPOSY);
			clrtoeol();
	}
}

void AfterMsg()
{
	refresh();
	getch();
	move(MSGPOSX, MSGPOSY);
	clrtoeol();
}
