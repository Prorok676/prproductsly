#include <iostream>
#include <iomanip>
#include<Windows.h>

const int MAX_SIZE = 100; //���� ���-�� ����������

void gauss(double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], int n)
{
    //������ ��� 
    for (int i = 0; i < n; i++) 
    {
        //������� �������
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

    //�������� ���
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

    //����� �����������
    std::cout << "������� ���:\n";
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
    std::cout << "������� ���������� ����������:\n";
    std::cin >> n;

    // ���������� ������� ������������� � ������� ��������� ������
    double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE];

    std::cout << "������� ������������ ������� � ��������� �����:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            std::cin >> a[i][j];
        }
        std::cin >> b[i];
    }

    //�������
    gauss(a, b, n);
    std::cout << "�����, ����! ��� � ������ ������:)";

    return 0;
}