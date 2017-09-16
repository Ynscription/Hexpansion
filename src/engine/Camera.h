#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

#include "Entity.h"


class Camera : public Entity
{
	public:
		Camera(sf::Vector2f windowSize);
		Camera(float windW, float winH);
		~Camera();

		void update (sf::Time deltaTime) override;
		void fixedUpdate (sf::Time deltaTime) override;
		void render (sf::RenderTarget& renderer) override;

		void windowResized ();

	private:
		sf::View _view;
};

#endif // CAMERA_H
