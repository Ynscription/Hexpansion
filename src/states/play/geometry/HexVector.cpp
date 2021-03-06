#include "HexVector.h"


constexpr float ThreeHalfs = (3.f/2.f);
constexpr float TwoThirds = (2.f/3.f);
constexpr float sqrtThree = sqrt(3);

HexVector::HexVector(int cq, int cr) : q(cq), r(cr) {
	//ctor
}

HexVector::~HexVector() {
	//dtor
}


///Geometric operations
//Cube coordinates of a hex are expressed as (x, y, z)
sf::Vector3<int> HexVector::axialToCube (const HexVector& hex) {
	return sf::Vector3<int>(hex.q, -hex.q -hex.r, hex.r);
}
HexVector HexVector::cubeToAxial (const sf::Vector3<int>& cube){
	return HexVector(cube.x, cube.z);
}

//Transforms the coordinates of a hex to coordinates on screen, requires de size of a side of the hex
sf::Vector2f HexVector::hexToPixel (const HexVector& hex, int size) {
	float x = float(size) * ThreeHalfs * float(hex.q);
	float y = float(size) * sqrtThree * (float(hex.r) + float(hex.q)/2.f);
	return sf::Vector2f(x, y);
}
HexVector HexVector::pixelToHex	(const sf::Vector2f& pixel, int size) {
	float q = ((pixel.x * TwoThirds) / float(size));
    float r = (((sqrtThree*pixel.y - pixel.x)/3.f) / float(size));
    return roundHex(sf::Vector2f(q, r));
}

//Round hex takes a Vector2f where (x = q, y = r), that represents a decimal hex coordinate
//and returns a valid HexVector
HexVector HexVector::roundHex (const sf::Vector2f& fracHex) {
	float y = -fracHex.x - fracHex.y;
	int rx = std::round(fracHex.x);
	int ry = std::round(y);
	int rz = std::round(fracHex.y);

	float x_diff = std::abs(rx - fracHex.x);
	float y_diff = std::abs(ry - y);
	float z_diff = std::abs(rz - fracHex.y);

	if ((x_diff > y_diff) && (x_diff > z_diff)) {
		rx = -ry - rz;
	}else if (y_diff <= z_diff) {
		rz = -rx - ry;;
	}
	return  HexVector(rx, rz);
}










///HexVector Operations
HexVector& HexVector::operator+=(const HexVector& rhs) {
	q += rhs.q;
	r += rhs.r;
	return *this;
}

HexVector& HexVector::operator-=(const HexVector& rhs)  {
	q -= rhs.q;
	r -= rhs.r;
	return *this;
}

HexVector& HexVector::operator*=(const int& rhs) {
	q *= rhs;
	r *= rhs;
	return *this;
}

HexVector& HexVector::operator/=(const int& rhs) {
	q /= rhs;
	r /= rhs;
	return *this;
}








