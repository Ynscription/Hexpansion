#include "PlayState.h"

PlayState::PlayState(Game& game, int width, int height)
	: GameState(game)
	, _width(width)
	, _height(height) {
	//ctor
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

}


void PlayState::fixedUpdate (sf::Time deltaTime) {

}


void PlayState::render (sf::RenderTarget& renderer) {

}
