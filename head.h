//
// Created by charol on 2020/12/29.
//

#ifndef TURING_MACHINE_HEAD_H
#define TURING_MACHINE_HEAD_H
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <sstream>
#define R +1
#define L -1
#define S 0
#define MAXNUM 100

using namespace std;
typedef struct R_node{
    int pre_i_condition;//标记状态值，0，1，2，。。。
    char pre_c_condition[5];
    char pre_c;//当前指向字符
    int cur_i_condition;//标记状态值，0，1，2，。。。
    char cur_c_condition[5];
    char cur_c;//操作后字符
    int op;//操作符，R，L，S；
    struct R_node * next;
}R_node,*R_list;

int i_char2int(string c);//字符转数字
string c_int2char(int a);//数字转字符


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
#endif //TURING_MACHINE_HEAD_H
