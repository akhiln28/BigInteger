//
// Created by akhil on 21/7/17.
//

#include "BasicArithmatic.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//This class is used for representing big integers

BigInteger :: BigInteger(string str1){
    str = str1;
}
//This is for default printing to the ostream
ostream &operator << (ostream &out,const BigInteger &obj){
    out << obj.str;
    return out;
}
//function that removes the stray zeroes(zeroes in the front)
string BigInteger :: removezeros(string str)
{
    if(str == "0") return "0";
    int i = 0;
    while(str[i] == '0')
    {
        i++;
    }
    str = str.substr(i,str.length() - i + 1);
    return str;
}
//we'll utilize this in + operator , it just adds two positive integers
string BigInteger :: add(const string &str1,const string &str2)
{
    int carry = 0,i = (int)str1.length() - 1,j = (int)str2.length() - 1;
    string res = "";
    while(i >= 0 && j >= 0)
    {
        int digit = carry + (str1[i]  - '0') + (str2[j] - '0');
        if(digit >= 10)
        {
            carry = digit/10;
            char ans = digit%10 + '0';
            res = ans + res;
        }
        else if(digit <= 9)
        {
            char ans = digit + '0';
            carry = 0;
            res = ans + res;
        }
        i--;
        j--;
    }
    while(i >= 0)
    {
        int digit = carry + str1[i] - '0';
        if(digit >= 10)
        {
            carry = digit/10;
            char ans = digit%10 + '0';
            res = ans + res;
        }
        else if(digit <= 9)
        {
            char ans = digit + '0';
            carry = 0;
            res = ans + res;
        }
        i--;
    }
    while(j >= 0)
    {
        int digit = carry + str2[j] - '0';
        if(digit >= 10)
        {
            carry = digit/10;
            char ans = digit%10 + '0';
            res = ans + res;
        }
        else if(digit <= 9)
        {
            char ans = digit + '0';
            carry = 0;
            res = ans + res;
        }
        j--;
    }
    //if carry is not vanished at the end
    if(carry != 0)
    {
        char ans = carry + '0';
        res = ans + res;
    }
    return res;
}
//for "-" operator , subtracts two positive integers
string BigInteger :: sub(const string &str1,const string &str2)
{
    if(str1 == str2)  return "0";
    string res;
    int i = str1.length() - 1,j = str2.length() - 1;
    int carry = 0;
    while(j >= 0 && i >= 0)
    {
        int digit = str1[i] - str2[j] + carry;
        if(digit >= 0)
        {
            char ans = digit + '0';
            res = ans + res;
            carry = 0;
        }
        else
        {
            char ans = digit + 10 + '0';
            carry = -1;
            res = ans + res;
        }
        i--;
        j--;
    }
    while(i >= 0)
    {
        int digit = str1[i] - '0' + carry;
        if(digit >= 0)
        {
            char ans = digit + '0';
            res = ans + res;
            carry = 0;
        }
        else
        {
            char ans = digit + 10 + '0';
            carry = -1;
            res = ans + res;
        }
        i--;
    }
    return removezeros(res);
}
string BigInteger :: operator+(BigInteger obj)
{
    string res;
    if(str[0] == '-' && obj.str[0] == '-')
    {
        //str1 and str2 are the positive parts of str and obj.str
        string str1 = str.substr(1,str.length());
        string str2 = obj.str.substr(1,obj.str.length());
        return "-" + add(str1,str2);
    }
    if(str[0] != '-' && obj.str[0] != '-')
    {
        return add(str,obj.str);
    }
    if(str[0] != '-' && obj.str[0] == '-')
    {
        //always subtract larger no. with smaller
        string str2 = obj.str.substr(1,obj.str.length());
        if(str.length() > str2.length())
        {
            return sub(str,str2);
        }
        else if(str.length() == str2.length())
        {
            if(str > str2) return sub(str,str2);
            else if(str == str2) return "0";
            else return "-" + sub(str2,str);
        }
        else return "-" + sub(str2,str);
    }

    if(str[0] == '-' && obj.str[0] != '-')
    {
        string str1 = str.substr(1,str.length());
        string str2 = obj.str;
        if(str2.length() > str1.length()) return removezeros(sub(str2,str1));
        else if(str2.length() == str1.length())
        {
            if(str2 > str1) return sub(obj.str,str1);
            else if(str2 == str1) return "0";
            else return "-" + sub(str1,obj.str);
        }
        else return "-" + sub(str1,obj.str);
    }
    return str;
}
string BigInteger :: operator-(BigInteger obj)
{
    if(str == obj.str)
    {
        return "0";
    }
    if(str[0] != '-' && obj.str[0] != '-')
    {
        if(str.length() > obj.str.length())
        {
            return sub(str,obj.str);
        }
        else if(str.length() == obj.str.length())
        {
            if(str > obj.str) return sub(str,obj.str);
            else return "-" + sub(obj.str,str);
        }
        else return "-" + sub(obj.str,str);
    }
    if(str[0] == '-' && obj.str[0] == '-')
    {
        string str1 = str.substr(1,str.length());
        string str2 = obj.str.substr(1,obj.str.length());
        if(str2.length() > str1.length()) return sub(str2,str1);
        else if(str2.length() == str1.length())
        {
            if(str2 > str1)  return sub(str2,str1);
            else return "-" + sub(str1,str2);
        }
        else return "-" + sub(str1,str2);
    }
    if(str[0] != '-' && obj.str[0] == '-')
    {
        string str1 = str;
        string str2 = obj.str.substr(1,obj.str.length());
        return add(str1,str2);
    }
    if(str[0] == '-' && obj.str[0] != '-')
    {
        string str1 = str.substr(1,str.length());
        string str2 = obj.str;
        return "-" + add(str1,str2);
    }
    return str;
}
