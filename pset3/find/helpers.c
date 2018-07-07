/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n > 0){
        //Binary Search [Best: O(1), Worst: O(logN)]
        int first = 0;
        int last = n-1;
        int middle;
        while (first <= last){
            middle = (first + last)/2;
            
            if (values[middle] == value)
                return true;
            else if (values[middle] < value)
                first = middle + 1;
            else
                last = middle -1;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    //Bubble Sort [Best: O(N), Worst: O(N^2)]
    int tmp;
    for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (values[j] > values[j + 1]) {
				tmp = values[j];
				values[j] = values[j+1];
				values[j+1] = tmp;
			}
		}
	}
    return;
}
