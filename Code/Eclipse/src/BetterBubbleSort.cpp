//============================================================================
// Name        : BetterBubbleSort.cpp
// Author      : Nathan Perkins
// Version     :
// Copyright   : No Copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool BetterBubbleSort(int array[], int size);
int main() {
	int k = 0;
	int array[] = {6,2,3,4,6,5};
	int size = 6;
	BetterBubbleSort(array,size);
	for(int i = 0; i<size;i++){
		cout<< array[i];
	}
	return 0;
}

bool BetterBubbleSort(int array[], int size){
	int count = size;
	bool sflag = true;
	// insert error checking here

	while (sflag){
		sflag = false;
		for (int j = 0; j<count-1;j++){
			if (array[j+1] < array[j]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				sflag = true;
			}
		}
		count--;
	}
	return true;
}
