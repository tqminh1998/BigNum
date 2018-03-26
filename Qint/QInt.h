#ifndef QINT_H
#define QINT_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Qint{
private:
	int m_data[4];
public:
	int getBit(int pos);
	void setBit(int pos,int bit);
	Qint();
	Qint(const Qint& num);
	Qint(int, int, int, int);
	//~Qint();
	Qint& operator =(const Qint& b);
	Qint(string binArr);
	string binArr();

	Qint operator & (const Qint& b);
	Qint operator | (const Qint& b);
	friend Qint operator ~ (const Qint& b);//1 ngoi
	friend Qint operator - (const Qint& b); // 1 ngoi
	Qint operator ^ (const Qint& b);

	Qint operator + (Qint& b);
	Qint operator - (const Qint& b);
	Qint operator * (/*const*/ Qint& M);
	Qint operator / (/*const*/ Qint& M);

	
	//dich trai 1 bit
	Qint leftShift();
	//dich phai 1 bit
	Qint rightShift();
	Qint operator >> (unsigned int x);
	Qint operator << (unsigned int x);

	//nhap & convert
	void scan(string str, int base);
	string print(int base);
};

#endif