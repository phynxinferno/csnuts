//
// Created by phoenix on 03/10/23.
//

// wow what a creative task im sure i'll never have to apply this knowledge ever

#include "iostream"
using namespace std;

int main(int argc, char** argv) {
    int value = 21;
    int* pointer = &value;
    cout << *pointer << " address: " << pointer << endl;
    return 0;
}