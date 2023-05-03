#include "CopySyntaxTree.h"

Expression* CopySyntaxTree::transformNumber(Number const* number)
{
    return new Number(number->evaluate());
}

Expression* CopySyntaxTree::transformBinaryOperation(BinaryOperation const* binop)
{
    return new BinaryOperation(binop->left(), binop->operation(), binop->right());
}

Expression* CopySyntaxTree::transformFunctionCall(FunctionCall const* fcall)
{
    return new FunctionCall(fcall->name(), fcall->arg());
}

Expression* CopySyntaxTree::transformVariable(Variable const* var)
{
    return new Variable(var->name());
}