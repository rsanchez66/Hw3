#include <iostream>


using namespace std;


bool isSorted(const int arr[], int size) {
for (int i = 0; i < size - 1; ++i) {
if (arr[i] > arr[i + 1]) {
return false; // Array not sorted
}
}
return true; // Array sorted
}


int main() {
int arr1[] = {1, 2, 3, 4, 5};
int arr2[] = {5, 4, 3, 2, 1};
int arr3[] = {1, 3, 2, 5, 4};


cout << "arr1 is sorted: " << boolalpha << isSorted(arr1, 5) << endl;
cout << "arr2 is sorted: " << boolalpha << isSorted(arr2, 5) << endl;
cout << "arr3 is sorted: " << boolalpha << isSorted(arr3, 5) << endl;


return 0;
}