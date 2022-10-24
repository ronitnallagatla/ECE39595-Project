#ifndef STMT_H_
#define STMT_H_

#include "opcodes.h"

class Stmt {
protected:
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
    Label(std::string label);
    void serialize();
};

class Gosublabel : public Stmt {
public:
    Gosublabel(std::string label);
    void serialize();
};

class Start : public Stmt {
public:
    Start();
    void serialize();
};

class End : public Stmt {
public:
    End();
    void serialize();
};

class Exit : public Stmt {
public:
    Exit();
    void serialize();
};

class Jump : public Stmt {
public:
    Jump(std::string label);
    void serialize();
};

class Jumpzero : public Stmt {
public:
    Jumpzero(std::string label);
    void serialize();
};

class Jumpnzero : public Stmt {
public:
    Jumpnzero(std::string label);
    void serialize();
};

class Gosub : public Stmt {
public:
    Gosub(std::string label);
    void serialize();
};

class Return : public Stmt {
public:
    Return();
    void serialize();
};

class Pushscal : public Stmt {
protected:
    int opcode = OP_PUSHSCALAR;
    // int* value;

public:
    Pushscal(std::string var);
    void serialize();
};

class Pusharr : public Stmt {
protected:
    int opcode = OP_PUSHARRAY;
    // int* array;

public:
    Pusharr(std::string var);
    void serialize();
};

class Pushi : public Stmt {
protected:
    int opcode = OP_PUSHI;
    // int value;
public:
    Pushi(int val);
    void serialize();
};

class Pop : public Stmt {
protected:
    int opcode = OP_POP;

public:
    Pop();
    void serialize();
};

class Popscal : public Stmt {
protected:
    int opcode = OP_POPSCALAR;
    // int* index;

public:
    Popscal(std::string var);
    void serialize();
};

class Poparr : public Stmt {
protected:
    int opcode = OP_POPARRAY;
    // int* index;

public:
    Poparr(std::string var);
    void serialize();
};

class Dup : public Stmt {
protected:
    int opcode = OP_DUP;

public:
    Dup();
    void serialize();
};

class Swap : public Stmt {
protected:
    int opcode = OP_SWAP;

public:
    Swap();
    void serialize();
};

class Add : public Stmt {
protected:
    int opcode = OP_ADD;

public:
    Add();
    void serialize();
};

class Negate : public Stmt {
protected:
    int opcode = OP_NEGATE;

public:
    Negate();
    void serialize();
};

class Mul : public Stmt {
public:
    void serialize();

protected:
    Mul();
    int opcode = OP_MUL;
};

class Div : public Stmt {
protected:
    int opcode = OP_DIV;

public:
    Div();
    void serialize();
};

class Printtos : public Stmt {
protected:
    int opcode = OP_PRINTTOS;

public:
    Printtos();
    void serialize();
};

class Prints : public Stmt {
protected:
    Prints(std::string* str);
    int opcode = OP_PRINTS;
    std::string* string_buffer = nullptr;

public:
    void serialize();
};

#endif /* STMT_H_ */
