//============================================================================
// Name        : BetterBubbleSort.cpp
// Author      : Nathan Perkins
// Version     :
// Copyright   : No Copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool BetterBubbleSort(int array[], int size);
bool IsSorted(int array[],int size);
void SortedPrint(int array[], int size);
void PrintArray(int array[], int size);
void GenerateArray(int array[], int size);
void GenerateOrderedArray(int array[],int size);
int main() {
	int size = 100;
	int array[size];
	GenerateOrderedArray(array,size);
	PrintArray(array,size);
	clock_t start;
	double duration;
    start = clock();

    BetterBubbleSort(array,size);

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<endl<<"Time Taken: "<< duration <<'\n';


	PrintArray(array,size);
	SortedPrint(array, size);
	return 0;
}

bool BetterBubbleSort(int array[], int size){
	int count = size;
	bool sflag = true;
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

bool IsSorted(int array[], int size){
	for(int i=1;i<size;i++){
		if(array[i]<array[i-1]){
			return false;
		}
	}
	return true;
}
void SortedPrint(int array[], int size){
	cout<<endl;
	if (IsSorted(array,size)){
		cout<<"This array is sorted"<<endl;
	}
	else{
		cout<<"This array is not sorted"<<endl;
	}
}
void PrintArray(int array[],int size){
	for(int i = 0; i<size;i++){
		cout<< array[i]<< " ";
	}
}
void GenerateArray(int array[], int size){
	srand(time(NULL));
	for(int i = 0; i<size;i++){
		int temp = rand()%100+1;
		array[i] = temp;
	}
}
void GenerateOrderedArray(int array[], int size){
	srand(time(NULL));
	array[0] = 1;
	for(int i = 1; i<size;i++){
		int temp = rand()%10+array[i-1];
		array[i] = temp;
	}
}
