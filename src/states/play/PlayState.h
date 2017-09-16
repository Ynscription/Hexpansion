#ifndef PLAY_H
#define PLAY_H

#include "GameState.h"
#include "Map.h"
#include "Camera.h"

class PlayState : public GameState {
  public:
	PlayState(Game& game, int width, int height);
	~PlayState();

	void handleEvent (sf::Event e) override;
	void handleInput () override;
	void update (sf::Time deltaTime) override;
	void fixedUpdate (sf::Time deltaTime) override;
	void render (sf::RenderTarget& renderer) override;

  private:
	int _width;
	int _height;
	Map _map;
	Camera _camera;


};

#endif // PLAY_H
