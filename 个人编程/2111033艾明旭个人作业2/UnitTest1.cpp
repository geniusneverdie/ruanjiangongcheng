#include "pch.h"
#include "CppUnitTest.h"
#include "11123.h"

#include <iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


bool AreEqual1(const std::vector<int>& a, bool b) {
    // 假设当向量为空时，我们期望的布尔值为false，否则为true
    bool vectorResult = !a.empty();
    return vectorResult == b;
}
namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(ProcessXTest_HandlesZeroInput)
        {
            std::vector<int> vec = { 0, 0, 0 };
            int k = 0;
            bool isInput = true;
            Assert::AreEqual(0, processx(vec, k, isInput));
        }

        TEST_METHOD(ProcessXTest_HandlesNonZeroInput)
        {
            std::vector<int> vec = { 1, 0, 1 };
            int k = 0;
            bool isInput = true;
            Assert::AreEqual(0, processx(vec, k, isInput));
        }
        TEST_METHOD(ProcessATest_HandlesZeroInput)
        {
            std::vector<int> vec = { 0, 0, 0 };
            int k = 0;
            bool isInput = true;
            Assert::AreEqual(0, process_A(vec, k, isInput));
        }

        TEST_METHOD(ProcessOTest_HandlesZeroInput)
        {
            std::vector<int> vec = { 0, 0, 0 };
            int k = 0;
            bool isInput = true;
            Assert::AreEqual(0, process_O(vec, k, isInput));
        }

        TEST_METHOD(ProcessNOTTest_HandlesZeroInput)
        {
            std::vector<int> vec = { 0 };
            int k = 0;
            bool isInput = true;
            Assert::AreEqual(1, process_NOT(vec, k, isInput));
        }

        TEST_METHOD(ProcessNANDTest_HandlesZeroInput)
        {
            std::vector<int> vec = { 0, 0, 0 };
            int k = 0;
            bool isInput = true;
            Assert::AreEqual(1, process_NAND(vec, k, isInput));
        }

        TEST_METHOD(ProcessNORTest_HandlesZeroInput)
        {
            std::vector<int> vec = { 0, 0, 0 };
            int k = 0;
            bool isInput = true;
            Assert::AreEqual(1, process_NOR(vec, k, isInput));
        }
        TEST_METHOD(DFSTest)
        {
            int u = 0;
            int k = 1;
            bool expectedOutput = true; // 假设你期望dfs函数返回true
            Assert::IsTrue(dfs(u, k) == expectedOutput);
        }

        TEST_METHOD(Tp)
        {
            int u = 0;
           // int k = 1;
            bool expectedOutput = true; // 假设你期望dfs函数返回true
            Assert::IsTrue(tp(u) == expectedOutput);
        }
    };
}
