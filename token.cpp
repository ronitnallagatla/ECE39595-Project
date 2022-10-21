#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <cstring> 
#include "Instruction.h"

using namespace std;

class token {
    public:
        int i = 0;
        string op1 = "/0";
        string op2 = "/0";
        string op3 = "/0";
        string op4 = "/0";
        string op5 = "/0";

        void set_op (char* s) {
            string str(s);
            i++;
            if (i == 1) {
                op1 = str;
            }

            else if (i == 2) {
                op2 = str;
            }

            else if (i == 3) {
                op3 = str;
            }

            else if (i == 4) {
                op4 = str;
            }

            else {
                op5 = str;
            }
        }
};

token tokenizer (string instruction) {
    char *ptr, *str;
    str = &instruction[0];
    ptr = strtok(str, " , ");

    token t;
    while (ptr != NULL)  
    {
        t.set_op(ptr);
        ptr = strtok (NULL, " , ");
    }

    return t;
}


/* Uncomment to test tokenizer
#include <iostream>
int main () {
    string st = "JumpZero, FIBL0, (18)";
    string st2 = "PushScalar A, (0)";
    string st3 = "Prints 2+6=";

    token t1 = tokenizer (st);
    
    cout << t1.op1 <<endl;
    cout << t1.op2 <<endl;
    cout << t1.op3 <<endl;
    cout << t1.op4 <<endl;
    cout << t1.op5 <<endl;

    token t1 = tokenizer (st2);
    
    cout << t1.op1 <<endl;
    cout << t1.op2 <<endl;
    cout << t1.op3 <<endl;
    cout << t1.op4 <<endl;
    cout << t1.op5 <<endl;

    token t1 = tokenizer (st3);
    
    cout << t1.op1 <<endl;
    cout << t1.op2 <<endl;
    cout << t1.op3 <<endl;
    cout << t1.op4 <<endl;
    cout << t1.op5 <<endl;
    return 0;
}
*/

#endif
