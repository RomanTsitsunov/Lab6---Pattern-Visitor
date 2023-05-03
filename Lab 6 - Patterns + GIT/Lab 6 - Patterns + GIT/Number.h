#include "Expression.h"

class Number : // ��������� ������
    public Expression
{
public:
    Number(double value); //�����������
    double value() const; // ����� ������ �������� �����
    double evaluate() const; // ���������� ������������ ������ �����������
    Expression* transform(CopySyntaxTree* tr) const;
    virtual ~Number(); //����������, ���� �����������
private:
    double value_; // ���� ������������ �����
};
