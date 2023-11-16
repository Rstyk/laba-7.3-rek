
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Calculatenew(int** a, int** matrix, int n, int t, int q)
{
    int** Matrix = new int* [n];
    for (int i = 0; i < n; i++)
        Matrix[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0;
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int newRow = i + x;
                    int newCol = j + y;

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n)
                    {
                        sum += a[newRow][newCol];
                        count++;
                    }
                }
            }
            Matrix[i][j] = sum / count;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Matrix[i][j];

    for (int i = 0; i < n; i++)
        delete[] Matrix[i];
    delete[] Matrix;
}
void Create(int** a, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int n, int i, int j);
void Element(int** a, int n, int i, int j, int x, int y, int count);
void Calculatenew(int** a, int** matrix, int n, int t, int q);
int Sum(int** a, int n, int sum, int i, int j);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -30;
    int High = -1;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High, 0, 0);
    Print(a, n, 0, 0);

    int** Matrix = new int* [n];
    for (int i = 0; i < n; i++)
        Matrix[i] = new int[n];

    Calculatenew(a, Matrix, n, 0, 0);
    Print(a, n, 0, 0);

    int sum = Sum(a, n, 0, 0, 0);
    cout << "sum = " << sum << endl;

    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] Matrix[i];
    }
    delete[] Matrix;
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < n - 1)
        Create(a, n, Low, High, i, j + 1);
    else
        if (i < n - 1)
            Create(a, n, Low, High, i + 1, 0);
}

void Print(int** a, const int n, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j < n - 1)
        Print(a, n, i, j + 1);
    else if (i < n - 1)
    {
        cout << endl;
        Print(a, n, i + 1, 0);
    }
    else
        cout << endl << endl;
}

void Calculetenew(int** a, int n, int i, int j)
{
    if (i < n) {
        if (j < n) {
            Element(a, n, i, j, -1, -1, 0);
            Calculetenew(a, n, i, j + 1);
        }
        else {
            Calculetenew(a, n, i + 1, 0);
        }
    }
}

void Element(int** a, int n, int i, int j, int x, int y, int count)
{
    if (x <= 1) {
        if (y <= 1) {
            int newRow = i + x;
            int newCol = j + y;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n)
            {
                a[i][j] += a[newRow][newCol];
                count++;
            }
            Element(a, n, i, j, x, y + 1, count);
        }
        else
            Element(a, n, i, j, x + 1, -1, count);
    }
    if (count > 0)
        a[i][j] /= count;
}

int Sum(int** a, int n, int sum, int i, int j)
{
    if (i > j)
        sum += fabs(a[i][j]);
    if (j < n - 1)
        Sum(a, n, sum, i, j + 1);
    else
        if (i < n - 1)
            Sum(a, n, sum, i + 1, 0);
        else
            return sum;
}