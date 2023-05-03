#pragma once
#include "CopySyntaxTree.h"

class Expression
{
public:
	virtual ~Expression();
	virtual double evaluate() const = 0;
};