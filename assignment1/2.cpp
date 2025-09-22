#include <iostream>
using namespace std;

int main() {
	int size = 5;
    int arr[] = {1, 1, 3, 5, 7, 5};
    
    std::cout << "Create" << std::endl;
	for (int i = 0; i <= size; i++) {
        cout << arr[i] << endl;
    }

	for (int i = 0; i <= size; i++) {
		for (int j = i; j <= size; j++) {
			if (arr[j] == arr[i]) {
				arr[j] = arr[j+1];
			}
		}
	}
	
	cout << "Unique Elements" << endl;
	for (int i = 0; i <= size; i++) {
        cout << arr[i] << endl;
    }
    
	
}