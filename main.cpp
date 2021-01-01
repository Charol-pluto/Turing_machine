
#include "head.h"
using namespace std;


int main() {
    TuringMachine turingMachine;
    turingMachine.file_load(_0n1n);
    if (turingMachine.Is_Turing()){
        cout << "Yes" << endl;
    }else{
        cout << "NO" << endl;
    }
//    cout << "Hello World!" << endl;
    return 0;
}
