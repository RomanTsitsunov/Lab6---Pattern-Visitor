﻿#include <iostream>
#include <cassert>
#include <string>

struct Number;
struct BinaryOperation;
struct FunctionCall;
struct Variable;

struct Expression
{
public:
    virtual ~Expression()
    {}
    virtual double evaluate() const = 0;
};





struct Transformer //pattern Visitor
{
public:
    virtual ~Transformer()
    { }
    virtual Expression* transformNumber(Number const*) = 0;
    virtual Expression* transformBinaryOperation(BinaryOperation const*) = 0;
    virtual Expression* transformFunctionCall(FunctionCall const*) = 0;
    virtual Expression* transformVariable(Variable const*) = 0;
};





struct BinaryOperation : // «Бинарная операция»
    public Expression
{
public:
    enum
    { // перечислим константы, которыми зашифруем символы операций
        PLUS = '+',
        MINUS = '-',
        DIV = '/',
        MUL = '*'
    };

    // в конструкторе надо указать 2 операнда — левый и правый, а также сам символ операции
    BinaryOperation(Expression const* left, int op, Expression const* right)
        : left_(left), op_(op), right_(right)
    {
        assert(left_ && right_);
    }

    ~BinaryOperation() //в деструкторе освободим занятую память
    {
        delete left_;
        delete right_;
    }

    Expression const* left() const
    {
        return left_;
    } // чтение левого операнда

    Expression const* right() const
    {
        return right_;
    } // чтение правого операнда

    int operation() const
    {
        return op_;
    } // чтение символа операции

    double evaluate() const // реализация виртуального метода «вычислить»
    {
        double left = left_->evaluate(); // вычисляем левую часть
        double right = right_->evaluate(); // вычисляем правую часть
        switch (op_) // в зависимости от вида операции, складываем, вычитаем,
            // или делим левую и правую части
        {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case DIV: 
        {
            assert(right != 0);
            return left / right;
        }
        case MUL: return left * right;
        }
    }

    Expression* transform(Transformer* tr) const
    {
        return tr->transformBinaryOperation(this);
    }
private:
    Expression const* left_;
    Expression const* right_;
    int op_; // символ операции
};





struct FunctionCall : // структура «Вызов функции»
    public Expression
{
public:
    // в конструкторе надо учесть имя функции и ее аргумент
    FunctionCall(std::string const& name, Expression const* arg) : name_(name), arg_(arg)
    {
        assert(arg_);
        assert(name_ == "sqrt" || name_ == "abs");
    }

    // разрешены только вызов sqrt и abs
    std::string const& name() const
    {
        return name_;
    }

    Expression const* arg() const // чтение аргумента функции
    {
        return arg_;
    }

    ~FunctionCall()
    {
        delete arg_;
    } // освобождаем память в деструкторе

    virtual double evaluate() const
    { // реализация виртуального метода «вычислить»
        if (name_ == "sqrt")
        {
            assert(arg_->evaluate() >= 0);
            return sqrt(arg_->evaluate()); // либо вычисляем корень квадратный
        }
        else return fabs(arg_->evaluate());
    } // либо модуль — остальные функции запрещены

    Expression* transform(Transformer* tr) const
    {
        return tr->transformFunctionCall(this);
    }
private:
    std::string const name_; // имя функции
    Expression const* arg_; // указатель на ее аргумент
};





struct Number : // структура «Число»
    public Expression
{
public:
    Number(double value) : value_(value)
    {} //конструктор

    virtual ~Number()
    {} //деструктор, тоже виртуальный

    double value() const
    {
        return value_;
    } // метод чтения значения числа

    double evaluate() const
    {
        return value_;
    } // реализация виртуального метода «вычислить»

    Expression* transform(Transformer* tr) const
    {
        return tr->transformNumber(this);
    }
private:
    double value_; // само вещественное число
};





struct Variable : // структура «Переменная»
    public Expression
{
public:
    Variable(std::string const& name) : name_(name)
    {} //в конструкторе надо указать ее имя

    std::string const& name() const
    {
        return name_;
    } // чтение имени переменной

    double evaluate() const // реализация виртуального метода «вычислить»
    {
        return 0.0;
    }

    Expression* transform(Transformer* tr) const
    {
        return tr->transformVariable(this);
    }
private:
    std::string const name_; // имя переменной
};





struct CopySyntaxTree :
    public Transformer
{
public:
    Expression* transformNumber(Number const* number)
    {
        return new Number(number->evaluate());
    }

    Expression* transformBinaryOperation(BinaryOperation const* binop)
    {
        return new BinaryOperation(binop->left(), binop->operation(), binop->right());
    }

    Expression* transformFunctionCall(FunctionCall const* fcall)
    {
        return new FunctionCall(fcall->name(), fcall->arg());
    }

    Expression* transformVariable(Variable const* var)
    {
        return new Variable(var->name());
    }
};





struct FoldConstants : Transformer
{
    Expression* transformNumber(Number const* number)
    {
        return new Number(number->evaluate());
    }
    Expression* transformBinaryOperation(BinaryOperation const* binop)
    {
        return new Number(binop->evaluate());
    }
    Expression* transformFunctionCall(FunctionCall const* fcall)
    {
        return new Number(fcall->evaluate());
    }
    Expression* transformVariable(Variable const* var)
    {
        return new Variable(var->name());
    }
};





int main()
{
    Number* n32 = new Number(32.0);
    Number* n16 = new Number(16.0);
    BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS,
        n16);
    FunctionCall* callSqrt = new FunctionCall("sqrt", minus);
    BinaryOperation* mult = new BinaryOperation(n32, BinaryOperation::MUL,
        callSqrt);
    FunctionCall* callAbs = new FunctionCall("abs", mult);
    FoldConstants FC;
    Expression* newExpr = callAbs->transform(&FC);
    std::cout << newExpr->evaluate();
    double x1;
    Number* n1;
    CopySyntaxTree copy_n1;
}