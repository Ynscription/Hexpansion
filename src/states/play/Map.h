#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "HexHolder.h"


class Map : public Entity
{
	public:
		Map(int width, int height, sf::RenderWindow& window);
		Map(const Map& other) = delete;
		~Map();

		//void mouseClicked (int x, int y);

		void handleEvent(const sf::Event& e) override;

		void update (sf::Time deltaTime) override;
		void fixedUpdate (sf::Time deltaTime) override;
		void render (sf::RenderTarget& renderer) override;

	private:
		int _HEX_SIZE = 100;
		int _width;
		int _height;

		sf::RenderWindow& _window;

		Hex* _hoveredHex = nullptr;
		Hex* _selectedHex = nullptr;
		HexHolder _hexes;


};

#endif // MAP_H
