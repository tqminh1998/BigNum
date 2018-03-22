#include <iostream>
#include <cstring>
#include "tools.h"
#include "Qfloat.h"
using namespace std;

int main() {
    //string s;
    //cin >> s;
    
   // vector<int> ss;
    // ss = cvBias(-5);
   // for (int i = 0; i < ss.size(); i++) cout << ss[i];
    string input;
    cin >> input;
    Qfloat f;
    f.ScanQfloat(input);
	return 0;
}
