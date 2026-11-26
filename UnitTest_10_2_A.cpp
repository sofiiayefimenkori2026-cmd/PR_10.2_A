#if defined(_MSC_VER)
#include "pch.h"
#include "CppUnitTest.h"
#include "sort_search.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102A
{
    TEST_CLASS(UnitTest102A)
    {
    public:
        TEST_METHOD(TestSortAndSearch)
        {
            const int N = 3;
            Student students[N] = {
                { "Бойко", 2, KN, 4, 4, 5 },
                { "Коваль", 1, IN, 5, 5, 4 },
                { "Шевченко", 2, KN, 5, 5, 5 }
            };

            int* I = IndexSort(students, N);
            Assert::AreEqual(1, I[0]);
            Assert::AreEqual(2, I[1]);
            Assert::AreEqual(0, I[2]);
            delete[] I;

            Sort(students, N);
            Assert::AreEqual(std::string("Коваль"), students[0].prizv);
            Assert::AreEqual(std::string("Шевченко"), students[1].prizv);
            Assert::AreEqual(std::string("Бойко"), students[2].prizv);

            Assert::AreEqual(1, BinSearch(students, N, "Шевченко", 2, 5));
            Assert::AreEqual(-1, BinSearch(students, N, "Невідомий", 2, 5));
        }
    };
}
#else
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sort_search.h"

TEST_CASE("Тестування 10.2 (Рівень А)") {
    const int N = 3;
    Student students[N] = {
        { "Бойко", 2, KN, 4, 4, 5 },
        { "Коваль", 1, IN, 5, 5, 4 },
        { "Шевченко", 2, KN, 5, 5, 5 }
    };

    int* I = IndexSort(students, N);
    CHECK(I[0] == 1);
    CHECK(I[1] == 2);
    CHECK(I[2] == 0);
    delete[] I;

    Sort(students, N);
    CHECK(students[0].prizv == "Коваль");
    CHECK(students[1].prizv == "Шевченко");
    CHECK(students[2].prizv == "Бойко");

    CHECK(BinSearch(students, N, "Шевченко", 2, 5) == 1);
    CHECK(BinSearch(students, N, "Невідомий", 2, 5) == -1);
}
#endif
