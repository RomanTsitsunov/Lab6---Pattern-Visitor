#include "Number.h"

Number::Number(double value) : value_(value)
{} //�����������

Number::~Number()
{} //����������, ���� �����������

double Number::value() const
{
	return value_;
} // ����� ������ �������� �����

double Number::evaluate() const
{
	return value_;
} // ���������� ������������ ������ �����������

Expression* Number::transform(CopySyntaxTree* tr) const
{
	return tr->transformNumber(this);
}