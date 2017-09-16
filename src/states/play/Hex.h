#ifndef HEX_H
#define HEX_H

#include <SFML/Graphics.hpp>

#include "HexVector.h"


class Hex {
  public:
	HexVector coords;

	Hex(int q, int r);
	Hex(HexVector coords);
	Hex(const Hex& other) = delete;
	~Hex();

	HexVector getNeighbour (int dir);	//For mor info on dir -> HexVector.h
	HexVector getDiagonal (int dir);
	int getDistanceTo (const Hex& other);	//Distance in hexes to another hex
	void setHovered(bool val);
	void setSelected (bool val);

	void render (sf::RenderTarget& renderer, sf::Vector2f position, int size);

  private:
  	const sf::Color NORMAL_COLOR 	= sf::Color::White;
	const sf::Color SELECTED_COLOR 	= sf::Color::Green;
	const sf::Color HOVERED_COLOR 	= sf::Color::Blue;

	sf::ConvexShape _hexagon;

	bool _isHovered = false;
	bool _isSelected = false;
	sf::Color _currentColor;
	int _zeroSize = -1;

	void setColor ();
	void setVertices (int size);

	//Gets a corner position of a hex, useful for drawing
	static sf::Vector2f hexCorner(int size, int i);

};

inline bool operator==(const Hex& lhs, const Hex& rhs) {
	return (lhs.coords == rhs.coords);
}
inline bool operator!=(const Hex& lhs, const Hex& rhs){return !operator==(lhs,rhs);}

#endif // HEX_H
