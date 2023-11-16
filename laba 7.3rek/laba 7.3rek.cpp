#include "pch.h"
#include "CppUnitTest.h"
#include "../laba 7.3 rek/laba 7.3 rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace laba73rek
{
	TEST_CLASS(laba73rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            
                int n = 3;
                int** a = new int* [n];
                for (int i = 0; i < n; i++)
                {
                    a[i] = new int[n];
                    for (int j = 0; j < n; j++)
                    {
                        a[i][j] = 1;
                    }
                }
                int t = Sum(a, n, 0, 0, 0);

                Assert::AreEqual(3, t);

                for (int i = 0; i < n; i++)
                    delete[] a[i];
                delete[] a;


		}
	};
}
