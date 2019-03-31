#include "TicketManager.h"

void main()
{
	TicketManager tm;
	
	tm.loadFile();
	tm.getMenu();
	tm.saveFile();
}