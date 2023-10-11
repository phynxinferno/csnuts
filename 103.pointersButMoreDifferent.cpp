//
// Created by phoenix on 11/10/23.
//

#include "iostream"
#include "math.h"
#include "algorithm"

using namespace std;

void cubeByPointer(double* num) {
    cout << pow(*num, 3) << endl;
}
void reduceTwoInt(int* num1, int* num2){
    const int gcd = __gcd(*num1, *num2);
    cout << *num1/gcd << "/" << *num2/gcd << endl;
}
void circle(int* radius, bool* pointer1, string* pointer2){
    cout << 2 * *radius * M_PI << endl << M_PI * pow(*radius, 2) << endl;
}
bool quadEquation(int* a, int* b, int* c, double* root1, double* root2){
    return pow(*b, 2) - 4 * *a * *c >= 0;
}
// the function in q5 swaps the values of the pointers as it swaps their addresses. The original variables are not affected as it doesn't change their values, only the values of the pointers.
void swap(float* p1, float* p2){
    float temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// not entirely sure what this code was supposed to do but i made it assign the values to specified pointers(&a shouldnt be a valid variable name). Also made use of the builtin math library.
void SquareComplex(double* a, double* b) {
// Squares a complex number a + bi
    *a = pow(*a,2) - pow(*b,2);
    *b = 2 * *a * *b;
}

int main(int argc, char* argv[]) {
    double cube = 5;
    cubeByPointer(&cube);
    int num1 = 10;
    int num2 = 20;
    reduceTwoInt(&num1, &num2);
    circle(&num1, nullptr, nullptr);
    int a = 1;
    cout << quadEquation(&a, &num1, &num2, nullptr, nullptr) << endl;
    float num3 = 1.5;
    float num4 = 2.5;
    swap(&num3, &num4);
    cout << num3 << endl << num4 << endl;
    return 0;
}

