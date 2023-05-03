#include "FunctionCall.h"
#include <cassert>

// � ������������ ���� ������ ��� ������� � �� ��������
FunctionCall::FunctionCall(std::string const& name, Expression const* arg) : name_(name), arg_(arg)
{
    assert(arg_);
    assert(name_ == "sqrt" || name_ == "abs");
}

// ��������� ������ ����� sqrt � abs
std::string const& FunctionCall::name() const
{
    return name_;
}

Expression const* FunctionCall::arg() const // ������ ��������� �������
{
    return arg_;
}

FunctionCall::~FunctionCall() { delete arg_; } // ����������� ������ � �����������

double FunctionCall::evaluate() const
{ // ���������� ������������ ������ �����������
    if (name_ == "sqrt")
        return sqrt(arg_->evaluate()); // ���� ��������� ������ ����������
    else return fabs(arg_->evaluate());
} // ���� ������ � ��������� ������� ���������

Expression* FunctionCall::transform(CopySyntaxTree* tr) const
{
    return tr->transformFunctionCall(this);
}