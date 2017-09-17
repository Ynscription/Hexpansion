#include "Camera.h"


#include <SFML/Graphics.hpp>

constexpr float MAX_ZOOM = 2.f;
constexpr float MIN_ZOOM = 1.f/3.f;

Camera::Camera(sf::Vector2u windowSize)
	: _view(sf::FloatRect(0, 0, windowSize.x, windowSize.y))
	, _windowSize(windowSize)
	, _currentSize (windowSize) {
	//ctor
}

Camera::Camera(int winW, int winH)
	: _view(sf::FloatRect(0, 0, winW, winH))
	, _windowSize(winW, winH) {
	//ctor
}

Camera::~Camera()
{
	//dtor
}

sf::Vector2f Camera::zoom (sf::Vector2f& size, float zoom) {
	size.x = std::round(size.x*zoom);
	size.y = std::round(size.y*zoom);
	return size;
}

void Camera::resetZoom () {
	_currentSize.x = _windowSize.x;
	_currentSize.y = _windowSize.y;
}

void Camera::handleEvent (const sf::Event& e) {
	if (e.type == sf::Event::Resized) {
		float currZoom = float(_currentSize.x) / float(_windowSize.x);
		_windowSize.x = e.size.width;
		_windowSize.y = e.size.height;
		_currentSize.x = e.size.width;
		_currentSize.y = e.size.height;
		_view.setSize(zoom(_currentSize, currZoom));

	}
	if (e.type == sf::Event::MouseWheelScrolled) {
		float change = 1.f - float(e.mouseWheelScroll.delta)*0.1f;
		_view.setSize(zoom(_currentSize, change));
		float currZoom = float(_currentSize.x) / float(_windowSize.x);
		if (currZoom >= MAX_ZOOM) {
			resetZoom();
			_view.setSize(zoom(_currentSize, MAX_ZOOM));
		}
		if (currZoom < MIN_ZOOM) {
			resetZoom();
			_view.setSize(zoom(_currentSize, MIN_ZOOM));
		}
	}
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
