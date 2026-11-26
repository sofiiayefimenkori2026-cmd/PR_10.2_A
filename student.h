// student.h
// Єфіменко Софія
// Лабораторна робота № 10.2 (Рівень А)
// Модуль опису структур даних
// Варіант 8

#pragma once
#include <string>

// Перелік спеціальностей (Рівень А)
enum Spec { KN, IN, ME, FI, TN };

extern const std::string specStr[5];

// Структура студента (Рівень А: 3 предмети без об'єднання)
struct Student {
    std::string prizv;
    int kurs;
    Spec spec;
    int fizyka;
    int matematika;
    int informatyka;
};
