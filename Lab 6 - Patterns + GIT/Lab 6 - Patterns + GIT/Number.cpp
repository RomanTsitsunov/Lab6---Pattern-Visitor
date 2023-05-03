#include "Number.h"

Number::Number(double value) : value_(value)
{} //конструктор

Number::~Number()
{} //деструктор, тоже виртуальный

double Number::value() const
{
	return value_;
} // метод чтения значения числа

double Number::evaluate() const
{
	return value_;
} // реализация виртуального метода «вычислить»

Expression* Number::transform(CopySyntaxTree* tr) const
{
	return tr->transformNumber(this);
}