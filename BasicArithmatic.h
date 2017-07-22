//
// Created by akhil on 21/7/17.
//

#ifndef BIGINTEGER_BASICARITHMATIC_H
#define BIGINTEGER_BASICARITHMATIC_H
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class BigInteger{
public:
    string str;
    BigInteger(string str1);
    friend ostream &operator << (ostream &out,const BigInteger &obj);
    string removezeros(string str);
    string add(const string &str1,const string &str2);
    string sub(const string &str1,const string &str2);
    string operator+(BigInteger obj);
    string operator-(BigInteger obj);
};
#endif //BIGINTEGER_BASICARITHMATIC_H
