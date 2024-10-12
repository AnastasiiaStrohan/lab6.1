#include "pch.h"
#include "CppUnitTest.h"
#include "../lb6.1/lb6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int n = 23;
            int arr[n];
            int Low = -19, High = 25;
            CreateArray(arr, n, Low, High);

            for (int i = 0; i < n; i++) {
                Assert::IsTrue(arr[i] >= Low && arr[i] <= High, L"Element is out of bounds!");
            }
        }

        
        TEST_METHOD(TestCountElements)
        {
            const int n = 5;
            int arr[n] = { 5, 8, -3, 12, 15 }; 
            int count = CountElements(arr, n);
            Assert::AreEqual(2, count, L"Incorrect count of elements.");
        }

       
        TEST_METHOD(TestSumElements)
        {
            const int n = 5;
            int arr[n] = { 5, 8, -3, 12, 15 }; 
            int sum = SumElements(arr, n);
            Assert::AreEqual(20, sum, L"Incorrect sum of elements.");
        }

        
        TEST_METHOD(TestReplaceWithZero)
        {
            const int n = 5;
            int arr[n] = { 5, 8, -3, 12, 15 };
            ReplaceWithZero(arr, n);

            Assert::AreEqual(0, arr[0], L"Element not replaced correctly.");
            Assert::AreEqual(8, arr[1], L"Element incorrectly modified.");
            Assert::AreEqual(0, arr[4], L"Element not replaced correctly.");
		}
	};
}
