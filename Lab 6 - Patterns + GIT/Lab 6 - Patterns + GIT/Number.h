#include "Expression.h"

class Number : // структура «Число»
    public Expression
{
public:
    Number(double value); //конструктор
    double value() const; // метод чтения значения числа
    double evaluate() const; // реализация виртуального метода «вычислить»
    Expression* transform(CopySyntaxTree* tr) const;
    virtual ~Number(); //деструктор, тоже виртуальный
private:
    double value_; // само вещественное число
};
