//
// Created by phoenix on 03/10/23.
//
#include "iostream"
using namespace std;

int main(int argc, char** argv) {
    int value = 21;
    int* pointer = &value;
    cout << *pointer << " address: " << pointer << endl;
    return 0;
}