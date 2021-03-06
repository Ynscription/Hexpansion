#include "Game.h"



constexpr unsigned TPS = 60;	//Ticks Per Second
const sf::Time timePerUpdate = sf::seconds(1.f / float(TPS));


//public:
Game::Game(unsigned width, unsigned height, std::string name, std::string iconName)
	: _window ({width,height}, name) {
	_bgColor = sf::Color::White;
	sf::Image icon;
	if (icon.loadFromFile(iconName)) {
		_window.setIcon(256,256,icon.getPixelsPtr());
	}
}


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
			++ticks;
			lag -= timePerUpdate;
			state.fixedUpdate(timePerUpdate);
		}

		_window.clear(_bgColor);
		state.render(_window);
		_window.display();


		handleEvent();
		tryPop();
	}
}

void Game::close() {
	_window.close();
}


void Game::popState() {
	_shouldPop = true;
}


sf::RenderWindow& Game::getWindow() {
	return _window;
}

void Game::setBGColor (sf::Color color) {
	_bgColor = color;
}


//private:
void Game::handleEvent() {
	sf::Event e;
	GameState& state = getCurrentState();
	while (_window.pollEvent(e)) {
		state.handleEvent(e);
		/*switch (e.type) {
		case sf::Event::Closed:
			_window.close();
			break;

		default:
			break;

		}*/
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

