// io.h
// Єфіменко Софія
// Лабораторна робота № 10.2 (Рівень А)
// Заголовочний файл модуля введення та виведення даних
// Варіант 8

#pragma once
#include "student.h"

void Create(Student* p, const int N);
void PrintHeader();
void PrintRow(const Student& s, int rowNum);
void Print(const Student* p, const int N);
void PrintIndexSorted(const Student* p, const int* I, const int N);
