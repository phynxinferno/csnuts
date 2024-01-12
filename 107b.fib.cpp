//
// Created by phoenix on 16/11/23.
//
#include <bits/stdc++.h>

using namespace std;

int fib(int term) {
    switch(term) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fib(term - 1) + fib(term - 2);
    }
}

int main() {
    int ter;
    cin >> ter;
    cout << fib(ter);
}