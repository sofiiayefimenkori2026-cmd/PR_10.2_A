// io.cpp
// Єфіменко Софія
// Лабораторна робота № 10.2 (Рівень А)
// Реалізація функцій введення та табличного виведення (7 стовпців)
// Варіант 8

#include "io.h"
#include <iostream>
#include <iomanip>

using namespace std;

const string specStr[5] = {
    "Комп'ютерні науки",
    "Інформатика",
    "Математика та ек.",
    "Фізика та інф.",
    "Трудове навчання"
};

void Create(Student* p, const int N) {
    int ispec;
    for (int i = 0; i < N; i++) {
        cout << "\nСтудент № " << i + 1 << ":" << endl;

        cout << "  Прізвище: ";
        getline(cin >> ws, p[i].prizv);

        cout << "  Курс: ";
        cin >> p[i].kurs;

        cout << "  Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та ек., 3 - Фізика та інф., 4 - Трудове навчання): ";
        cin >> ispec;
        if (ispec < 0 || ispec > 4) ispec = 0;
        p[i].spec = (Spec)ispec;

        cout << "  Оцінка з фізики: ";
        cin >> p[i].fizyka;

        cout << "  Оцінка з математики: ";
        cin >> p[i].matematika;

        cout << "  Оцінка з інформатики: ";
        cin >> p[i].informatyka;
    }
}

void PrintHeader() {
    cout << "\n===================================================================================\n";
    cout << "| " << setw(3)  << right << "№"
         << " | " << setw(14) << left  << "Прізвище"
         << " | " << setw(4)  << right << "Курс"
         << " | " << setw(18) << left  << "Спеціальність"
         << " | " << setw(6)  << right << "Фізика"
         << " | " << setw(6)  << right << "Матем."
         << " | " << setw(8)  << right << "Інформ."
         << " |\n";
    cout << "-----------------------------------------------------------------------------------\n";
}

void PrintRow(const Student& s, int rowNum) {
    cout << "| " << setw(3)  << right << rowNum
         << " | " << setw(14) << left  << s.prizv
         << " | " << setw(4)  << right << s.kurs
         << " | " << setw(18) << left  << specStr[s.spec]
         << " | " << setw(6)  << right << s.fizyka
         << " | " << setw(6)  << right << s.matematika
         << " | " << setw(8)  << right << s.informatyka
         << " |\n";
}

void Print(const Student* p, const int N) {
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(p[i], i + 1);
    cout << "===================================================================================\n";
}

void PrintIndexSorted(const Student* p, const int* I, const int N) {
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(p[I[i]], i + 1);
    cout << "===================================================================================\n";
}
