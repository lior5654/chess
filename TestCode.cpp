#include <iostream>

using std::cout;
#include "Game.h"
int main()
{
	Game game = Game();
	while (true)
	{
		game.update();
	}
}