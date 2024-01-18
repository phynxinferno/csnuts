//
// Created by phoenix on 10/01/24.
//

//the horse is here(merge sort)

// only works in powers of 2 but is set up for implementing compatibility with other numbers later :3

/*
 * Accompanying Javascript tester functions

function randomListButReal(ln) {
	for(var list = ""; ln > 0; ln--)
		list += (Math.round(Math.random() * 1000) + " ");
	console.log(list);
}

function check(output) {
// add space to end of output before running
	let current = "";
	let last;
	for(let i = 0; i < output.length; i++) {
		if(output.charAt(i) === ' ') {
			if(parseInt(current) < parseInt(last)) return false;
			last = current;
			current = "";
		} else {
			current += ("" + output.charAt(i));
		}
	}
	return true;
}

 */

#include <iostream>
#include <cmath>

using namespace std;


int getLine() {
    int line;
    cin >> line;
    return line;
}

int main(int argc, char** argv) {
    // array-fetching stuff. not important.
    const int length = getLine();
    int arr[length];
    for(int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    // declare variables(explained later)
    int subperiod, bottomPosition, topPosition;

    // iterate over each period size until the one after it reaches >= length
    for(int period = 2; ceil(length / (double) (period/2)) != 1; period *= 2) {
        // declare subperiod
        subperiod = period / 2;

        // iterate over each period(i represents period number)
        for(int i = 0; i < ceil(length / (double) period); i++) {
            // set starting positions to merge into(second subperiod)
                topPosition = (bottomPosition = period * i) + subperiod -1;

                //iterate over elements of the second subperiod;
                for(int k = period * i + subperiod; k < period * (i+1); k++) {
                    // iterate over elements in first subperiod starting from the end
                    for(int j = topPosition; true; j--) {

                        // swap the element with the one after it if it's greater, starting with the element of the second subperiod's original position(the element after will always be the value of the original element of the second subperiod)
                        if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);

                        // if the element hasn't hit the bottom position but is in the right spot, move the bottom position to after it(element after it in its subperiod will always be greater)
                        else if(arr[j + 1] != arr[k]) {
                                bottomPosition = j + 2;
                                // increment top position to account for shift
                                topPosition++;

                                break;
                        }

                        // if it's hit the bottom position, move the bottom position to after it in a simpler manner.
                        if(j == bottomPosition) {
                            bottomPosition++;
                            // increment top position to account for shift
                            topPosition++;

                            break;
                        }

                    }

                }

            }


    }

    // print array :3
    for(int ele : arr) {
        cout << ele << " ";
    }

}

