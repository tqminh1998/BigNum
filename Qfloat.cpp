#include "Qfloat.h"

void Qfloat::setBit(int pos, int bit)
{
	int bitpos = this->getBit(pos);
	int data_i = pos / 32;
	pos = pos % 32;
	if (bitpos == 1 && bit == 0){
		this->m_data[data_i] = this->m_data[data_i] - (1 << (31 - pos));
	}
	else{
		this->m_data[data_i] = this->m_data[data_i] | (bit << (31 - pos));
	}
}

int Qfloat::getBit(int pos)
{
	int data_i = pos / 32;
	pos %= 32;
	int bit = (this->m_data[data_i] >> (31 - pos)) & 1;
	return bit;
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
    // case input equal 0
    if (input == "0" || input == "-0" || input == "+0")
    {
        int pos = 0;
        for (int i = 0; i < 128; i++){
            setBit(pos, 0); 
            pos++;
        }
        
        return ;
    }
    
    pair <string, string> pss = split_float_num(input);
    string part1 = pss.first;
    string part2 = pss.second; 
    
    //cout << part1 << " " << part2;
    
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

void Qfloat::PrintNormalize(vector <int> bit)
{
    vector <int> exp_bit;
    for (int i = 1; i <= 15; i++){
        exp_bit.push_back(bit[i]);
    }
    int exp = cvBiasToNum(exp_bit);
    
    vector<int> part1;
    vector<int> part2;
    if (exp < 0){
        part1.push_back(0);
        for (int i = 1; i <= abs(exp)-1; i++)
            part2.push_back(0);
        part2.push_back(1);
        for (int i = 16; i < 128; ++i)
            part2.push_back(bit[i]);
    }
    else{
        part1.push_back(1);
        for (int i = 16; i < 16 + exp; i++)
            part1.push_back(bit[i]);
        for (int i = 16+exp; i < 128; i++)
            part2.push_back(bit[i]);
    }
    
   
    
}

void Qfloat::PrintQfloat()
{
    vector <int> bit;
    for (int i = 0; i < 128; i++){
        bit.push_back(getBit(i));
    }
    
    int type = Classification(bit);
    
    switch (type){
        case 0: 
            cout << "0";
            break;
        case 1:
            break;
            
    }
}
