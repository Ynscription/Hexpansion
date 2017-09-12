#include "Game.h"

constexpr unsigned TPS = 60;	//Ticks Per Second
const sf::Time timePerUpdate = sf::seconds(1.f / float(TPS));


//public:
Game::Game(unsigned width, unsigned height, std::string name)
	: _window ({width,height}, name) {} //initializes _window (RenderWindow)


void Game::run() {
	if (_states.empty()) throw std::logic_error("No states in game.");

	unsigned ticks = 0;
	sf::Clock timer;
	//auto lastTime = sf::Time::Zero;
	auto lag = sf::Time::Zero;

	while (_window.isOpen() && !_states.empty()) {

		auto& state = getCurrentState();

		auto elapsed = timer.restart();
		lag += elapsed;

		//RT update
		state.handleInput();
		state.update(elapsed);

		//Fixed update
		while (lag >= timePerUpdate) {
			ticks++;
			lag -= timePerUpdate;
			state.fixedUpdate(timePerUpdate);
		}

		_window.clear();
		state.render(_window);
		_window.display();


		handleEvent();
		tryPop();
	}
}



void Game::popState() {
	_shouldPop = true;
}


const sf::RenderWindow& Game::getWindow() const {
	return _window;
}



//private:
void Game::handleEvent() {
	sf::Event e;

	while (_window.pollEvent(e)) {

		switch (e.type) {
		case sf::Event::Closed:
			_window.close();
			break;

		default:
			break;

		}
	}
}


void Game::tryPop() {
	if (_shouldPop) {
		_states.pop_back();	//Removes last element of vector
	}
}


GameState& Game::getCurrentState() {
	return *_states.back();
}

