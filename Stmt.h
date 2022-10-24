#ifndef STMT_H_
#define STMT_H_

#include "opcodes.h"

class Stmt {
private:
    int opcode;

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

class Pushscal : public Stmt {
    protected:
        int Opcode = OP_PUSHSCALAR;
        int *value;
    public:
        void serialize();
};

class Pusharr : public Stmt {
    protected:
        int Opcode = OP_PUSHARRAY;
        int *array;
    public:
        void serialize();
};

class Pushi : public Stmt {
    public:
        int Opcode = OP_PUSHI;
        int value;
        void serialize();
};

class Pop : public Stmt {
    protected:
        int Opcode = OP_POP;
    public:
        void serialize();
};

class Popscal : public Stmt {
    protected:
        int Opcode = OP_POPSCALAR;
        int *index;
    public:
        void serialize();
};

class Poparr : public Stmt {
    protected:
        int Opcode = OP_POPARRAY;
        int *index;
    public:
        void serialize();
};

class Dup : public Stmt {
    protected:
        int Opcode = OP_DUP;
    public:
        void serialize();
};

class Swap : public Stmt {
    protected:
        int Opcode = OP_SWAP;
    public:
        void serialize();
};

class Add : public Stmt {
    protected:
        int Opcode = OP_ADD;
    public:
        void serialize();
};

class Negate : public Stmt {
    protected:
        int Opcode = OP_NEGATE;
    public
        void serialize();
};

class Mul : public Stmt {
    public:
        void serialize();

    protected:
        int Opcode = OP_MUL;
};

class Div : public Stmt {
    protected:
        int Opcode = OP_DIV;
    public:
        void serialize();
};


class Printtos : public Stmt {
    protected:
        int Opcode = OP_PRINTTOS;
    public:
        void serialize();
};

class Prints : public Stmt {
    protected:
        Prints(std::string *str);
        int OpCode = OP_PRINTS;
        std::string *string_buffer = nullptr;
    public:
        void serialize();
};

#endif /* STMT_H_ */

#endif /* STMT_H_ */
