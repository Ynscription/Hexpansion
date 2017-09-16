#include "Camera.h"

Camera::Camera(sf::Vector2f windowSize)
	: _view(sf::FloatRect(0, 0, windowSize.x, windowSize.y)) {
	//ctor
}

Camera::Camera(float winW, float winH)
	: _view(sf::FloatRect(0, 0, winW, winH)) {
	//ctor
}

Camera::~Camera()
{
	//dtor
}

void Camera::windowResized () {

}


void Camera::update (sf::Time deltaTime)  {

}
void Camera::fixedUpdate (sf::Time deltaTime)  {

}
void Camera::render (sf::RenderTarget& renderer) {

}
