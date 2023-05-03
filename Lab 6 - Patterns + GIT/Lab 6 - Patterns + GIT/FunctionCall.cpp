#include "FunctionCall.h"
#include <cassert>

// в конструкторе надо учесть им€ функции и ее аргумент
FunctionCall::FunctionCall(std::string const& name, Expression const* arg) : name_(name), arg_(arg)
{
    assert(arg_);
    assert(name_ == "sqrt" || name_ == "abs");
}

// разрешены только вызов sqrt и abs
std::string const& FunctionCall::name() const
{
    return name_;
}

Expression const* FunctionCall::arg() const // чтение аргумента функции
{
    return arg_;
}

FunctionCall::~FunctionCall() { delete arg_; } // освобождаем пам€ть в деструкторе

double FunctionCall::evaluate() const
{ // реализаци€ виртуального метода Ђвычислитьї
    if (name_ == "sqrt")
        return sqrt(arg_->evaluate()); // либо вычисл€ем корень квадратный
    else return fabs(arg_->evaluate());
} // либо модуль Ч остальные функции запрещены

Expression* FunctionCall::transform(CopySyntaxTree* tr) const
{
    return tr->transformFunctionCall(this);
}