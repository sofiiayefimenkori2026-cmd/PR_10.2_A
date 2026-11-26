// sort_search.cpp
// Єфіменко Софія
// Лабораторна робота № 10.2 (Рівень А)
// Реалізація фізичного, індексного сортування та бінарного пошуку
// Варіант 8

#include "sort_search.h"
#include <utility>

using namespace std;

// Умова впорядкування (Варіант 8, Рівень А):
// курс (зрост.) -> інформатика (зрост.) -> прізвище (спад.)
bool ShouldPrecede(const Student& a, const Student& b) {
    if (a.kurs != b.kurs)
        return a.kurs < b.kurs;
    if (a.informatyka != b.informatyka)
        return a.informatyka < b.informatyka;
    return a.prizv > b.prizv;
}

// Фізичне впорядкування (бульбашкове сортування з std::swap)
void Sort(Student* p, const int N) {
    for (int i0 = 0; i0 < N - 1; i0++) {
        bool swapped = false;
        for (int i1 = 0; i1 < N - i0 - 1; i1++) {
            if (ShouldPrecede(p[i1 + 1], p[i1])) {
                swap(p[i1], p[i1 + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Індексне впорядкування (сортування вставками)
int* IndexSort(const Student* p, const int N) {
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    for (int i = 1; i < N; i++) {
        int value = I[i];
        int j = i - 1;
        while (j >= 0 && ShouldPrecede(p[value], p[I[j]])) {
            I[j + 1] = I[j];
            j--;
        }
        I[j + 1] = value;
    }
    return I;
}

// Порівняння запису зі значенням ключа пошуку
int CompareStudents(const Student& s, int kurs, int infMark, const string& prizv) {
    if (s.kurs != kurs)
        return (s.kurs < kurs) ? -1 : 1;
    if (s.informatyka != infMark)
        return (s.informatyka < infMark) ? -1 : 1;
    if (s.prizv > prizv) return -1;
    if (s.prizv < prizv) return 1;
    return 0;
}

// Бінарний пошук у фізично впорядкованому масиві
int BinSearch(const Student* p, const int N, const string& prizv, const int kurs, const int infMark) {
    int L = 0, R = N - 1;
    while (L <= R) {
        int m = L + (R - L) / 2;
        int cmp = CompareStudents(p[m], kurs, infMark, prizv);
        if (cmp == 0)
            return m;
        if (cmp < 0)
            L = m + 1;
        else
            R = m - 1;
    }
    return -1;
}
