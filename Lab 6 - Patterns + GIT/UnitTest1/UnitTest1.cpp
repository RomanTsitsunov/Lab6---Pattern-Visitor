#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6 - Patterns + GIT/Lab 6 - Patterns + GIT.cpp"
#include "random"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestBinOpPlus)
		{
			double x1, x2;
			Number* n1;
			Number* n2;
			BinaryOperation* plus;
			for (int i = 0; i < 10; i++)
			{
				x1 = rand() % 100;
				x2 = rand() % 100;
				n1 = new Number(x1);
				n2 = new Number(x2);
				plus = new BinaryOperation(n1, BinaryOperation::PLUS, n2);
				Assert::AreEqual(x1+x2, plus->evaluate());
			}
		}

		TEST_METHOD(TestSqrt)
		{
			double x1;
			Number* n1;
			FunctionCall* sqrtcall;
			for (int i = 0; i < 10; i++)
			{
				x1 = rand() % 100;
				n1 = new Number(x1);
				sqrtcall = new FunctionCall("sqrt", n1);
				Assert::AreEqual(sqrt(x1), sqrtcall->evaluate());
			}
		}
		
		TEST_METHOD(TestDiv)
		{
			double x1, x2;
			Number* n1;
			Number* n2;
			BinaryOperation* div;
			for (int i = 0; i < 10; i++)
			{
				x1 = rand() % 100 + 1.0;
				x2 = rand() % 100 + 1.0;
				n1 = new Number(x1);
				n2 = new Number(x2);
				div = new BinaryOperation(n1, BinaryOperation::DIV, n2);
				Assert::AreEqual(x1 / x2, div->evaluate());
			}
		}

		TEST_METHOD(TestCopyNumber)
		{
			double x1;
			Number* n1;
			CopySyntaxTree copy_n1;
			for (int i = 0; i < 10; i++)
			{
				x1 = rand() % 100;
				n1 = new Number(x1);
				Assert::IsTrue(n1->value()==n1->transform(&copy_n1)->evaluate());
			}
		}

		TEST_METHOD(TestFoldConstantsNumber)
		{
			double x1;
			Number* n1;
			FoldConstants fold_n1;
			for (int i = 0; i < 10; i++)
			{
				x1 = rand() % 100;
				n1 = new Number(x1);
				Assert::AreEqual(n1->evaluate(), n1->transform(&fold_n1)->evaluate());
			}
		}
	};
}
