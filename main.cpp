//
//  main.cpp
//  лаба 7_2 сем 2
//
//  Created by Andrey Scherbakov on 26.02.2024.
//

#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;
int x, y, z;
bool Triangle(int x, int y, int z) {
    return (x + y > z) && (x + z > y) && (y + z > x);
}

int countTriangleSides(int n, ...) {
    va_list args;
    va_start(args, n);

    int count = 0;
    for (int i = 0; i < n - 2; ++i) {
        int side1 = va_arg(args, int);
        int side2 = va_arg(args, int);
        int side3 = va_arg(args, int);

        if (Triangle(side1, side2, side3)) {
            count++;
        }
    }

    va_end(args);
    return count;
}

int main() {
    cout<<"Введите числа: ";
    cin>>x>>y>>z;
    // Проверка для 3 чисел
    cout << "Можно ли построить треугольник из заданных чисел? " << (Triangle(x, y, z) ? "Да" : "Нет") << endl;

    // Проверка для 9 чисел
    int count9 = countTriangleSides(9, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    cout << "Количество троек рядом расположенных чисел типа int, которые могут быть длинами сторон треугольника: " << count9 << endl;

    // Проверка для 11 чисел
    int count11 = countTriangleSides(11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    cout << "Количество троек рядом расположенных чисел типа int, которые могут быть длинами сторон треугольника: " << count11 << endl;

    return 0;
}

