//
// Created by Charon on 2020/12/30.
//
#include "head.h"
//字符转数字
int i_char2int(string c){
    int a;
    stringstream ss;
    ss << c;
    ss >> a;
    ss.clear();
    return a;
}

//数字转字符
string c_int2char(int a){
    stringstream ss;
    ss << a;
    string s = ss.str();
    ss.clear();
    return s;
}

//操作字符转操作数字
int operator_RLS(string c){
    string _R ="R";
    string _L = "L";
    string _S = "S";
    if(c == _R){
        return OP_R;
    }else if( c == _L){
        return OP_L;
    }else if( c == _S){
        return OP_S;
    }

}