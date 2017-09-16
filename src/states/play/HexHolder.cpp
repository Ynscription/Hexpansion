#include "HexHolder.h"

HexHolder::HexHolder()
{
}

HexHolder::~HexHolder()
{
}


bool HexHolder::removeHex(int q, int r) {
	return _hexes.erase(std::pair<int,int>(q, r)) == 1;
}
bool HexHolder::removeHex(HexVector coords) {
	return _hexes.erase(std::pair<int,int>(coords.q, coords.r)) == 1;
}

Hex* HexHolder::getHex(int q, int r) {
	Hex * res = nullptr;
	auto found = _hexes.find(std::pair<int,int>(q, r));
	if (found != _hexes.end()) {
		res = found->second.get();
	}
	return res;
}
Hex* HexHolder::getHex(HexVector coords) {
	Hex * res = nullptr;
	auto found = _hexes.find(std::pair<int,int>(coords.q, coords.r));
	if (found != _hexes.end()) {
		res = found->second.get();
	}
	return res;
}
