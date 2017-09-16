#include "Camera.h"


#include <SFML/Graphics.hpp>

Camera::Camera(sf::Vector2u windowSize)
	: _view(sf::FloatRect(0, 0, windowSize.x, windowSize.y)) {
	//ctor
}

Camera::Camera(int winW, int winH)
	: _view(sf::FloatRect(0, 0, winW, winH)) {
	//ctor
}

Camera::~Camera()
{
	//dtor
}

void Camera::windowResized (unsigned int winW, unsigned int winH) {
    _view.setSize(sf::Vector2f (winW, winH));
}

void Camera::setMoveSpeed (float moveSpeed) {
		_moveSpeed = moveSpeed;
}

sf::View& Camera::getView () {
	return _view;
}


void Camera::update (sf::Time deltaTime)  {

}
void Camera::fixedUpdate (sf::Time deltaTime)  {
	float dt = deltaTime.asSeconds();
	float x = 0, y = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		x -= _moveSpeed*dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		x += _moveSpeed*dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		y -= _moveSpeed*dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		y += _moveSpeed*dt;
	}
	_view.move(x, y);
}
void Camera::render (sf::RenderTarget& renderer) {
	renderer.setView(_view);
}
