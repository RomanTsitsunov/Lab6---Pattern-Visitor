#pragma once
#include "Expression.h"
#include <string>

class Variable : // ��������� ������������
    public Expression
{
public:
    Variable(std::string const& name); //� ������������ ���� ������� �� ���
    std::string const& name() const; // ������ ����� ����������
    double evaluate() const; // ���������� ������������ ������ �����������
    Expression* transform(CopySyntaxTree* tr) const;
private:
    std::string const name_; // ��� ����������
};