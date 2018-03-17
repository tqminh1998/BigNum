#pragma once
#include <iostream>
#include <string>
#include <utility>

// split floating number
pair <string, string> split_float_num(string input){
    pair <string, string> res;
    res.first = input.substr(0, input.find('.'));
    res.second = "0." + input.substr(input.find('.'));
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

bool isZero(string s)
{
    for (int i = 0; i < s.size(); i++){
        if (s[i] != '0')
            return false;
    }
    return true;
}

