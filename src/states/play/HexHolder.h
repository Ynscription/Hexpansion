#ifndef HEXHOLDER_H
#define HEXHOLDER_H

#include <memory>
#include <unordered_map>

#include "Hex.h"
#include "HexVector.h"
#include "NonCopyable.h"

class HexHolder : public NonCopyable
{
	public:
		HexHolder();
		~HexHolder();

		template<typename... Args> //<Variadic template>, Args is some amount of arguments
		bool addHex (Args&&... args);	//Pass some amount of args as rvalue reference

		bool removeHex(int q, int r);
		bool removeHex(HexVector coords);

		Hex* getHex(int q, int r);
		Hex* getHex(HexVector coords);

		int count () {
			return _hexes.size();
		}


	private:
		struct PairHash {
			std::size_t elegantHash (const int& x, const int& y) const{
				//From http://szudzik.com/ElegantPairing.pdf
				//Max value of abs(x) and abs(y) is max value of 15 bits (32.767)
				int tempX = x >= 0 ? x*2 : x*2-1;
				int tempY = x >= 0 ? x*2 : x*2-1;
				return (tempX >= tempY) ? (tempX*tempX + tempX + tempY)
										: (tempY*tempY + tempX);
			}
		  	std::size_t operator()(const std::pair<int, int>& x) const {
				return elegantHash (x.first, x.second);
		  	}
		};

		std::unordered_map<std::pair<int, int>, std::shared_ptr<Hex>, PairHash> _hexes;


};

template<typename... Args>
bool HexHolder::addHex (Args&&... args) {
	std::shared_ptr<Hex> hex (std::make_shared<Hex>(std::forward<Args>(args)...));
	return _hexes.insert({std::pair<int,int> (hex->coords.q, hex->coords.r), std::move(hex)}).second;
}

#endif // HEXHOLDER_H
