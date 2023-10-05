//
// Created by phoenix on 03/10/23.
//

// wow what a creative task im sure i'll never have to apply this knowledge ever

#include "iostream"
using namespace std;

int main(int argc, char** argv) {
    int number= 123;
    int* pnumber = &number;
    cout << number << pnumber << pnumber << *pnumber;
    int num1 = 50;
    int num2 = 100;
    int* pnum = NULL;
    pnum = &num1;
    *pnum += 10;
    cout << *pnum << *pnum;
    pnum = &num2;
    *pnum *= 10;
    num1 = num2;
    cout << num1 << &num1 << num1;
    double value1, value2 = 200000;
    double* lPtr = &value1;
    cout << *lPtr;
    value1 = value2;
    cout << value2 << value1 << lPtr << (&value1 == lPtr ? "yes" : "no") << endl;
    cout << *pnumber;
    return 0;
}