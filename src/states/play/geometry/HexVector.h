#ifndef HEXVECTOR_H
#define HEXVECTOR_H

#include "SFML/Graphics.hpp"

struct HexVector {

	int q = 0;
	int r = 0;

	HexVector(int q, int r);
	~HexVector();

	HexVector& operator+=(const HexVector& rhs);
	HexVector& operator-=(const HexVector& rhs);

	HexVector& operator*=(const int& rhs);
	HexVector& operator/=(const int& rhs);

	//Cube coordinates of a hex are expressed as (x, y, z)
	static sf::Vector3<int> axialToCube (const HexVector& hex);
	static HexVector cubeToAxial (const sf::Vector3<int>& cube);

	//Round hex takes a Vector2f where (x = q, y = r), that represents a decimal hex coordinate
	//and returns a valid HexVector
	static HexVector roundHex (const sf::Vector2f& decHex);

	//Transforms the coordinates of a hex to coordinates on screen, requires de size of a side of the hex
	static sf::Vector2f hexToPixel (const HexVector& hex, int size);
	static HexVector pixelToHex	(const sf::Vector2f& pixel, int size);

};

//Array of unitary hex vectors of the 6 immediate directions of a hex
	const static HexVector AXIAL_DIRECTIONS[6] = {				//Map	  3 \2 / 1
		HexVector( 1, 0), HexVector( 1,-1), HexVector( 0,-1),	//	 	  __/‾‾\__
		HexVector(-1, 0), HexVector(-1, 1), HexVector( 0, 1)	//	  	    \__/
	};															//		  4 /5 \ 0

	//Array of unitary hex vectors of the 6 immediate diagonals of a hex	2/  \1		|
	const static HexVector AXIAL_DIAGONALS [6] = {				//Map	   ‾‾\  /‾‾		|
		HexVector( 2,-1), HexVector( 1,-2), HexVector(-1,-1),	//		 3\__/‾‾\__/0	|
		HexVector(-2, 1), HexVector(-1, 2), HexVector( 1, 1)	//		  /  \__/  \    |
	};															//		   __/  \__		|
																//			4\  /5		|


inline HexVector operator+(HexVector lhs, const HexVector& rhs) {
	lhs += rhs;
	return lhs;
}
inline HexVector operator-(HexVector lhs, const HexVector& rhs) {
	lhs -= rhs;
	return lhs;
}

inline HexVector operator*(HexVector lhs, const int& rhs) {
	lhs *= rhs;
	return lhs;
}
inline HexVector operator/(HexVector lhs, const int& rhs) {
	lhs /= rhs;
	return lhs;
}

inline bool operator==(const HexVector& lhs, const HexVector& rhs) {
	return (lhs.q == rhs.q)&&(lhs.r == rhs.r);
}
inline bool operator!=(const HexVector& lhs, const HexVector& rhs){return !operator==(lhs,rhs);}


#endif // HEXVECTOR_H
