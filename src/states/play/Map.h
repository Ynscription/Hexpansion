#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "HexHolder.h"


class Map : public Entity
{
	public:
		Map(int width, int height);
		Map(const Map& other) = delete;
		~Map();

		void update (sf::Time deltaTime) override;
		void fixedUpdate (sf::Time deltaTime) override;
		void render (sf::RenderTarget& renderer) override;

	private:
		int _HEX_SIZE = 100;
		int _width;
		int _height;

		HexHolder _hexes;


};

#endif // MAP_H
