#include "tools.h"

// split floating number
pair <string, string> split_float_num(string input){
    pair <string, string> res;
    
    int k = input.find('.');
    
    if (k == -1){
        res.first = input;
        res.second = "0";
    }
    else{
        res.first = input.substr(0, input.find('.'));
        res.second = "0" + input.substr(input.find('.')+1);
    }
    return res;
}

// string div and mod 2
pair <string, int> div2(string num){
    string quotient = "";
    int val = num[0] - '0';
        
    for (int i = 0; i < num.size(); i++){
        quotient += (val / 2 + '0');
        if (i + 1 < num.size())
            val = (val % 2)*10 + (num[i+1] - '0');  
    }
    
    pair<string, int> res;
    res.first = quotient;
    res.second = ((num[num.size() - 1] - '0') % 2) ? 1 : 0;
    
    return res;
}

// string num equal to zero
bool isZero(string s)
{
    for (int i = 0; i < s.size(); i++){
        if (s[i] != '0')
            return false;
    }
    return true;
}

// string mul 2
string mul2(string num)
{
    int sz = num.size();
    int val = 0, mem = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        val = num[i] - '0';
        num[i] = (val*2 + mem) % 10 + '0';
        mem = (val * 2 + mem) / 10;
    }
    
    return num;
}

// get bit of part before dot
vector<int> getBitPart1(string part1)
{
   stack <int> st;
   pair <string, int> psi;
   
   while (!isZero(part1))
   {
        psi = div2(part1);
        st.push(psi.second);
        part1 = psi.first;
   }
   vector <int> res;
   while (st.empty() == false)
   {
        res.push_back(st.top());
        st.pop();
   }
   
   return res;
}

// get bit of part after dot
vector <int> getBitPart2(string part2)
{
    vector <int> res;
    int max_bit = 0;
    while (!isZero(part2) && max_bit < 112)
    {
        part2 = mul2(part2);
        res.push_back(part2[0] - '0');
        if (part2[0] == '1')
        {
            part2[0] ='0';
        }
        max_bit++;
    }
    
    return res;
}

// count exponent
int countExponent(vector<int> bitPart1,vector <int> bitPart2)
{
    int dot_pos = bitPart1.size();
    int exp = 0;
    for (int i = 0; i < bitPart1.size(); i++)
        if (bitPart1[i] == 1)
        {
            exp = dot_pos - i - 1;
            return exp;
        }
    
    for (int i = 0; i < bitPart2.size(); i++)
        if (bitPart2[i] == 1)
        {
            exp = -(i+1);
            break;
        }
    return exp;
}

//convert bias
vector <int> cvBias(int a)
{
    vector <int> bit;
    if (a <= 0){
        
        a = -a;
        stringstream ss;
        ss << a;
        
        string str_a;
        ss >> str_a;
        bit = getBitPart1(str_a);
        
        for (int i = bit.size() - 1; i>=0 ; i--){
            if (bit[i] == 1)
                bit[i] = 0;
            else bit[i] = 1;
        }
        
        int tmp = 14 - bit.size();
        for (int i = 1; i <= tmp; i++)
            bit.insert(bit.begin(), 1);
        bit.insert(bit.begin(), 0);
    }
    else{
        a = a-1; // because 100000000000..00
        
        stringstream ss;
        ss << a;
        
        string str_a;
        ss >> str_a;
        bit = getBitPart1(str_a);
        
        for (int i = bit.size() - 1; i>=0 ; i--){
            if (bit[i] == 1)
                bit[i] = 1;
            else bit[i] = 0;
        }
        int tmp =14 - bit.size();
        for (int
                i = 1; i <= tmp; i++)
            bit.insert(bit.begin(), 0);
        bit.insert(bit.begin(), 1);
    }
    
    return bit;
}
//xác định xem 1 đoạn bit cụ thể có tất cả các bit đều giống nhau hay ko
bool isAllBit(vector<int> bit, int val, int s, int e){
    for (int i = s; i <= e; i++){
        if (bit[i] != val)
            return false;
    }
    return true;
}
//phân loại số chấm động
//0: số zero
//1: dạng chuẩn
//2: dạng không chuẩn
//3: Inf
//4: số báo lỗi
int Classification(vector <int> bit)
{   
    if (!isAllBit(bit,0,1,15) && !isAllBit(bit,1,1,15))
        return 1;
    
    if (isAllBit(bit,0,1,127))
        return 0;
    
    if (isAllBit(bit,0,1,15) && !isAllBit(bit,0,16,127))
        return 2;
    
    if (isAllBit(bit,1,1,15) && isAllBit(bit,0,16,127))
        return 3;
    
    return 4;
}

// chuyển từ bit sang số (bias)
int cvBiasToNum(vector <int> exp_bit)
{
    int res = 0;
    bool positve = false;
    if (exp_bit[0] == 0){
        for (int i = 1; i < exp_bit.size(); i++){
            if (exp_bit[i] == 1)
                exp_bit[i] = 0;
            else 
                exp_bit[i] = 1;
        }  
    }
    else{
        exp_bit[0] = 0;
        positve = true;
    }
    
    for (int i = 0; i < exp_bit.size(); i++){
        res += exp_bit[i]*pow(2,14 - i);
    }
    if (positve) res++;
    return res;
}
