//
// Created by Charon on 2020/12/30.
//
#include "head.h"

#include <utility>
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
    string C_R ="R";
    string C_L = "L";
    string C_S = "S";
    if(c == C_R){
        return OP_R;
    }else if( c == C_L){
        return OP_L;
    }else if( c == C_S){
        return OP_S;
    }

}

//todo:完善文件读写函数
//todo::缺少对状态队列的初始化加入
void TuringMachine::file_load(string filename) {
    this->filename = filename;
    string str;
    char c[MAXLENTH];
    int n=0;
    const char *split = ", ( ) ";
    fstream file(filename,ios::in);
    for (int i = 0; i <6 ; ++i) {//读入开头6行数据
        file.getline(c,MAXLENTH);
        str = c;
        this->init_print_start(str,i+1);
    }

    init_Operation();

    while (!file.eof()){
        file.getline(c,MAXLENTH);
        str = c;
        char *p2 = strtok(c,split);
        p2 = strtok(NULL,split);


    }


    file.close();
}


void TuringMachine::init_print_start(string str, int i) {
    switch (i) {
        case 1:
            this->printStart.State_set = str;
            break;
        case 2:
            this->printStart.Char_set = str;
            break;
        case 3:
            this->printStart.Start_state = str;
            break;
        case 4:
            this->printStart.Final_state = str;
            break;
        case 5:
            this->printStart.Blank_sign = str;
            break;
        case 6:
            this->printStart.str = str;
            break;
        default:
            return;
    }
}

void TuringMachine::init_Operation(){
    string s = BLANK + this->printStart.str + BLANK;
    this->Operation.str = s;
    this->Operation.state = this->printStart.Start_state;
    this->Operation.ptr = 1;

}
//todo:标记一下，使用了std::move
void TuringMachine::in_Operation(string str,string state,int ptr){
    this->Operation.str = std::move(str);
    this->Operation.state = std::move(state);
    this->Operation.ptr = ptr;
}











