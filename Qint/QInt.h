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
	//Constructor với đối số là dãy bit
	Qint(string binArr);
	//trả về chuỗi bit của số Qint
	string binArr();
	//toán tử and
	Qint operator & (const Qint& b);
	//toán tử or
	Qint operator | (const Qint& b);
	//toán tử not
	friend Qint operator ~ (const Qint& b);//1 ngoi
	//toán tử lấy số đối (1 ngôi)
	friend Qint operator - ( Qint b); // 1 ngoi
	Qint operator ^ (const Qint& b);

	//toán tử +,-,*,/ 2 số Qint
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

	//lấy trị tuyệt đối Qint
	Qint abs(Qint a);
};

#endif