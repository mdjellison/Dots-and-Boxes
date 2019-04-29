#include <iostream>
#include "Menu.h"
#include "GameMaster.h"

int main()
{
	Menu menu;
	for (;;)
	{
		menu.callMenu();
		if (menu.quitGame() == true) return 0;
		{
			GameMaster gM;
			gM.setPlayers();
			gM.createBoard();

			//Gameplay loop (turns)
			for (int i = 0; i < gM.numLines(); ++i)
			{
				gM.displayBoard();
				gM.playTurn(gM.getNumColumns(), gM.getNumRows());
			}
			gM.displayBoard();
			gM.displayScores();
		}
	}
}