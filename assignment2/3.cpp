#include <iostream>
using namespace std;

void linearSearchMissing(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << "Missing Number is: " << i + 1 << endl;
            return;
        }
    }
}

void binarySearchMissing(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] != mid + 1)
        {
            if (mid == 0 || arr[mid - 1] == mid)
            {
                cout << "Missing Number is: " << mid + 1 << endl;
                return;
            }
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    linearSearchMissing(arr, size);
    binarySearchMissing(arr, size);
}