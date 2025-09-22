#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int size_arr = 0;

void create_array() {
    cout << "Enter number of elements: ";
    cin >> size_arr;
    cout << "Enter " << size_arr << " elements:\n";
    for (int i = 0; i < size_arr; i++) {
        cin >> arr[i];
    }
}

void display_array() {
    if (size_arr == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size_arr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert_element() {
    int pos, val;
    cout << "Enter position (0 to " << size_arr << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;

    if (pos < 0 || pos > size_arr || size_arr == MAX) {
        cout << "Invalid position or array full!\n";
        return;
    }
    for (int i = size_arr; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size_arr++;
    cout << "Element inserted.\n";
}

void delete_element() {
    int pos;
    cout << "Enter position";
    cin >> pos;

    if (pos < 0 || pos >= size_arr) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < size_arr - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size_arr--;
    cout << "Element deleted.\n";
}

void linear_search() {
    int ele;
    cout << "Enter element to search: ";
    cin >> ele;
    for (int i = 0; i < size_arr; i++) {
        if (arr[i] == ele) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found!\n";
}

int main() {
    int choice;
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create_array(); 
            break;
            case 2: display_array(); 
            break;
            case 3: insert_element(); 
            break;
            case 4: delete_element(); 
            break;
            case 5: linear_search(); 
            break;
            case 6: cout << "Exiting\n"; break;
            default: cout << "Invalid choice\n";
        }

    return 0;
}
