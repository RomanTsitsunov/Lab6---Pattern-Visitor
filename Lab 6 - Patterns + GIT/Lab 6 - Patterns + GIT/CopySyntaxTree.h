#pragma once
#include "Transformer.h"

class CopySyntaxTree :
    public Transformer
{
public:
    Expression* transformNumber(Number const*);
    Expression* transformBinaryOperation(BinaryOperation const*);
    Expression* transformFunctionCall(FunctionCall const*);
    Expression* transformVariable(Variable const*);
};