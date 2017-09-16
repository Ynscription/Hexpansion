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

		void update (sf::Time deltaTime) override;
		void fixedUpdate (sf::Time deltaTime) override;
		void render (sf::RenderTarget& renderer) override;

		void windowResized (unsigned int winW, unsigned int winH);

		void setMoveSpeed (float moveSpeed);

		sf::View& getView ();

	private:
		sf::View _view;
		float _moveSpeed = 500;
};

#endif // CAMERA_H
