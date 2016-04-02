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
#include <fstream>

using namespace std;

int BetterBubbleSort(int array[], int size);
bool IsSorted(int array[],int size);
void SortedPrint(int array[], int size);
void PrintArray(int array[], int size);
void GenerateArray(int array[], int size);
void GenerateOrderedArray(int array[],int size);
void GenerateReversedArray(int array[], int size);
bool SaveData(int value, int n, double time, char filename[]);

int main() {
	int size = 1000;
	int steps;
	//PrintArray(array,size);
	clock_t start;
	double duration;
	int i = 2;
	char filename[] = "BubbleSort.csv";
	while (i<size){
		int array[i];
		GenerateArray(array,i);
		start = clock();
		steps = BetterBubbleSort(array,i);
		duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
		SaveData(steps,i,duration, filename);
		//cout<<"Iteration: "<<i<<" Complete"<<endl;
		i++;
	}
	cout<<endl<<"Time Taken: "<< duration <<endl;
	cout<<"Number of steps = "<< steps<<"/"<<size*size/2<<endl;
	return 0;
}

int BetterBubbleSort(int array[], int size){
	int num_steps = 0;
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
				num_steps++;
			}
		}
		count--;
	}
	return num_steps;
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
void GenerateReversedArray(int array[], int size){
	srand(time(NULL));
	array[size-1] = 1;
	for(int i = size-2; i>=0;i--){
		int temp = rand()%10+array[i+1];
		array[i] = temp;
	}
}
bool SaveData(int num, int n, double time, char filename[]){
	ofstream myfile;
	myfile.open(filename,ios::app);
	if(myfile.is_open()){
		myfile<<n<<","<<num<<","<<time<<"\n";
		myfile.close();
		return true;
	}
	return false;
}
