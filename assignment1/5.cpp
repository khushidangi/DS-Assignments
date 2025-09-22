#include <iostream>
using namespace std;

const int MAX = 10;

void sum(int mat[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < cols; j++)
        {
            row_sum += mat[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << row_sum << endl;
    }

    cout << endl;

    for (int j = 0; j < cols; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < rows; i++)
        {
            col_sum += mat[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << col_sum << endl;
    }
}

int main()
{
    int mat1[MAX][MAX] = {{1, 2}, {3, 4}};
    sum(mat1, 2, 2);
}