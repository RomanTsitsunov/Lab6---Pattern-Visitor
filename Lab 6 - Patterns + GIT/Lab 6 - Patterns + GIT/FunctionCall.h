#pragma once
#include "Expression.h"
#include <string>

class FunctionCall : // ��������� ������ �������
    public Expression
{
public:
    // � ������������ ���� ������ ��� ������� � �� ��������
    FunctionCall(std::string const& name, Expression const* arg);
        // ��������� ������ ����� sqrt � abs
    std::string const& name() const;
    Expression const* arg() const; // ������ ��������� �������
    ~FunctionCall(); // ����������� ������ � �����������
    Expression* transform(CopySyntaxTree* tr) const;
    virtual double evaluate() const; // ���� ������ � ��������� ������� ���������
private:
    std::string const name_; // ��� �������
    Expression const* arg_; // ��������� �� �� ��������
};