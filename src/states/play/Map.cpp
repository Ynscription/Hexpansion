#include "Map.h"

#include "HexVectorRectGenerator.h"

constexpr float moveSpeed = 100;

Map::Map(int width, int height) : _width (width), _height (height) {

	for (HexVectorRectGenerator rectGen (0, 0, _width, _height); !rectGen.isOOB(); ++rectGen) {
		_hexes.addHex(rectGen.get());
	}
}

Map::~Map()
{
	//dtor
}


void Map::update (sf::Time deltaTime) {

}

void Map::fixedUpdate (sf::Time deltaTime) {

}

void Map::render (sf::RenderTarget& renderer) {
	Hex* hex = nullptr;

	for (HexVectorRectGenerator rectGen (0, 0, _width, _height); !rectGen.isOOB(); ++rectGen) {
		hex = _hexes.getHex(rectGen.get());
		if (hex != nullptr) {
			hex->render(renderer, HexVector::hexToPixel(hex->coords, _HEX_SIZE), _HEX_SIZE);
		}
	}
}





