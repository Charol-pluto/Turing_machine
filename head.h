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
#include <fstream>
#include <queue>
#define OP_R +1
#define OP_L -1
#define OP_S 0
#define BLANK "B"
#define MAXNUM 100
#define MAXLENTH 1000

//定义文件替换
#define _0n1n "UTM_0n1n.txt"
#define _1to2 "UTM_1to2.txt"
#define _log2n "UTM_log2n.txt"
#define _m_n "UTM_m-n.txt"
#define _wcw "UTM_wcw.txt"

using namespace std;

int i_char2int(string c);//字符转数字
string c_int2char(int a);//数字转字符
int operator_RLS(string c);//操作字符转操作数字

typedef struct print_start{//开始接受结构体
    string State_set;//状态集
    string Char_set;//字符集
    string Start_state;//开始状态
    string Final_state;//终止状态
    string Blank_sign;//空白符
    string str;//初始读入字符串
} print_start;

typedef struct R_node{//规则存储结构
//    int pre_i_condition;//标记状态值，0，1，2，。。。
    string pre_c_condition;
    string pre_c;//当前指向字符
//    int cur_i_condition;//标记状态值，0，1，2，。。。
    string cur_c_condition;
    string cur_c;//操作后字符
    int op;//操作符，R，L，S；
}R_node,*R_list;

typedef struct OP{//操作结构体
    string str;//字符串
    string state;//当前状态
    int ptr;//当前读头位置
}OP,*OP_list;


class TuringMachine{
public://成员变量
    //开始不变
    string filename;//文件名
    print_start printStart;//开始输出结构体

    //直接下标法取规则，遍历找规则。
    R_node Rule[MAXNUM];//规则存放
    vector<string>Rule_list;//存放字符串规则；
    int num_Rule;//存放规则的数量

    //过程中变
    OP Operation;//操作结构体
    queue<OP>ID;//存放所有过程状态



public://成员函数
    void file_load(string filename);//读取文件
    void read_string(const string& str);//读取自定字符串
    void init_print_start(string str,int i);//读入开始接受结构体
    void init_Operation();//初始化操作结构体
    void in_Operation(string str,string state,int ptr);//修改操作结构体
    void push_OP();//进入ID对列
    bool Is_Turing();//检查输入的字符串是否符合规则
    bool Is_rule(const R_node& rule) const;//判断当前是否符合这条规则
    string cur_char() const;//返回当前指向的字符串
    //封装函数
    int get_num_Rule() const{return num_Rule;}//获得规则的数量
    void set_num_Rule(int num_Rule){this->num_Rule = num_Rule;}//设置规则的数量
    //命令行调试
    void printDATA();//输出当前存储的文件名，开始输出结构体，规则存放，所有过程状态

};






//typedef struct print_node{//全局传输出结构
//    string str_print;//输出字符串
//    string state_print;//输出状态
//    int ptr_print;//当前读头位置
//} print_node,*print_list;
#endif //TURING_MACHINE_HEAD_H
