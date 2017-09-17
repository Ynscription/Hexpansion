#include "PlayState.h"


#include "Game.h"
#include "Hex.h"

PlayState::PlayState(Game& game, int width, int height)
	: GameState::GameState(game)
	, _width(width)
	, _height(height)
	, _map (width, height, game.getWindow())
	, _camera (game.getWindow().getSize()) {
	game.setBGColor(sf::Color{128, 0, 128});

}


PlayState::~PlayState()
{
	//dtor
}


void PlayState::handleEvent (const sf::Event& e){
	if (e.type == sf::Event::Closed) {
		GameState::_pGame->close();
	}
	if (e.type == sf::Event::Resized) {
		_camera.handleEvent(e);
	}
	if (e.type == sf::Event::MouseWheelScrolled) {
		_camera.handleEvent(e);
	}
	if (e.type == sf::Event::MouseButtonPressed) {
		_map.handleEvent(e);
	}
}


void PlayState::handleInput () {

}


void PlayState::update (sf::Time deltaTime) {
	_camera.update (deltaTime);
	_map.update(deltaTime);
}


void PlayState::fixedUpdate (sf::Time deltaTime) {
	_camera.fixedUpdate (deltaTime);
	_map.fixedUpdate(deltaTime);
}


void PlayState::render (sf::RenderTarget& renderer) {
	_camera.render(renderer);
	_map.render(renderer);
}
