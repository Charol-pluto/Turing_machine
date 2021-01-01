
#include "head.h"
using namespace std;


int main() {
    TuringMachine turingMachine;
    turingMachine.file_load(_1to2);
    if (turingMachine.Is_Turing()){
        cout << "Yes" << endl;
    }else{
        cout << "NO" << endl;
    }
    printf("\n\n\n\n");
    turingMachine.printDATA();
    if (turingMachine.Is_Turing()){
        cout << "Yes" << endl;
    }else{
        cout << "NO" << endl;
    }
//    cout << "Hello World!" << endl;
    return 0;
}
