#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"

class MainMenuState : public GameState {
  public:
	MainMenuState(Game& game);
	~MainMenuState();

	void handleEvent (sf::Event e) override;
	void handleInput () override;
	void update (sf::Time deltaTime) override;
	void fixedUpdate (sf::Time deltaTime) override;
	void render (sf::RenderTarget& renderer) override;
};

#endif // MAINMENU_H
