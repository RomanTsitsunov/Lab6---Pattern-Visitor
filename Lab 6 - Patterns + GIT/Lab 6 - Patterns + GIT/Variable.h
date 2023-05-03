#pragma once
#include "Expression.h"
#include <string>

class Variable : // структура «Переменная»
    public Expression
{
public:
    Variable(std::string const& name); //в конструкторе надо указать ее имя
    std::string const& name() const; // чтение имени переменной
    double evaluate() const; // реализация виртуального метода «вычислить»
    Expression* transform(CopySyntaxTree* tr) const;
private:
    std::string const name_; // имя переменной
};