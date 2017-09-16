#ifndef HEXVECTORRECTGENERATOR_H
#define HEXVECTORRECTGENERATOR_H


#include "HexVector.h"

class HexVectorRectGenerator
{
	public:
		HexVectorRectGenerator(const HexVector& origin, int width, int height)
			: _origin (origin) {
			_width = width;
			_q = _origin.q + width -1;
			_r = _origin.r;
			_stopQ = _origin.q;
			_stopR = _origin.r + height -1;

		}
		HexVectorRectGenerator(int q, int r, int width, int height)
			: _origin (q, r) {
			_width = width;
			_q = _origin.q + width -1;
			_r = _origin.r;
			_stopQ = _origin.q;
			_stopR = _origin.r + height -1;

		}

		~HexVectorRectGenerator() {}



		HexVector get() {
			int diff = int((_q - _stopQ)/2);
			return HexVector(_q, _r - diff);
		}

		bool isOOB () {
			return ((_q < _stopQ) || (_q >= _origin.q + _width));
		}

		HexVectorRectGenerator& operator++() {
			++_r;
			if (_r >= _stopR) {
				_r = _origin.r;
				--_q;
			}
			return *this;
		}

		HexVectorRectGenerator& operator--() {
			--_r;
			if (_r < _origin.r) {
				_r = _stopR;
				++_q;
			}
			return *this;
		}




	private:
		int _q;
		int _r;
		int _stopQ;
		int _stopR;
		HexVector _origin;
		int _width;
};

#endif // HEXVECTORRECTGENERATOR_H
