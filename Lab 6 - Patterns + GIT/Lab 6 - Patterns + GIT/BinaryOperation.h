#pragma once
#include "Expression.h"

class BinaryOperation : // ЂЅинарна€ операци€ї
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
    // в конструкторе надо указать 2 операнда Ч левый и правый, а также сам символ операции
    BinaryOperation(Expression const* left, int op, Expression const* right);
    ~BinaryOperation(); //в деструкторе освободим зан€тую пам€ть
    Expression const* left() const; // чтение левого операнда
    Expression const* right() const; // чтение правого операнда
    int operation() const; // чтение символа операции
    double evaluate() const; // реализаци€ виртуального метода Ђвычислитьї
    Expression* transform(CopySyntaxTree* tr) const;
private:
    Expression const* left_; // указатель на левый операнд
    Expression const* right_; // указатель на правый операнд
    int op_; // символ операции
};