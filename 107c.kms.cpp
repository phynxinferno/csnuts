//
// Created by phoenix on 16/11/23.
//
#include <bits/stdc++.h>
#include "string"
#include "algorithm"
using namespace std;
void printArray(int* arr, int startPos, int size) {
    cout << arr[startPos] << " ";
    if(startPos == size - 1) return;
    printArray(arr, startPos + 1, size);
}
int main() {
    int size;
    cin >> size;
    int arr[size];
    string elements;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    printArray(arr, 0, size);
}