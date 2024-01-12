//
// Created by phoenix on 22/11/23.
//
#include "iostream"
#include <cmath>

using namespace std;

int getLine() {
    int line;
    cin >> line;
    return line;
}

double average(int *arr, int size, int position, double start) {
    return (position == size - 1) ? start + arr[position] / ((double) size) : average(arr, size, position + 1,start + arr[position] / ((double) size));
}

int main() {
    //recursive average function
    int n = getLine();
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << round(average(arr, n, 0, 0.0) * 10) / 10.0;
}