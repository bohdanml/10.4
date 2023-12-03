#include "pch.h"
#include "CppUnitTest.h"
#include "..\\10.4\lab.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:



        TEST_METHOD(TestCalculateDistance)
        {
            Point p1 = { 0.0, 0.0 };
            Point p2 = { 3.0, 4.0 };

            Assert::AreEqual(5.0, calculateDistance(p1, p2));
        }
    };
}