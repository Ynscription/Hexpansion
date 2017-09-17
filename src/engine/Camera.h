#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

#include "Entity.h"


class Camera : public Entity
{
	public:
		Camera(sf::Vector2u windowSize);
		Camera(int windW, int winH);
		~Camera();

		void handleEvent (const sf::Event& e) override;

		void update (sf::Time deltaTime) override;
		void fixedUpdate (sf::Time deltaTime) override;
		void render (sf::RenderTarget& renderer) override;

		void windowResized (unsigned int winW, unsigned int winH);

		void setMoveSpeed (float moveSpeed);

		sf::View& getView ();

	private:
		sf::View _view;
		float _moveSpeed = 500;
		sf::Vector2u _windowSize;
		sf::Vector2f _currentSize;

		sf::Vector2f zoom (sf::Vector2f& size, float zoom);
		void resetZoom();
};

#endif // CAMERA_H
