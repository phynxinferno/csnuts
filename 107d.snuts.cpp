//
// Created by phoenix on 16/11/23.
//
int* initArray() {
    int* arr = new int[10];
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}