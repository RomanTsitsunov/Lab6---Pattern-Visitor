#pragma once
#include "Expression.h"
#include <string>

class FunctionCall : // структура «Вызов функции»
    public Expression
{
public:
    // в конструкторе надо учесть имя функции и ее аргумент
    FunctionCall(std::string const& name, Expression const* arg);
        // разрешены только вызов sqrt и abs
    std::string const& name() const;
    Expression const* arg() const; // чтение аргумента функции
    ~FunctionCall(); // освобождаем память в деструкторе
    Expression* transform(CopySyntaxTree* tr) const;
    virtual double evaluate() const; // либо модуль — остальные функции запрещены
private:
    std::string const name_; // имя функции
    Expression const* arg_; // указатель на ее аргумент
};