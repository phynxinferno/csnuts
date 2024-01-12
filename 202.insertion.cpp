//
// Created by phoenix on 05/12/23.
//

/*
 * Change the comparison to < instead of >
Since elements in the original array are iterated on in order, and placement goes down the output array, the first equal element in the original array will also be the first equal element in the sorted array.
 */

#include "string"
#include "iostream"

using namespace std;

string planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus","Neptune"};