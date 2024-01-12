//
// Created by phoenix on 10/01/24.
//

// linear and binary search

// took me a while to figure out it needed to round up in the pivot point calculation. Clarification would be appreciated.

#include <iostream>
#include <cmath>

using namespace std;

int getLine() {
    int line;
    cin >> line;
    return line;
}

void insert(int arr[], int size, int pos) {
//    if element is greater than its children, do nothing, otherwise, swap it with its largest child and keep trying until it's greater
    int largestIndex = pos;
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    if(left < size) {
        if(arr[left] > arr[largestIndex]) {
            largestIndex = left;
        }
        if(right < size && arr[right] > arr[largestIndex]) {
            largestIndex = right;
        }
    }
    if(largestIndex != pos) {
        swap(arr[pos], arr[largestIndex]);
        insert(arr, size, largestIndex);
    }
}

int main(int argc, char* argv[]) {
    int ln;
    // declare array and get length
    int* array = new int[ln = getLine()];
    // get search target
    int element = getLine();
    for(int i = 0; i < ln; i++)
        cin >> array[i];
    //    implements heapsort to consistently sort array in O(nlogn) time using a binary tree structure
    //    build heap
    for(int i = ln / 2 - 1; i >= 0; i--)
        insert(array, ln, i);
    //    swap in the rest of the array to result in a sorted array
    for(int i = ln - 1; i > 0; i--) {
        swap(array[0], array[i]);
        insert(array, i, 0);
    }
    // although it is possible to linear search an unsorted array, it's been moved under because the cboj task requires it.
    // search linearly for target
    cout << "Linear Search" << endl;
    for(int i = 0; i < ln; i++) {
        for(int j = i; j < ln; j++)
            cout << array[j] << " ";
        cout << endl;
        if(array[i] == element) {
            cout << "found at index " << i;
            break;
        } else if(i == ln - 1) {
            cout << "not found";
        }
    }
    cout << endl << endl << "Binary Search" << endl;
    // kbinary msearch s
    // define borders of search area and middle placeholder
    int start = 0, end = ln - 1, mid;
    while(true) {
        // log array
        for(int i = start; i <= end; i++)
            cout << array[i] << " ";
        cout << endl;
        // get middle index
        mid = ceil((start + end) / 2.0);
        // check element
        if(array[mid] == element) {
            cout << "found at index " << mid << endl;
            break;
        }
        if(start >= end) {
            cout << "not found" << endl;
            break;
        }
        // adjust borders
        else if(array[mid] < element) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return 0;
}