#include "BinaryOperation.h"
#include <cassert>

// � ������������ ���� ������� 2 �������� � ����� � ������, � ����� ��� ������ ��������
BinaryOperation::BinaryOperation(Expression const* left, int op, Expression const* right)
    : left_(left), op_(op), right_(right)
{
    assert(left_ && right_);
}

BinaryOperation::~BinaryOperation() //� ����������� ��������� ������� ������
{
    delete left_;
    delete right_;
}

Expression const* BinaryOperation::left() const
{
    return left_;
} // ������ ������ ��������

Expression const* BinaryOperation::right() const
{
    return right_;
} // ������ ������� ��������

int BinaryOperation::operation() const
{
    return op_;
} // ������ ������� ��������

double BinaryOperation::evaluate() const // ���������� ������������ ������ �����������
{
    double left = left_->evaluate(); // ��������� ����� �����
    double right = right_->evaluate(); // ��������� ������ �����
    switch (op_) // � ����������� �� ���� ��������, ����������, ��������,
        // ��� ����� ����� � ������ �����
    {
    case PLUS: return left + right;
    case MINUS: return left - right;
    case DIV: return left / right;
    case MUL: return left * right;
    }
}

Expression* BinaryOperation::transform(CopySyntaxTree* tr) const
{
    return tr->transformBinaryOperation(this);
}