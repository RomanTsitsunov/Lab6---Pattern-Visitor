#include "Variable.h"

Variable::Variable(std::string const& name) : name_(name)
{} //в конструкторе надо указать ее имя

std::string const& Variable::name() const
{
    return name_;
} // чтение имени переменной

double Variable::evaluate() const // реализация виртуального метода «вычислить»
{
    return 0.0;
}

Expression* Variable::transform(CopySyntaxTree* tr) const
{
    return tr->transformVariable(this);
}