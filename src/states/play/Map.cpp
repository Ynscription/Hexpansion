#include "Map.h"

#include "HexVectorRectGenerator.h"


Map::Map(int width, int height, sf::RenderWindow& window)
	: _width (width), _height (height)
	, _window (window) {

	for (HexVectorRectGenerator rectGen (0, 0, _width, _height); !rectGen.isOOB(); ++rectGen) {
		_hexes.addHex(rectGen.get());
	}
}

Map::~Map()
{
	//dtor
}

void Map::handleEvent(const sf::Event& e) {
	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {
		int x = e.mouseButton.x;
		int y = e.mouseButton.y;
		sf::Vector2f worldPos = _window.mapPixelToCoords(sf::Vector2i(x, y));
		HexVector selectedCoords = HexVector::pixelToHex(worldPos, _HEX_SIZE);
		Hex* selectedHex = _hexes.getHex(selectedCoords);
		if (_selectedHex != selectedHex) {
			if (_selectedHex != nullptr) {
				_selectedHex->setSelected(false);
			}
			_selectedHex = selectedHex;
			if (_selectedHex != nullptr) {
				_selectedHex->setSelected(true);
			}
		}
	}
}


void Map::update (sf::Time deltaTime) {

}

void Map::fixedUpdate (sf::Time deltaTime) {
	sf::Vector2f worldPos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
	HexVector hoveredCoords = HexVector::pixelToHex(worldPos, _HEX_SIZE);
	Hex* hoveredHex = _hexes.getHex(hoveredCoords);
	if (_hoveredHex != hoveredHex) {
		if (_hoveredHex != nullptr) {
			_hoveredHex->setHovered(false);
		}
		_hoveredHex = hoveredHex;
		if (_hoveredHex != nullptr) {
			_hoveredHex->setHovered(true);
		}
	}
}

void Map::render (sf::RenderTarget& renderer) {
	Hex* hex = nullptr;
	sf::Vector2f vPos = renderer.getView().getCenter();
	sf::Vector2f vSize = renderer.getView().getSize();
	vPos.x -= vSize.x/2.f;
	vPos.y -= vSize.y/2.f;

	HexVector origin = HexVector::pixelToHex(vPos, _HEX_SIZE);
	HexVector endingQ = HexVector::pixelToHex(vSize, _HEX_SIZE);
	vSize.x = 0;
	HexVector endingR = HexVector::pixelToHex(vSize, _HEX_SIZE);
	origin.q -= 1;
	endingQ.q += 3;
	origin.r -= 1;
	//TODO there should be a better way
	endingR.r += 4;
	int i = 0;
	for (HexVectorRectGenerator rectGen (origin, endingQ.q, endingR.r); !rectGen.isOOB(); ++rectGen) {
		hex = _hexes.getHex(rectGen.get());
		if (hex != nullptr) {
			hex->render(renderer, HexVector::hexToPixel(hex->coords, _HEX_SIZE), _HEX_SIZE);
		}
		i++;
	}
}





