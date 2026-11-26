// sort_search.h
// Єфіменко Софія
// Лабораторна робота № 10.2 (Рівень А)
// Заголовочний файл модуля сортування та бінарного пошуку
// Варіант 8

#pragma once
#include <string>
#include "student.h"

bool ShouldPrecede(const Student& a, const Student& b);
void Sort(Student* p, const int N);
int* IndexSort(const Student* p, const int N);
int CompareStudents(const Student& s, int kurs, int infMark, const std::string& prizv);
int BinSearch(const Student* p, const int N, const std::string& prizv, const int kurs, const int infMark);
