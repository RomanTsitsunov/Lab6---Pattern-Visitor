#include "Variable.h"

Variable::Variable(std::string const& name) : name_(name)
{} //� ������������ ���� ������� �� ���

std::string const& Variable::name() const
{
    return name_;
} // ������ ����� ����������

double Variable::evaluate() const // ���������� ������������ ������ �����������
{
    return 0.0;
}

Expression* Variable::transform(CopySyntaxTree* tr) const
{
    return tr->transformVariable(this);
}