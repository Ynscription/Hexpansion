#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameState.h"


class Game {
  public:
	Game(unsigned width, unsigned height, std::string name, std::string iconName);
	~Game() = default;

	void run ();

	template<typename T, typename... Args> //<Variadic template>, Args is some amount of arguments
	void pushState (Args&&... args);	//Pass some amount of args as rvalue reference

	void popState();

	const sf::RenderWindow& getWindow() const;	//returns a <reference> (not a copy) to the render window

  private:
	sf::RenderWindow _window;
	std::vector<std::unique_ptr<GameState>> _states; //owner vector of States



	bool _shouldPop = false;

	void handleEvent();
	void tryPop();

	GameState& getCurrentState(); //returns currentState as <reference>


};

//Templated functions must be implemented in .h for compiler reasons
template<typename T, typename... Args>
void Game::pushState(Args&&... args) {
	/*Appends a state to _states
	**The state is initialized here,
		<make_unique> calls constructor with args as arguments and wraps it in a unique_ptr
	**This only needs
		the class(type) of the state we want to push and the arguments needed by the constructor, no reference*/
	_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}




#endif // GAME_H
