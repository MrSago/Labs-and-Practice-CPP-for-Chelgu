#ifndef BIGNUM_H
#define BIGNUM_H

#include <climits>

typedef unsigned int Word;

class BigNum
{
	private:
		Word *buf;
		size_t size;
		void init();

	public:
		BigNum();
		BigNum(unsigned int n);
		const BigNum& operator=(const BigNum& obj);
		void operator++(int) const;
		BigNum operator+(const BigNum& obj) const;
		BigNum operator*(const BigNum& obj) const;
		void printHex();
		void printDec();
		void free();
		size_t memusage();
};

#endif //BIGNUM_H