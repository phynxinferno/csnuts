//
// Created by phoenix on 20/11/23.
//
/*
 * 5 4 3 2 1
 * 120
 * 5*4*3*2 % 1 = 0
 * 5*4*3 % 2 = 0
 * 5*4 % 3 = 2
 *
 * 5*4*3*2 % 1 = 0
 * 5*4*3 % 2 = 0
 * 5*4 % 3 = 2
 *
 * 2 * 3  4 * 5 *  6 % 1 = 0
 * 3*4*5*6 % 2 = 0
 * 4*5*6 % 3 = 0
 * 5*6 % 4 = 2
 */

#include <iostream>
#include <numeric>

using namespace std;
int getLine() {
    int line;
    cin >> line;
    return line;
}

long fractorial(int* arr, int size, int position)  {
    if(position == size - 1) return lcm(arr[position], arr[position + 1]);
    return lcm(arr[position], fractorial(arr, size, position + 1));
}

long factorial(int* arr, long product, int position) {
    if(position < 1) return product;
    product *= position;
    arr[position - 1] = position;
    return factorial(arr, product, position - 1);
}

int main() {
    int n = getLine();
    if(n == 1) {
        cout << 1;
        return 0;
    }
    int arr[n];
    int factrl = factorial(arr, 1, n);
    cout << endl << fractorial(arr, n - 1, 0);
}