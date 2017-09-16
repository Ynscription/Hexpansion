#include <iostream>
//#include <cstdlib>

#include "Game.h"
#include "PlayState.h"


int main() {

	Game game(1600, 900, "Hexpansion", "resources/icon_hexpansion.png");
	game.pushState<PlayState>(game, 100, 40);
	try {
		game.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
	return 0;
}


