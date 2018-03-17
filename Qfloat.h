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
};


