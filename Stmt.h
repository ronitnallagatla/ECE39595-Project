#ifndef STMT_H_
#define STMT_H_

#include "opcodes.h"

class Stmt {
private:
    uint32_t opcode;

public:
    virtual void serialize() = 0;
};

// class Declscal : public Stmt {
// public:
//     void serialize();
// };

// class Declarr : public Stmt {
// public:
//     void serialize();
// };

class Label : public Stmt {
public:
    void serialize();
};

class Gosublabel : public Stmt {

public:
    void serialize();
};

#endif /* STMT_H_ */
