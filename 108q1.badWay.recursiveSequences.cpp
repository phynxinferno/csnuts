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

int t1(int prevTerm, const int* order) {
    int term = prevTerm -2;
    return (3 - *order * 2 == term) ? term : t1(term, order);
}
int t2(int prevTerm, const int* order) {
    int term = prevTerm * 2;
    return (-1 * pow(2,*order) == term) ? term : t2(term, order);
}
int main(int argc, char** argv) {
    const int order = getLine() - 1;
    cout << t1(3,&order) << endl << (int) t2(-1, &order);
}