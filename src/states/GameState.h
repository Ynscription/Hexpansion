#ifndef STATEBASE_H
#define STATEBASE_H

#include <SFML/Graphics.hpp>

#include "NonCopyable.h"

class Game;

class GameState : public NonCopyable {
  public:
	GameState(Game& game) : _pGame(&game){} //Initialize m_pGame to game
	virtual ~GameState() = default;

	virtual void handleEvent (sf::Event e) = 0; //abstract (pure virtual) function (must be implemented in inheritors)
	virtual void handleInput () = 0;
	virtual void update (sf::Time deltaTime) = 0;
	virtual void fixedUpdate (sf::Time deltaTime) = 0;
	virtual void render (sf::RenderTarget& renderer) = 0;

  protected:
  	Game* _pGame;

};

#endif // STATEBASE_H
