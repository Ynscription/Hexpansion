#include "Game.h"
#include "PlayState.h"
#include <iostream>
//#include <cstdio>
//#include <cstdlib>


int main() {
	Game game(1600, 900, "Hexpansion", "resources/icon_hexpansion.png");
	game.pushState<PlayState>(game, 1000, 1000);
	try {
		game.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
	return 0;
}


