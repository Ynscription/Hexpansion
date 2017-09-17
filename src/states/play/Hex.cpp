#include "Hex.h"


constexpr float pi = 3.14159265358979323846f;
constexpr float piThirds = pi/3.f;

Hex::Hex(HexVector ccoords) : coords(ccoords) {
	_hexagon.setPointCount(6);
	_hexagon.setOutlineThickness(-3);
	_hexagon.setOutlineColor(sf::Color::Black);
}

Hex::Hex(int q, int r) : coords(q, r) {
	_hexagon.setPointCount(6);
	_hexagon.setOutlineThickness(-3);
	_hexagon.setOutlineColor(sf::Color::Black);
}

Hex::~Hex() {
	//dtor
}

///Other Hexes
HexVector Hex::getNeighbour (int dir) {
	return AXIAL_DIRECTIONS[dir] + coords;
}

HexVector Hex::getDiagonal (int dir){
	return AXIAL_DIAGONALS[dir] + coords;
}

int Hex::getDistanceTo (const Hex& other) {
	return std::max({
				std::abs(coords.q - other.coords.q),
				std::abs(coords.q + coords.r - other.coords.q - other.coords.r),
				std::abs(coords.r - other.coords.r)
			});
}

///Modify hex
void Hex::setColor() {
	if (_isSelected) {
		_hexagon.setFillColor(SELECTED_COLOR);
	}else {
		if (_isHovered) {
			_hexagon.setFillColor(HOVERED_COLOR);
		}else {
			_hexagon.setFillColor(NORMAL_COLOR);
		}
	}
}

void Hex::setHovered(bool val) {
	_isHovered = val;
	setColor();
}

void Hex::setSelected (bool val) {
	_isSelected = val;
	setColor();
}

///Render hex
sf::Vector2f Hex::hexCorner(int size, int i) {
	float angle = piThirds * i;
	return sf::Vector2f (size*cos(angle), size*sin(angle));
}

void Hex::setVertices(int size) {
	for (int i = 0; i < 6; ++i) {
		_hexagon.setPoint(i, hexCorner(size, i));
	}
}

void Hex::render (sf::RenderTarget& renderer, sf::Vector2f position, int size) {
    //sf::Transform trans;
    //trans.translate(position);

    if (_zeroSize != size)
		setVertices(size);
	_hexagon.setPosition(position);
    renderer.draw(_hexagon);
}


