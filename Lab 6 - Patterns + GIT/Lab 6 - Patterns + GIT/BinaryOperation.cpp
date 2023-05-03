#include "BinaryOperation.h"
#include <cassert>

// в конструкторе надо указать 2 операнда — левый и правый, а также сам символ операции
BinaryOperation::BinaryOperation(Expression const* left, int op, Expression const* right)
    : left_(left), op_(op), right_(right)
{
    assert(left_ && right_);
}

BinaryOperation::~BinaryOperation() //в деструкторе освободим занятую память
{
    delete left_;
    delete right_;
}

Expression const* BinaryOperation::left() const
{
    return left_;
} // чтение левого операнда

Expression const* BinaryOperation::right() const
{
    return right_;
} // чтение правого операнда

int BinaryOperation::operation() const
{
    return op_;
} // чтение символа операции

double BinaryOperation::evaluate() const // реализация виртуального метода «вычислить»
{
    double left = left_->evaluate(); // вычисляем левую часть
    double right = right_->evaluate(); // вычисляем правую часть
    switch (op_) // в зависимости от вида операции, складываем, вычитаем,
        // или делим левую и правую части
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