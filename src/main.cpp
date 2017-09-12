#include "Game.h"
#include "MainMenuState.h"
#include <iostream>

int main() {
	Game game(1600, 900, "Hexpansion");
	game.pushState<MainMenuState>(game);
	try {
		game.run();
	}
	catch (const std::logic_error& e) {
		std::cerr << e.what();
	}
	return 0;
}
