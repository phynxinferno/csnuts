//
// Created by phoenix on 17/10/23.
//

#include "iostream"
#include "math.h"
using namespace std;
int getLine() {
    int line;
    cin >> line;
    return line;
}
// constructs a magic square of given order and magic constant
int main(int argc, char** argv) {
    cout << "help sos";
    // declare magic square properties
    const int order = /*getLine()*/3, tiles = pow(order, 2),add = (/*getLine()*/15 - order*(tiles + 1)/2)/order;
    int square[order][order];
    //int* array = new int[] {0,0,1,2,3,4};
    // fill square with empty values(nonzero values will be skipped)
    /*for(int i = 0; i < order - 1; i++) {
        for(int j = 0; j < order - 1; j++) {
            square[i][j] = 0;
        }
    }*/
    // set initial position and prepare iterator
    int column = order/2, row = 0, fills = 1;
    // iterate until square is full
    do {
        // fill square with next value and move according to the algorithm for a magic square of odd order
        if(square[row][column] != 0) continue;
        square[row][column] = fills + add;
        cout << fills++;
        if(row == 0) row = order - 1;
        else row--;
        if(column == order - 1) column = 0;
        else column++;
    } while(fills != tiles);
    // log square in a square
    for(int i = 0; i < order; i++){
        for(int j = 0; j < order; j++){
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
}