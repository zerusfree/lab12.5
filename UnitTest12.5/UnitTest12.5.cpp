#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest125
{
	TEST_CLASS(UnitTest125)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* top = nullptr;
			int value = 10;

			push(top, value);

			Assert::IsNotNull(top);
			Assert::AreEqual(top->info, value);
			Assert::IsNull(top->link);

			delete top;
		}
	};
}
