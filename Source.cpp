#include <iostream>
#include <iomanip>
#include<Windows.h>

const int MAX_SIZE = 100; //макс кол-во переменных

void gauss(double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], int n)
{
    //пр€мой ход 
    for (int i = 0; i < n; i++) 
    {
        //главный элемент
        for (int j = i + 1; j < n; j++) 
        {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k < n; k++) 
            {
                a[j][k] -= factor * a[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    //обратный ход
    double x[MAX_SIZE];
    for (int i = n - 1; i >= 0; i--) 
    {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) 
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    //вывод результатов
    std::cout << "–ешение слу:\n";
    for (int i = 0; i < n; i++) 
    {
        std::cout << "x" << i + 1 << " = " << std::fixed << std::setprecision(6) << x[i] << "\n";
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    std::cout << "¬ведите количество переменных:\n";
    std::cin >> n;

    // ќбъ€вление матрицы коэффициентов и массива свободных членов
    double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE];

    std::cout << "¬ведите коэффициенты матрицы и свободные члены:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            std::cin >> a[i][j];
        }
        std::cin >> b[i];
    }

    //решение
    gauss(a, b, n);
    std::cout << "—упер, брат! —Ћ” с кайфом решена:)";

    return 0;
}