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
bool SaveData(int num, int n, double time, char filename[]);

int main() {

	srand(time(NULL));
	int size = 2000;
	int repeat = 100;
	int steps;
	clock_t start;
	double duration;
	int i = 2;
	char filename[] = "BubbleSort.csv";
	char filename1[] = "BubbleSortOrdered.csv";
	char filename2[] = "BubbleSortReversed.csv";

	while (i<size){
		steps = 0;
		duration = 0.0;
		for(int j = 0;j<repeat;j++){
			int array[i];
			GenerateArray(array,i);
			start=clock();
			steps += BetterBubbleSort(array,i);
			duration += ( clock() - start)/(double) CLOCKS_PER_SEC;
			if(IsSorted(array,i)){
                if(j==0){
                    cout<<"Iteration "<< i << " sorted"<< endl;
                }
			}
		}
		steps = steps/repeat;
		duration = duration/(double)repeat;
		if(!SaveData(steps,i,duration, filename)){
			cout<<"Writing to file failed:"<<endl;
			cout<<"Number: "<<i<<endl;
			cout<<"Steps:  "<<steps<<endl;
			cout<<"Time:   "<<duration<<endl;
			break;
		}
		i++;
	}
	cout<<"Finished Writing Random to file"<<endl;
	i = 2;
	while (i<size){
		steps = 0;
		duration = 0.0;
		for(int j = 0;j<repeat;j++){
			int array[i];
			GenerateOrderedArray(array,i);
			start=clock();
			steps += BetterBubbleSort(array,i);
			duration += ( clock() - start)/(double) CLOCKS_PER_SEC;
            if(IsSorted(array,i)){
                if(j==0){
                    cout<<"Iteration "<< i << " sorted"<< endl;
                }
			}
		}
		steps = steps/repeat;
		duration = duration/(double)repeat;
		if(!SaveData(steps,i,duration, filename1)){
			cout<<"Writing to file failed:"<<endl;
			cout<<"Number: "<<i<<endl;
			cout<<"Steps:  "<<steps<<endl;
			cout<<"Time:   "<<duration<<endl;
			break;
		}
		i++;
	}
	cout<<"Finished Writing Ordered to file"<<endl;
	i = 2;
	while (i<size){
		steps = 0;
		duration = 0.0;
		for(int j = 0;j<repeat;j++){
			int array[i];
			GenerateReversedArray(array,i);
			start=clock();
			steps += BetterBubbleSort(array,i);
			duration += ( clock() - start)/(double) CLOCKS_PER_SEC;
            if(IsSorted(array,i)){
                if(j==0){
                    cout<<"Iteration "<< i << " sorted"<< endl;
                }
			}
		}
		steps = steps/repeat;
		duration = duration/(double)repeat;
		if(!SaveData(steps,i,duration, filename2)){
			cout<<"Writing to file failed:"<<endl;
			cout<<"Number: "<<i<<endl;
			cout<<"Steps:  "<<steps<<endl;
			cout<<"Time:   "<<duration<<endl;
			break;
		}
		i++;
	}
	cout<<"Finished Writing Reversed to file"<<endl;

	return 0;
}

int BetterBubbleSort(int array[], int size){
	int num_steps = 0; // This tracks the operation count
	int count = size-1;
	bool sflag = true;
	while (sflag){
		sflag = false;
		for (int j = 0; j<=count-1;j++){
			if (array[j+1] < array[j]){
				//Swap the 2 array elements
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				sflag = true;
			}
			num_steps++; //Increment the operation counter to indicate a comparison has been made
		}
		count--;
	}
	return num_steps; //Return the operation count
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
	for(int i = 0; i<size;i++){
		int temp = rand()%100+1;
		array[i] = temp;
	}
}
void GenerateOrderedArray(int array[], int size){
	array[0] = 1;
	for(int i = 1; i<size;i++){
		int temp = rand()%10+array[i-1];
		array[i] = temp;
	}
}
void GenerateReversedArray(int array[], int size){
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
bool SaveAllData(int num[], int n[], double time[], int size, char filename[]){
	for(int i = 0; i<size;i++){
		if(!SaveData(num[i],n[i],time[i],filename)){
			return false;
		}
	}
	return true;
}


