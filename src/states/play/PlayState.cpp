#include "PlayState.h"


#include "Game.h"
#include "Hex.h"

PlayState::PlayState(Game& game, int width, int height)
	: GameState::GameState(game)
	, _width(width)
	, _height(height)
	, _map (width, height){

	game.setBGColor(sf::Color{128, 0, 128});

}


PlayState::~PlayState()
{
	//dtor
}


void PlayState::handleEvent (sf::Event e){

}


void PlayState::handleInput () {

}


void PlayState::update (sf::Time deltaTime) {
	_map.update(deltaTime);
}


void PlayState::fixedUpdate (sf::Time deltaTime) {
	_map.fixedUpdate(deltaTime);
}


void PlayState::render (sf::RenderTarget& renderer) {
	_map.render(renderer);
}
