#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to read an array of integers from a file
void readArrayFromFile(string filename, int arr[], int& n)
{
    ifstream file(filename);
    file >> n;
    for (int i = 0; i < n; i++) {
        file >> arr[i];
    }
    file.close();
}

// Function to sort two arrays based on three-digit and two-digit numbers, respectively
void sortArrays(string filename1, string filename2)
{
    int arr1[1000], arr2[1000], n1, n2;

    // Read data from first file into array1
    readArrayFromFile(filename1, arr1, n1);

    // Read data from second file into array2
    readArrayFromFile(filename2, arr2, n2);

    // Sorting first array by three-digit numbers
    sort(arr1, arr1 + n1, [](int a, int b) {
        return a / 100 < b / 100;
    });

    // Sorting second array by two-digit numbers
    sort(arr2, arr2 + n2, [](int a, int b) {
        return a % 100 < b % 100;
    });

    // Printing sorted arrays
    cout << "Sorted array1: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Sorted array2: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}
