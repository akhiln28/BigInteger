#include "BasicArithmatic.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string str1,str2;
    cin >> str1 >> str2;
    BigInteger obj1(str1),obj2(str2);
    cout << obj1 - obj2 << endl;
    return 0;
}