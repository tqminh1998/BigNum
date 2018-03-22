#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

// split floating number
pair <string, string> split_float_num(string input);

// string div and mod 2
pair <string, int> div2(string num);

// string num equal to zero
bool isZero(string s);

// string mul 2
string mul2(string num);

// get bit of part before dot
vector<int> getBitPart1(string part1);

// get bit of part after dot
vector <int> getBitPart2(string part2);

// count exponent
int countExponent(vector<int> bitPart1, vector<int> bitPart2);

// convert bias
vector< int> cvBias(int a);
