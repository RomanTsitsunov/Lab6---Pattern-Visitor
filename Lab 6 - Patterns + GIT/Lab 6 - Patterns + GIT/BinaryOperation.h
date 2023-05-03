#pragma once
#include "Expression.h"

class BinaryOperation : // ��������� ���������
    public Expression
{
public:
    enum
    { // ���������� ���������, �������� ��������� ������� ��������
        PLUS = '+',
        MINUS = '-',
        DIV = '/',
        MUL = '*'
    };
    // � ������������ ���� ������� 2 �������� � ����� � ������, � ����� ��� ������ ��������
    BinaryOperation(Expression const* left, int op, Expression const* right);
    ~BinaryOperation(); //� ����������� ��������� ������� ������
    Expression const* left() const; // ������ ������ ��������
    Expression const* right() const; // ������ ������� ��������
    int operation() const; // ������ ������� ��������
    double evaluate() const; // ���������� ������������ ������ �����������
    Expression* transform(CopySyntaxTree* tr) const;
private:
    Expression const* left_; // ��������� �� ����� �������
    Expression const* right_; // ��������� �� ������ �������
    int op_; // ������ ��������
};