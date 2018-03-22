#include "Qfloat.h"

void Qfloat::setBit(int pos, int value)
{
    m_data[pos / 32] = value << (127 - pos);
}

void Qfloat::setSign(string &part1, int &cur_pos)
{
    if (part1[0] == '-')
    {
        setBit(cur_pos, 1);
        part1 = part1.substr(1);
    }
    else
        setBit(cur_pos, 0);
    
    cur_pos++;
}

void Qfloat::setExp(vector <int> exp_bit, int &cur_pos)
{
    for (int i = 0; i < exp_bit.size(); i++){
        setBit(cur_pos, exp_bit[i]);
        cur_pos++;
    }
}

void Qfloat::setFraction(vector<int> fraction, int &cur_pos)
{
    for (int i = 0; i < fraction.size(); i++){
        setBit(cur_pos, fraction[i]);
        cur_pos++;
    }
}

void Qfloat::ScanQfloat(string input)
{
    pair <string, string> pss = split_float_num(input);
    string part1 = pss.first;
    string part2 = pss.second; 
    
    int cur_pos = 0;
    // set sign
    setSign(part1, cur_pos);
    
    // count exponent
   
    vector <int> bitPart1 = getBitPart1(part1);  
    vector <int> bitPart2 = getBitPart2(part2);
    vector <int> fraction = bitPart1;
    
    fraction.insert( fraction.end(), bitPart2.begin(), bitPart2.end());
    
    //for (int i = 0 ; i < fraction.size(); i++){
      //  cout << fraction[i];
    //}
    //cout << endl;
    
    int exp = countExponent(bitPart1, bitPart2); 
    
    cout << exp << endl;
    vector <int> exp_bit = cvBias(exp);
    
    //for (int i = 0; i < exp_bit.size(); i++)
      //  cout << exp_bit[i];
    //cout << endl;
    
    setExp(exp_bit, cur_pos);
    
    //update fraction
    
    for (int i = 0; i < fraction.size(); i++){
        if (fraction[i] == 1){
            if (i >= 0)
                fraction.erase(fraction.begin(), fraction.begin() + i + 1);
            
            break;
        }
    }
    
    int tmp = fraction.size();
    for (int i = 1; i <= 112 - tmp; i++){
        fraction.push_back(0);
    }
    if (fraction.size() > 112){
        fraction.erase(fraction.begin()+112, fraction.end());
    } 
    
    for (int i = 0 ; i < fraction.size(); i++){
        cout << fraction[i];
    }
    cout << endl;
    cout << fraction.size(); 
    
    setFraction(fraction, cur_pos);
    
}
