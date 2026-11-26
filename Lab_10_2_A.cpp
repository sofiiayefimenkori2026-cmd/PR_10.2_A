// Lab_10_2_A.cpp
// Єфіменко Софія
// Лабораторна робота № 10.2 (Рівень А)
// Головний модуль програми (текстове меню)
// Варіант 8

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#if defined(_WIN32)
#include <Windows.h>
#endif

#include "student.h"
#include "io.h"
#include "sort_search.h"

using namespace std;

int main() {
#if defined(_WIN32)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    int N;
    cout << "Введіть кількість студентів N: ";
    cin >> N;

    if (N <= 0) {
        cout << "Кількість студентів має бути більшою за 0!" << endl;
        return 1;
    }

    Student* p = new Student[N];
    int* I = nullptr;

    int menuItem;
    do {
        cout << "\n================= МЕНЮ =================" << endl;
        cout << "  [1] - Введення даних з клавіатури" << endl;
        cout << "  [2] - Вивід даних на екран" << endl;
        cout << "  [3] - Фізичне впорядкування даних" << endl;
        cout << "  [4] - Бінарний пошук студента" << endl;
        cout << "  [5] - Індексне впорядкування та вивід" << endl;
        cout << "  [0] - Вихід та завершення роботи" << endl;
        cout << "========================================" << endl;
        cout << "Ваш вибір: ";
        cin >> menuItem;

        switch (menuItem) {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            Sort(p, N);
            cout << "\nМасив успішно фізично впорядковано (курс зрост. -> інформатика зрост. -> прізвище спад.):" << endl;
            Print(p, N);
            break;
        case 4: {
            string searchPrizv;
            int searchKurs, searchMark;
            cout << "\n--- Бінарний пошук студента ---" << endl;
            cout << "Введіть прізвище: ";
            getline(cin >> ws, searchPrizv);
            cout << "Введіть курс: ";
            cin >> searchKurs;
            cout << "Введіть оцінку з інформатики: ";
            cin >> searchMark;

            int foundIdx = BinSearch(p, N, searchPrizv, searchKurs, searchMark);
            if (foundIdx != -1) {
                cout << "\nСтудента ЗНАЙДЕНО під номером " << foundIdx + 1 << " у впорядкованому масиві:" << endl;
                cout << "  Прізвище:      " << p[foundIdx].prizv << endl;
                cout << "  Курс:          " << p[foundIdx].kurs << endl;
                cout << "  Спеціальність: " << specStr[p[foundIdx].spec] << endl;
                cout << "  Інформатика:   " << p[foundIdx].informatyka << endl;
            } else {
                cout << "\nСтудента із зазначеними даними НЕ знайдено (переконайтеся, що масив попередньо впорядковано [3])!" << endl;
            }
            break;
        }
        case 5:
            delete[] I;
            I = IndexSort(p, N);
            cout << "\nРезультат індексного впорядкування:" << endl;
            PrintIndexSorted(p, I, N);
            break;
        case 0:
            cout << "\nЗавершення роботи програми." << endl;
            break;
        default:
            cout << "Помилкове значення! Виберіть номер від 0 до 5." << endl;
            break;
        }
    } while (menuItem != 0);

    delete[] I;
    delete[] p;
    return 0;
}
