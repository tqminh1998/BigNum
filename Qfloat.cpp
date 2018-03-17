#include "Qfloat.h"

void setBit(int pos, int value)
{
    m_data[pos / 32] = value << (127 - pos);
}

void ScanQfloat(string input)
{
	pair <string, string> pss = split_float_num(input);
    string part1 = pss.first;
    string part2 = pss.second;
    
    // set sign
    if (part[1] = '-')
    {
        setBit(0, 1);
        part1 = part1.substr(1);
    }
    else
        setBit(0, 0);
    
    int cur_pos = 1; // pos 0 is sign bit
    
    // set num
    /*
    pair <string, int> psi;
    while (isZero(part1))
    {
        psi = div2(part1);
        setBit(cur_pos, psi.second);
        part1 = psi.first;
    }
    */
    
}
