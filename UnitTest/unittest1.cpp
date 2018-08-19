#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\isSupportSSE42\findMinIndex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			const unsigned int test1 = findMinIndex(16);
			const unsigned int test2 = findMinIndex(19);
			// const unsigned int test3 = findMinIndex(0xffffffff);
			// const unsigned int test4 = findMinIndex(-1);
			const unsigned int test5 = findMinIndex(0);

			Assert::AreEqual<int>(4, test1);
			Assert::AreEqual<int>(5, test2);
			// Assert::AreEqual<int>(0, test3);
			// Assert::AreEqual<int>(0, test4);
			Assert::AreEqual<int>(0, test5);

			Logger::WriteMessage("Shot tested.\n");
		}

	};
}