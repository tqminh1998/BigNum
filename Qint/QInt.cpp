#include "Qint.h"
#include "function.h"
#include <cstring>


int Qint::getBit(int pos){ //pos tinh tu l->r : 0->127
	int data_i = pos / 32;
	pos %= 32;
	int bit = (this->m_data[data_i] >> (31 - pos)) & 1;
	return bit;
}
void Qint::setBit(int pos, int bit){
	int bitpos = this->getBit(pos);
	int data_i = pos / 32;
	pos = pos % 32;
	if (bitpos == 1 && bit == 0){
		this->m_data[data_i] = this->m_data[data_i] - (1 << (31 - pos));
	}
	else{
		this->m_data[data_i] = this->m_data[data_i] | (bit << (31 - pos));
	}
	//or ma bit=1 thi no sẽ set đúng, còn bit=0 thì ko đổi.
}
Qint::Qint(){
	m_data[0] = m_data[1] = m_data[2] = m_data[3] = 0;
}
Qint::Qint(const Qint& b){
	for (int i = 0; i < 4; i++){
		this->m_data[i] = b.m_data[i];
	}
}
Qint::Qint(int x, int y, int z, int t){
	m_data[0] = x;
	m_data[1] = y;
	m_data[2] = z;
	m_data[3] = t;
}
//dua vao (*this) la default constructor
Qint& Qint:: operator =(const Qint& b){
	for (int i = 0; i < 4; i++)
		m_data[i] = b.m_data[i];
	return (*this);
}
Qint::Qint(string binArr){
	*this = Qint();
	int i = binArr.length() - 1;
	int j = 127;
	while (j >= 0 && i >= 0){
		this->setBit(j, binArr[i]-'0');
		j--;
		i--;
	}
}
string Qint::binArr(){
	string res = "";
	int i = 127;
	while (i >= 0){
		int bit = this->getBit(i);
		res.insert(res.begin(), bit + '0');
		i--;
	}
	int j = 0;
	while (res[j] == '0' && j<127){
		j++;
	}
	return res.substr(j);
}
//Cac thao tac tren bit, tan dung thao tac co san tren int
Qint Qint:: operator & (const Qint& b){
	Qint res(m_data[0] & b.m_data[0], m_data[1] & b.m_data[1], m_data[2] & b.m_data[2], m_data[3] & b.m_data[3]);
	return res;
}
Qint Qint:: operator | (const Qint& b){
	Qint res(m_data[0] | b.m_data[0], m_data[1] | b.m_data[1], m_data[2] | b.m_data[2], m_data[3] | b.m_data[3]);
	return res;
}
Qint operator ~ (const Qint& b){
	Qint res(~b.m_data[0], ~b.m_data[1], ~b.m_data[2],~b.m_data[3]);
	return res;
}
Qint Qint:: operator ^ (const Qint& b){
	Qint res(m_data[0] ^ b.m_data[0], m_data[1] ^ b.m_data[1], m_data[2] ^ b.m_data[2], m_data[3] ^ b.m_data[3]);
	return res;
}
Qint operator - (const Qint& b){
	Qint one(0, 0, 0, 1);
	return ~b + one;
}

Qint Qint::rightShift(){ //Qint>>1
	int bit31 = this->getBit(31);
	int bit63 = this->getBit(63);
	int bit95 = this->getBit(95);
	for (int i = 0; i < 4; i++){
		this->m_data[i] >>= 1;	
	}
	this->setBit(32, bit31);
	this->setBit(64, bit63);
	this->setBit(96, bit95);
	return (*this);
}
Qint Qint::leftShift(){ //Qint<<1
	int bit32 = this->getBit(32);
	int bit64 = this->getBit(64);
	int bit96 = this->getBit(96);
	for (int i = 0; i < 4; i++){
		this->m_data[i] <<= 1;
	}
	this->setBit(31, bit32);
	this->setBit(63, bit64);
	this->setBit(95, bit96);
	return (*this);
}
Qint Qint:: operator >> (unsigned int x){
	Qint res;
	while (x--){
		res = this->rightShift();
	}
	return res;
}
Qint Qint:: operator << (unsigned int x){
	Qint res;
	while (x--){
		res = this->leftShift();
	}
	return res;
}

Qint Qint:: operator + (Qint& b){
	Qint sum;
	int rem = 0;
	for (int i = 127; i >= 0; i--){
		int bitb = b.getBit(i);
		int tmp = this->getBit(i) + b.getBit(i) + rem; //sao const lai sai?
		int bit = tmp % 2;
		rem = tmp / 2;
		sum.setBit(i, bit);
	}
	return sum;
}


Qint Qint::operator - (const Qint& b){ //b>0
	return (*this) + (-b);
}

Qint Qint::  operator * (/*const*/ Qint& M){
	Qint A;
	int Q_1 = 0;
	Qint Q = (*this);
	int lastA, lastQ;
	int i = 128;
	//freopen("output.txt", "w", stdout);
	while (i--){
		lastQ = Q.getBit(127);
		if (lastQ > Q_1){
			A = A - M;
		}
		else if (lastQ < Q_1) { 
			A = A + M; 
		}
		//dich phai
		lastA = A.getBit(127);
		Q_1 = lastQ;
		Q.rightShift();
		Q.setBit(0, lastA); 

		A.rightShift();
		//cout << A.binArr() << endl << Q.binArr() << endl << Q_1 << endl;
	}
	return Q;
}

Qint Qint::operator /(/*const*/ Qint& M){
	Qint A;
	Qint Q = (*this);
	int dauQ = Q.getBit(0), dauM = Q.getBit(0);
	int firstQ;
	int i = 128;
	while (i--){
		firstQ = Q.getBit(0);
		A.leftShift();
		Q.leftShift();
		A.setBit(127, firstQ);
		A = A - M;
		if (A.m_data[0] < 0) {
			A = A + M;
			Q.setBit(127, 0);
		}
		else Q.setBit(127, 1);
	}
	if (dauM != dauQ) return -Q;
	return Q;
}
//nhap vao voi string la chuoi bat ki
void Qint::scan(string str, int base){
	switch (base){
	case 2:
		 *this=Qint(str);
		 break;
	case 10:{
				str = DecToBin(str);
				*this = Qint(str);
				break;
		}
	case 16:{
				str = HexToBin(str);
				*this = Qint(str);
				break;
		}
	}
}
string Qint::print(int base){
	string res = "";
	switch (base){
	case 2:
		res=this->binArr();
		break;
	case 10: {
				 res = BinToDec(this->binArr());
				 break;
		}
	case 16:{
				res = BinToHex(this->binArr());
				break;
		}
	}
	return res;
}