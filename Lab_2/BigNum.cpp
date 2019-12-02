#include "BigNum.h"
#include <iostream>
#include <cstdlib>

constexpr Word WORD_MAX = UINT_MAX;
constexpr unsigned long long WORD_BASE = (unsigned long long)WORD_MAX + 1;


void BigNum::init() { buf = new Word[size]; }

BigNum::BigNum() : size(0) { }
BigNum::BigNum(unsigned int n) : size(1) { init(); buf[0] = n; }

const BigNum& BigNum::operator=(const BigNum& obj)
{
	free();
	buf = obj.buf;
	size = obj.size;
	return *this;
}

void BigNum::operator++(int) const { ++buf[0]; }

BigNum BigNum::operator+(const BigNum& obj) const
{
	BigNum bigResult;
	unsigned char digit = false;


	bigResult.size = size;
	bigResult.buf = new Word[bigResult.size];

	for (size_t i = 0; i < size; ++i)
	{
		if (i < obj.size)
		{
			if (digit)
			{
				Word tmp;

				if (buf[i] > WORD_MAX - digit)
				{
					bigResult.buf[i] = obj.buf[i];
					digit = true;
					continue;
				}
				else
				{
					tmp = buf[i] + digit;
					digit = false;
				}

				if (tmp > WORD_MAX - obj.buf[i])
				{
					Word tmpMax = WORD_MAX - tmp;
					Word tmpMin = WORD_MAX - obj.buf[i];

					bigResult.buf[i] = WORD_MAX - (tmpMax + tmpMin + 1) + digit;
					digit = true;
				}
				else
				{
					bigResult.buf[i] = tmp + obj.buf[i];
				}
			}
			else //(!digit)
			{
				if (buf[i] > WORD_MAX - obj.buf[i])
				{
					Word tmpMax = WORD_MAX - buf[i];
					Word tmpMin = WORD_MAX - obj.buf[i];

					bigResult.buf[i] = WORD_MAX - (tmpMax + tmpMin + 1);
					digit = true;
				}
				else
				{
					bigResult.buf[i] = buf[i] + obj.buf[i];
				}
			}
		}
		else //(i >= bigMin.size)
		{
			if (digit)
			{
				if (buf[i] > WORD_MAX - digit)
				{
					bigResult.buf[i] = 0;
					digit = true;
				}
				else
				{
					bigResult.buf[i] = buf[i] + digit;
					digit = false;
				}
			}
			else //(!digit)
			{
				bigResult.buf[i] = buf[i];
			}
		}
	}

	if (digit)
	{
		Word *tmp = bigResult.buf;

		bigResult.buf = new Word[++bigResult.size];
		for (size_t j = 0; j < bigResult.size - 1; ++j)
			bigResult.buf[j] = tmp[j];

		bigResult.buf[bigResult.size - 1] = digit;
		delete tmp;
	}

	delete buf;

	return bigResult;
}

BigNum BigNum::operator*(const BigNum& obj) const
{
	BigNum bigResult;
	BigNum *bigAdd;


	bigAdd = new BigNum[obj.size];

	for (size_t i = 0; i < obj.size; ++i)
	{
		bigAdd[i].size = size + i;
		bigAdd[i].buf = new Word[bigAdd[i].size];

		for (size_t j = 0; j < i; ++j)
			bigAdd[i].buf[j] = 0;
	}

	for (size_t i = 0; i < obj.size; ++i)
	{
		Word digit = 0;

		for (size_t j = 0; j < size; ++j)
		{
			unsigned long long tmp = ((unsigned long long)buf[j] * (unsigned long long)obj.buf[i]) + digit;
			digit = (Word)(tmp / WORD_BASE);
			bigAdd[i].buf[j + i] = (Word)(tmp % WORD_BASE);
		}

		if (digit)
		{
			Word *tmp = bigAdd[i].buf;

			bigAdd[i].buf = new Word[++bigAdd[i].size];
			for (size_t j = 0; j < bigAdd[i].size - 1; ++j)
				bigAdd[i].buf[j] = tmp[j];

			bigAdd[i].buf[bigAdd[i].size - 1] = digit;
			delete tmp;
		}
	}

	if (obj.size == 1)
	{
		bigResult.buf = bigAdd[0].buf;
		bigResult.size = bigAdd[0].size;
	}
	else //(bigMin.size > 1)
	{
		bigResult = bigAdd[0] + bigAdd[1];

		for (size_t i = 2; i < obj.size; ++i)
		{
			bigResult = bigResult + bigAdd[i];
		}

		for (size_t i = 0; i < obj.size; ++i)
			delete[](bigAdd[i].buf);
	}

	delete bigAdd;

	return bigResult;
}

void BigNum::printHex()
{
	for (size_t i = size; i > 0; --i)
	{
		size_t index = i - 1;
		char tmp[8 + 1];
		size_t len;


		_i64toa_s(buf[index], tmp, 9, 16);

		if ((index + 1) < size && (len = strlen(tmp)) < 8)
		{
			for (size_t k = 8 - len; k > 0; --k)
			{
				putchar('0');
			}
		}

		std::cout << tmp;
	}
}

void BigNum::printDec()
{
	//
}

void BigNum::free()
{
	if (buf != nullptr)
		delete buf;
	size = 0;
}

size_t BigNum::memusage() { return (size * sizeof(Word) + sizeof(BigNum)); }