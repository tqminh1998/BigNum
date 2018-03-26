#include<iostream>
#include <fstream>
#include "Qint.h"
#include "function.h"

int main(int argc,char* argv[]){
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
