#ifndef PLAY_H
#define PLAY_H

#include "GameState.h"

class PlayState : public GameState {
  public:
	PlayState(Game& game);
	~PlayState();

	void handleEvent (sf::Event e) override;
	void handleInput () override;
	void update (sf::Time deltaTime) override;
	void fixedUpdate (sf::Time deltaTime) override;
	void render (sf::RenderTarget& renderer) override;
};

#endif // PLAY_H
