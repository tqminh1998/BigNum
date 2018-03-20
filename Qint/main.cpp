#include<iostream>
#include <fstream>
#include "Qint.h"
#include "function.h"

int main(int argc,char* argv[]){
	//Qint a("0111");
	//Qint b("0011");
	//cout << a.binArr() << endl;
	//a.setBit(127, 0);
	//cout << a.binArr() << endl;
	//a.leftShift();
	//a.rightShift();
	//cout << a.binArr() << endl;

	//cout << a.getBit(127)<<endl;
	//cout << b.getBit(st125) << endl;
	//cout << b.binArr() << endl;
	
	/*Qint a, b;
	a.scan("32147432648", 10);
	b.scan("32147432648", 10);
	Qint c = a * b;
	c.print(10);
	cout << endl;
	a.print(2);
	cout << endl;*/
	cout << argv[1] << " " << argv[2] << endl;
	fstream fi,fo;
	fi.open(argv[1], ios::in);
	fo.open(argv[2], ios::out);
	if (!fi.is_open()) cout << "Unable to open\n";
	else{
		while (!fi.eof()){
			string tmp = "";
			getline(fi, tmp);
			string res = readLine(tmp);
			fo << res << endl;
		}
	}
	fi.close();
	fo.close();
	


	return 0;
}
