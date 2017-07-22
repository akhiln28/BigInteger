//
// Created by akhil on 21/7/17.
//

#include "expression_evaluation.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//pref function for operators as string
int pref(string c){
    if(c == "-" || c == "+")
        return 1;
    if(c == "*" || c == "/")
        return 2;
    if(c == "**" || c == "!")
        return 3;
    if(c == "(")
        return -1;
    else return 0;
}
//to check for a valid number
bool isnumber(string str)
{
    if(str[0] >= '0' && str[0] <= '9')
        return true;
    else if(str[0] == '-' && str[1] >= '0' && str[1] <= '9')
        return true;
    else return false;
}
vector<string> postfix(vector<string> infix)
{
    stack<string> st;
    vector<string> postfix;
    for(int i = 0;i < infix.size(); i++)
    {
        //if it is number just add it to the postfix
        if(isnumber(infix[i]))
        {
            cout << infix[i] << endl;
            postfix.push_back(infix[i]);
        }
            //if it is a open bracked or the stack is empty push it to stack
        else if(infix[i] == "(" || st.empty()) st.push(infix[i]);
        else if(pref(infix[i]) || infix[i] == ")")
        {
            //if it is closing bracket then pop the top and append to the postfix until you find the open bracket, then remove it.
            if(infix[i] == ")")
            {
                while(st.top() != "(")
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
                //if pref of adding element is greater than the top then push it to the stack
            else if(pref(infix[i]) > pref(st.top()))
            {
                st.push(infix[i]);
            }
            else
            {
                postfix.push_back(st.top());st.pop();
                st.push(infix[i]);
            }
        }
    }
    while(!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}
















































