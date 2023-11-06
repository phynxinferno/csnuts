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

int main(int argc, char** argv) {
    const int order = getLine() - 1;
    cout << 3 - order * 2 << endl << -1 * pow(2,order);
}