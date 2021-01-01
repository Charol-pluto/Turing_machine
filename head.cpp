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

//todo:完善文件读写函数

void TuringMachine::file_load(string filename) {
    this->filename = filename;
    string str;
    char c[MAXLENTH];
    int n=0;
    memset(c,'\0',MAXLENTH);//初始化临时字符数组
    const char *split = ", ( ) ";
    fstream file(filename,ios::in);
    for (int i = 0; i <6 ; ++i) {//读入开头6行数据
        file.getline(c,MAXLENTH);
        str = c;
        this->init_print_start(str,i+1);
    }

    memset(c,'\0',MAXLENTH);//初始化临时字符数组
    init_Operation();//初始化当前操作结构体
    push_OP();//将当前操作结构体推入ID队列

    while (!file.eof()){
        //todo:标记一下这里可能会读入换行符
        file.getline(c,MAXLENTH);
        str = c;
        //投入存放字符串规则
        this->Rule_list.push_back(str);

        //读取字符串规则
        char *p2 = strtok(c,split);//获取第一个字符串1
        str = p2;
        Rule[n].pre_c_condition = str;
        p2 = strtok(NULL,split);//指针移动2
        str = p2;
        Rule[n].pre_c = str;
        p2 = strtok(NULL,split);//指针移动3
        str = p2;
        Rule[n].cur_c_condition = str;
        p2 = strtok(NULL,split);//指针移动4
        str = p2;
        Rule[n].cur_c = str;
        p2 = strtok(NULL,split);//指针移动5
        str = p2;
        Rule[n].op = operator_RLS(str);
        n++;
    }
    this->set_num_Rule(n+1);//存入规则的数量

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
    this->Operation.ptr = 1;//读头指向第一个位置

}
//todo:标记一下，使用了std::move
void TuringMachine::in_Operation(string str,string state,int ptr){
    this->Operation.str = std::move(str);
    this->Operation.state = std::move(state);
    this->Operation.ptr = ptr;
}

void TuringMachine::push_OP() {
    OP swap;
    swap.str = this->Operation.str;
    swap.ptr = this->Operation.ptr;
    swap.state = this->Operation.state;
    this->ID.push(swap);
}

void TuringMachine::read_string(string str) {
    this->Operation.str = BLANK + str + BLANK;
}


bool TuringMachine::Is_rule(R_node rule) {
    return this->Operation.state == rule.cur_c_condition && cur_char() == rule.cur_c;
}

string TuringMachine::cur_char() const {
    int n = Operation.ptr;
    string str = Operation.str.substr(n,1);
    return str;
}

bool TuringMachine::Is_Turing() {
    int i = 0;
    while (Operation.state != printStart.Final_state){
        for (i = 0; i <this->get_num_Rule() ; ++i) {
            if (this->Is_rule(Rule[i])){
                this->Operation.state = Rule[i].cur_c_condition;
                string substr = Rule[i].cur_c;
                this->Operation.str = this->Operation.str.replace(this->Operation.ptr, 1, substr, 0, 1);
                this->Operation.ptr = this->Operation.ptr + Rule[i].op;

                this->push_OP();//推入ID队列
                break;
            }else{
                continue;
            }
        }
        if (i == get_num_Rule()){
            return false;
        }
        i=0;
    }
    return true;
}





