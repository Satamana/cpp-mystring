#pragma once
#include "stdafx.h"
class Stringi
{
	char *str = nullptr;
	size_t size = 0;
public:
	Stringi() = default;
	Stringi(size_t n) : size(n) { this->str = (char*)malloc(n); }
	Stringi(char *s);
	Stringi(const Stringi &);
	Stringi(Stringi &&);
	Stringi & operator=(const Stringi &);
	Stringi operator*(const Stringi &);
	char operator[](int i) { return this->str[i]; }
	int operator()(char);
	operator int() { return strlen(this->str); }
	friend std::istream & operator>>(std::istream &, Stringi &);
	friend std::ostream & operator<<(std::ostream &os, Stringi &ob) { return os << ob.str << std::endl; }
	~Stringi() { free(this->str); }
};
void get(char *&);