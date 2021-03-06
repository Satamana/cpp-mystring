#include "stdafx.h"
#include "Stringi.h"
Stringi::Stringi(char *s)
{
	this->size = strlen(s) + 1;
	this->str = (char*)malloc(this->size);
	strcpy_s(this->str, this->size, s);
}
Stringi::Stringi(const Stringi &copy)
{
	this->size = copy.size;
	this->str = (char*)malloc(this->size);
	strcpy_s(this->str, this->size, copy.str);
}
Stringi::Stringi(Stringi &&move)
{
	this->size = move.size;
	this->str = move.str;
	move.size = 0;
	move.str = nullptr;
}
Stringi & Stringi::operator=(const Stringi &ob)
{
	if (this->str) free(this->str);
	this->size = ob.size;
	this->str = (char*)malloc(this->size);
	strcpy_s(this->str, this->size, ob.str);
	return *this;
}
Stringi Stringi::operator*(const Stringi &ob)
{
	Stringi tmp;
	size_t lenthis = strlen(this->str);
	size_t lenob = strlen(ob.str);
	for (size_t i = 0; i < lenthis; i++)
	{
		for (size_t j = 0; j < lenob; j++)
		{
			if (this->str[i] == ob.str[j] && ((tmp.str == nullptr)? 1 : strchr(tmp.str, this->str[i]) == nullptr))
			{
				tmp.str = (char*)realloc(tmp.str, tmp.size + 1);
				tmp.str[tmp.size++] = this->str[i];
			}
		}
	}
	tmp.str = (char*)realloc(tmp.str, tmp.size + 1);
	tmp.str[tmp.size++] = 0;
	return tmp;
}
int Stringi::operator()(char s)
{
	if (strchr(this->str, s)) return (strchr(this->str, s) - this->str);
	return -1;
}
std::istream & operator>>(std::istream &os, Stringi &ob)
{
	if (ob.str) free(ob.str);
	get(ob.str);
	ob.size = strlen(ob.str) + 1;
	return os;
}
void get(char *&s)
{
	s = nullptr;
	size_t n = 0;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		s = (char*)realloc(s, n + 1);
		s[n++] = ch;
	}
	s = (char*)realloc(s, n + 1);
	s[n] = 0;
}