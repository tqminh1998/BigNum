#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <utility>
#include "tools.h"

class Qfloat{
private:
    int m_data[4];
public:
    void ScanQfloat(string input);
    void PrintQfloat();
    void setBit(int pos, int value);
    int getBit(int pos);
    void setExp(vector<int> exp_bit, int &cur_pos);
    void setFraction(vector<int> fraction, int &cur_pos);
    void setSign(string &part1, int &cur_pos);
    void PrintNormalize(vector <int> bit);
};


