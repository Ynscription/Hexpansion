#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <unordered_map>

#include "SFML/Graphics.hpp"


class Entity {
  public:
	Entity() = default;
	virtual ~Entity() = default;

	virtual void update (sf::Time deltaTime) = 0;
	virtual void fixedUpdate (sf::Time deltaTime) = 0;
	virtual void render (sf::RenderTarget& renderer) = 0;



  private:
    sf::Vector2f _position;

};



#endif // ENTITY_H
