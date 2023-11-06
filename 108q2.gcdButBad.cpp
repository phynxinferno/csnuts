//
// Created by phoenix on 06/11/23.
//
#include <iostream>
#include <cmath>

using namespace std;

int getLine() {
    int line;
    cin >> line;
    return line;
}

int gcd(int x, int y) {
    return (y == 0) ? x : gcd(y, x % y);
}

int main(int argc, char** argv) {
    cout << gcd(getLine(), getLine());
}