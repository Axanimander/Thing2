#define MSGPOSX MAP_SIZE_X + 2
#define MSGPOSY 0
#define MSGT_GENERIC 1
#define MSGT_HIT 2
#define MSGSTACKSIZE 10
#define MSGMAXLEN 60
#define MSGVAR_NAME 1
#define MSGVAR_NAME2 2
#define MSGVAR_HITVAL 3
struct MessageStack //Not in use
{
	int Size;
	char MsgStack[MSGSTACKSIZE];
	char *CurrMsg;
}	typedef MessageStack;
struct Msg
{
	short MsgType;
	char MsgString[500];
	short MsgVars[10];
} typedef Msg;
void Message(Msg *ThisMsg);
void HitMsg(Msg *ThisMsg);
void AfterMsg();
