#ifndef STMT_H_
#define STMT_H_

class Stmt {
private:
    int opcode;

public:
    virtual void serialize() = 0;
};

#endif /* STMT_H_ */
