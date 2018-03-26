#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
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

//xác định xem 1 đoạn bit cụ thể có tất cả các bit giống nhay hay ko
bool isAllBit(vector <int> bit, int val, int s, int e);

// phân loại số chấm động
// 0: số zero
// 1: dạng chuẩn 
// 2: dạng không chuẩn
// 3: Inf
// 4: Số báo lỗi
int Classification(vector<int> bit);

// chuyển từ bit sang số (bias)
int cvBiasToNum(vector<int> exp_bit);
