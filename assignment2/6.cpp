#include <iostream>
using namespace std;

struct term {
    int row, col, val;
};

void show(term mat[], int count) {
    cout << "row col val" << endl;
    for (int i = 0; i < count; i++) {
        cout << mat[i].row << " " << mat[i].col << " " << mat[i].val << endl;
    }
}

int transpose(term mat[], term result[], int count) {
    for (int i = 0; i < count; i++) {
        result[i].row = mat[i].col;
        result[i].col = mat[i].row;
        result[i].val = mat[i].val;
    }
    return count;
}

int add(term a[], int countA, term b[], int countB, term result[]) {
    int i = 0, j = 0, k = 0;
    while (i < countA && j < countB) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col))
            result[k++] = a[i++];
        else if (b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col))
            result[k++] = b[j++];
        else {
            result[k] = a[i];
            result[k].val += b[j].val;
            k++; i++; j++;
        }
    }
    while (i < countA) result[k++] = a[i++];
    while (j < countB) result[k++] = b[j++];
    return k;
}

int multiply(term a[], int countA, term b[], int countB, term result[], int rowsA, int colsA, int colsB) {
    int k = 0;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int x = 0; x < countA; x++) {
                for (int y = 0; y < countB; y++) {
                    if (a[x].row == i && b[y].col == j && a[x].col == b[y].row)
                        sum += a[x].val * b[y].val;
                }
            }
            if (sum != 0) {
                result[k].row = i;
                result[k].col = j;
                result[k].val = sum;
                k++;
            }
        }
    }
    return k;
}

int main() {
    term a[10], b[10], res[20], t[20];
    int rowsA, colsA, rowsB, colsB;
    int termsA, termsB;
    int choice;

    cout << "Enter rows and columns for matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter number of non-zero terms in A: ";
    cin >> termsA;
    cout << "Enter row, col, val for each term of A:\n";
    for (int i = 0; i < termsA; i++) cin >> a[i].row >> a[i].col >> a[i].val;

    cout << "Enter rows and columns for matrix B: ";
    cin >> rowsB >> colsB;
    cout << "Enter number of non-zero terms in B: ";
    cin >> termsB;
    cout << "Enter row, col, val for each term of B:\n";
    for (int i = 0; i < termsB; i++) cin >> b[i].row >> b[i].col >> b[i].val;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Show matrix A\n";
        cout << "2. Show matrix B\n";
        cout << "3. Transpose A\n";
        cout << "4. Add A + B\n";
        cout << "5. Multiply A * B\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: show(a, termsA); break;
            case 2: show(b, termsB); break;
            case 3: {
                int countT = transpose(a, t, termsA);
                cout << "Transpose of A:\n";
                show(t, countT);
                break;
            }
            case 4: {
                if (rowsA != rowsB || colsA != colsB) {
                    cout << "Matrices must be same size for addition!\n";
                    break;
                }
                int countR = add(a, termsA, b, termsB, res);
                cout << "A + B:\n";
                show(res, countR);
                break;
            }
            case 5: {
                if (colsA != rowsB) {
                    cout << "Columns of A must equal rows of B for multiplication!\n";
                    break;
                }
                int countR = multiply(a, termsA, b, termsB, res, rowsA, colsA, colsB);
                cout << "A * B:\n";
                show(res, countR);
                break;
            }
            case 6: cout << "Exiting\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
