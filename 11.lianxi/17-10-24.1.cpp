/*************************************************************************
	> File Name: 17-10-24.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 17时53分03秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

enum class BinaryOpt {
    PLUS,
    MINUS,
    MUTIL,
    DIVIDE,
    MAX
};

class BinaryExpr;
class NumberExpr;

class Expr {
//protected: 
//    Expr() {}
public :
    virtual ~Expr() = 0;
    
    class IVistor {
    public:
        virtual void Visit(BinaryExpr *) = 0;
        virtual void Visit(NumberExpr *) = 0;
    };
    virtual void Accept(IVistor *Visitor) = 0;
};
Expr::~Expr() {}

class BinaryExpr : public Expr{
public:
    BinaryExpr(Expr *first, BinaryOpt Op, Expr *second) : first(first), second(second), Op(Op){}
    virtual void Accept(IVistor *Visitor) override {
        Visitor->Visit(this);
    }
    shared_ptr<Expr> GetFirst() { return first; }
    shared_ptr<Expr> GetSecond() { return second; }
    BinaryOpt GetOp() { return Op; }
    virtual ~BinaryExpr() {};

private:
    shared_ptr<Expr> first;
    shared_ptr<Expr> second;
    BinaryOpt Op;
};

class NumberExpr : public Expr{
public:
    NumberExpr(int Value) : Value(Value) {}
    virtual void Accept(IVistor *Visitor) override{
        Visitor->Visit(this);
    }
    int GetValue() { return Value; }
    virtual ~NumberExpr() {};
private:
    int Value;
};

BinaryOpt CharToOpt(char ch) {
    switch (ch) {
        case '+' :
            return BinaryOpt::PLUS;
        case '-' :
            return BinaryOpt::MINUS;
        case '*' :
            return BinaryOpt::MUTIL;
        case '/' :
            return BinaryOpt::DIVIDE;
    }
    return BinaryOpt::MAX;
}

Expr *__Parser(const char *&Read) {
    if (Read[0] == '(') {
        Read++;
        BinaryOpt Op = CharToOpt(Read[0]);
        Read++;
        while (Read[0] == ' ') Read++;
        Expr *first = __Parser(Read);
        while (Read[0] == ' ') Read++;
        Expr *second = __Parser(Read);
        Read++;
        return new BinaryExpr(first, Op, second);
    } else {
        int num = 0;
        while (Read[0] != ' ' && Read[0] != ')') {
            num = num * 10 + (Read[0] - '0');
            Read++;
        }
        return new NumberExpr(num);
    }
}

Expr *Parser(const char *Read) {
    return __Parser(Read);
}

class CalcNumber : public Expr::IVistor {
public :
    int result;
    virtual void Visit(BinaryExpr *node) {
        CalcNumber firstV,secondV;
        node->GetFirst()->Accept(&firstV);
        node->GetSecond()->Accept(&secondV);
        switch (node->GetOp()) {
            case BinaryOpt::PLUS :
                this->result = firstV.result + secondV.result;
                break;
            case BinaryOpt::MINUS :
                this->result = firstV.result - secondV.result;
                break;
            case BinaryOpt::MUTIL :
                this->result = firstV.result * secondV.result;
                break;
            case BinaryOpt::DIVIDE :
                this->result = firstV.result / secondV.result;
                break;
        }
    }

    virtual void Visit(NumberExpr *node) {
        this->result = node->GetValue();
    }
};

class CalcStr : public Expr::IVistor {
public:
    string str;
    int level;
    virtual void Visit(BinaryExpr *node) {
        CalcStr firstV,secondV;
        node->GetFirst()->Accept(&firstV);
        node->GetSecond()->Accept(&secondV);
        switch (node->GetOp()) {
            case BinaryOpt::PLUS :
                this->level = 2;
                this->str = firstV.str + "+" + secondV.str;
                break;
            case BinaryOpt::MINUS :
                this->level = 2;
                if (this->level == secondV.level) {
                    secondV.str = "(" + secondV.str + ")";
                }
                this->str = firstV.str + "-" + secondV.str;
                    
                break;
            case BinaryOpt::MUTIL :
                this->level = 1;
                if (this->level < secondV.level) {
                    secondV.str = "(" + secondV.str + ")";
                }
                if (this->level < firstV.level) {
                    firstV.str = "(" + firstV.str + ")";
                }
                this->str = firstV.str + "*" + secondV.str;
                break;
            case BinaryOpt::DIVIDE :
                this->level = 1;
                if (this->level <= secondV.level) {
                    secondV.str = "(" + secondV.str + ")";
                }
                if (this->level < firstV.level) {
                    firstV.str = "(" + firstV.str + ")";
                }
                this->str = firstV.str + "/" + secondV.str;
                break;
        }
    }

    virtual void Visit(NumberExpr *node) {
        int num = node->GetValue();
        do {
            this->str = static_cast<char>(num % 10 + '0') + this->str;
            num /= 10;
        } while (num);
        this->level = 0;
    }

};


class CalcSet : public Expr::IVistor {
public:
    string str;
    int level;
    virtual void Visit(BinaryExpr *node) {
        CalcSet firstV,secondV;
        node->GetFirst()->Accept(&firstV);
        node->GetSecond()->Accept(&secondV);
        switch (node->GetOp()) {
            case BinaryOpt::PLUS :
                this->level = 4;
                this->str = firstV.str + "加" + secondV.str;
                break;
            case BinaryOpt::MINUS :
                this->level = 3;
                if (this->level <= secondV.level) {
                    if (secondV.level == 4) {
                        secondV.str = " " + secondV.str + "的和 ";
                    } else {
                        secondV.str = " " + secondV.str + "的差 ";
                    }
                }
                this->str = firstV.str + "减" + secondV.str;
                    
                break;
            case BinaryOpt::MUTIL :
                this->level = 2;
                if (this->level < secondV.level) {
                    if (secondV.level == 4) {
                        secondV.str = " " + secondV.str + "的和 ";
                    } else {
                        secondV.str = " " + secondV.str + "的差 ";
                    }
                }
                if (this->level < firstV.level) {
                    if (firstV.level == 4) {
                        firstV.str = firstV.str + "的和 ";
                    } else {
                        firstV.str = firstV.str + "的差 ";
                    }
                }
                this->str = firstV.str + "乘" + secondV.str;
                break;
            case BinaryOpt::DIVIDE :
                this->level = 1;
                if (this->level <= secondV.level) {
                    if (secondV.level == 4) {
                        secondV.str = " " + secondV.str + "的和 ";
                    } else if (secondV.level == 3) {
                        secondV.str = " " + secondV.str + "的差 ";
                    } else if (secondV.level == 2) {
                        secondV.str = " " + secondV.str + "的积 ";
                    } else {
                        secondV.str = " " + secondV.str + "的商 ";
                    }
                }
                if (this->level <= firstV.level) {
                    if (firstV.level == 4) {
                        firstV.str = firstV.str + "的和 ";
                    } else if (firstV.level == 3) {
                        firstV.str = firstV.str + "的差 ";
                    }
                }
                this->str = firstV.str + "除" + secondV.str;
                break;
        }
    }

    virtual void Visit(NumberExpr *node) {
        int num = node->GetValue();
        do {
            this->str = static_cast<char>(num % 10 + '0') + this->str;
            num /= 10;
        } while (num);
        this->level = 0;
    }
};

class CalcAffter : public Expr::IVistor {
public:
    CalcAffter(const string str2 = "") : str2(str2) {}
    string str;
    string str2;
    void Visit_2(BinaryExpr *node) {
        CalcAffter firstV,secondV;
        node->GetFirst()->Accept(&firstV);
        node->GetSecond()->Accept(&secondV);
        switch (node->GetOp()) {
            case BinaryOpt::PLUS :
                this->str = firstV.str + secondV.str + "+";
                break;
            case BinaryOpt::MINUS :
                this->str = firstV.str + secondV.str + "-";
                break;
            case BinaryOpt::MUTIL :
                this->str = firstV.str + secondV.str + "*";
                break;
            case BinaryOpt::DIVIDE :
                this->str = firstV.str + secondV.str + "/";
                break;
        }
    }

    virtual void Visit(BinaryExpr *node) {
        Visit_2(node);
        this->str = this->str2 + this->str;
    }

    virtual void Visit(NumberExpr *node) {
        int num = node->GetValue();
        do {
            this->str = static_cast<char>(num % 10 + '0') + this->str;
            num /= 10;
        } while (num);
    }
};

class CalcForm : public Expr::IVistor {
public:
    CalcForm(const string str2 = "    ") : str2(str2) , number(0) {}
    string str;
    string str2;
    int number;

    string operator* (const int& k) {
        string result = "";
        int x = k;
        while (x--) {
            result = result + this->str2;
        }
        return result;
    }
    virtual void Visit(BinaryExpr *node) {
        CalcForm firstV(this->str2), secondV(this->str2);
        firstV.number = this->number + 1;
        secondV.number = this->number + 1;
        node->GetFirst()->Accept(&firstV);
        node->GetSecond()->Accept(&secondV);
        switch (node->GetOp()) {
            case BinaryOpt::PLUS :
                this->str = "+{\n" + (*this * firstV.number) + firstV.str + ",\n" + (*this * secondV.number) + secondV.str + "\n" + (*this * this->number) + "}" ;
                break;
            case BinaryOpt::MINUS :
                this->str = "-{\n" + (*this * firstV.number) + firstV.str + ",\n" + (*this * secondV.number) + secondV.str + "\n" + (*this * this->number) + "}" ;
                break;
            case BinaryOpt::MUTIL :
                this->str = "*{\n" + (*this * firstV.number) + firstV.str + ",\n" + (*this * secondV.number) + secondV.str + "\n" + (*this * this->number)+ "}" ;
                break;
            case BinaryOpt::DIVIDE :
                this->str = "/{\n" + (*this * firstV.number) + firstV.str + ",\n" + (*this * secondV.number) + secondV.str + "\n" + (*this * this->number) + "}" ;
                break;
        }
    }

    virtual void Visit(NumberExpr *node) {
        int num = node->GetValue();
        do {
            this->str = static_cast<char>(num % 10 + '0') + this->str;
            num /= 10;
        } while (num);
    }
};

int main() {
    Expr *root = Parser("(* (- 5 2) (+ (* 1 1) (/ 4 2)))");
    //Expr *root = Parser("(/ (/ (+ 1 2) (- 4 5)) (/ 9 3))");
    //Expr *root = Parser("(- (/ 4 1) (+ 4 2))");
    
    CalcNumber ret;
    root->Accept(&ret);
    cout << ret.result << endl;
    
    CalcStr str;
    root->Accept(&str);
    cout << str.str << endl;
    
    CalcSet set;
    root->Accept(&set);
    cout << set.str << endl;
    
    CalcAffter aff("output : ");
    //CalcAffter aff;
    root->Accept(&aff);
    cout << aff.str << endl;
    
    //CalcForm formm;
    CalcForm formm("****");
    root->Accept(&formm);
    cout << formm.str << endl;
    
    return 0;
}
