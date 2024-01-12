//
// Created by phoenix on 31/10/23.
//

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int getLine() {
    int line;
    cin >> line;
    return line;
}
// constructs a magic square of given order and magic constant
int main() {
    // declare magic square properties
    const int order = 3, tiles = pow(order, 2),add = (15 - order*(tiles + 1)/2)/order;
    int square[order][order];
    memset(square, 0, sizeof(square));
    // set initial position and prepare iterator
    int column = order/2, row = order - 1, fills = 1;
    // iterate until square is full
    do {
        // fill square with next value and move according to the algorithm for a magic square of odd order
        if (column == -1 && row == order) {
            row = order - 1;
            column = 0;
        } else {
            if(order == row) row = 0;
            if(column < 0) column = order - 1;
        }
        if(square[column][row]) {
            row -= 2;
            column++;
            continue;
        };
        square[column][row] = fills + add;
        fills++;
        row++;
        column--;
    } while(fills != tiles + 1);
    // log square in a square

    for(int i = 0; i < order; i++){
        for(int j = 0; j < order; j++){
            cout << square[i][j] << " ";
        }
        cout << endl;
    }

}
