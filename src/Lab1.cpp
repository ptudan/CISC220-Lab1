//Lab 1 - Dalton Ashley and Paul Tudan
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
int collatz(int num);
void callCollatz();
bool pointerSort(int *a, int *b, int *c);
bool perfectNum(int cur, int sum, int orig);
bool refSort(int &a, int &b, int &c);
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
void reverseArray(int arr[], int size);
int minimumArray(int arr[], int size);
int sumArray(int arr[], int size);
int sortArray(int arr[], int size);
void filterArray(int arr[], int window, int size);
void createMatrix(int ***&arr, int &x, int &y, int &z);
void printMatrix(int ***&arr, int x, int y, int z);

int main() {
	srand(time(NULL));
	//Problem 1
	cout<<"Problem 1: "<<endl;
	cout<<"Hello World"<<endl;
	
	//Problem 2a
	cout<<" "<<endl;
	cout<<"Problem 2a: "<<endl;
	cout<<"Enter a number for the Collatz Conjecture: "<<endl;
	string input;
	cin >> input;
	int collatzNum = atoi(input.c_str());
	cout<<"The collatz conjecture for "<< collatzNum<< " is "<< collatz(collatzNum)<<endl;
	
	//Problem 2b
	cout<<" "<<endl;
	cout<<"Problem 2b: "<<endl;
	callCollatz();
	
	//Problem 3
	cout<<" "<<endl;
	cout<<"Problem 3: "<<endl;
	int first = rand()%100;
	int second = rand()%100;
	int third = rand()%100;
	cout<<"first: "<< first << " second: "<< second << " third: "<< third<<endl;
	if(pointerSort(&first, &second, &third)){//checks if already sorted
	}//if
	else{
		cout<<"Resorting... "<<endl;
		cout<<"first: "<< first << " second: "<< second << " third: "<< third<<endl;
	}//else
	
	//Problem 4
	cout<<" "<<endl;
	cout<<"Problem 4: "<<endl;
	for(int i = 3; i<31; i++){
		if(perfectNum(i-1, 0, i)){
			cout<<i<<" is a perfect number."<<endl;
		}//if
		else{
			cout<<i<< " is not a perfect number."<<endl;
		}//else
	}//for
	
	//Problem 5
	cout<<" "<<endl;
	cout<<"Problem 5: "<<endl;
	int d = rand()%100;
	int e = rand()%100;
	int f = rand()%100;
	cout<<"d: "<< d << " e: "<< e << " f: "<< f<<endl;
	if(refSort(d, e, f)){
	}//if
	else{
		cout<<"d: "<< d << " e: "<< e << " f: "<< f<<endl;
	}//else
	
	//Problem 6
	cout<<" "<<endl;
	cout<<"Problem 6: "<<endl;
	int arrSize = rand()%30 + 20;
	int arrP6[arrSize];
	fillArray(arrP6, arrSize);
	printArray(arrP6, arrSize);
	
	//Problem 7
	cout<<" "<<endl;
	cout<<"Problem 7: "<<endl;
	reverseArray(arrP6, arrSize);
	printArray(arrP6, arrSize);
	
	//Problem 8
	cout<<" "<<endl;
	cout<<"Problem 8: "<<endl;
	cout<<"The min value in this array is: " << minimumArray(arrP6, arrSize)<<endl;
	
	//Problem 9
	cout<<" "<<endl;
	cout<<"Problem 9: "<<endl;
	cout<<"The sum of this array is: "<< sumArray(arrP6, arrSize)<<endl;
	
	//Problem 10
	cout<<" "<<endl;
	cout<<"Problem 10: "<<endl;
	cout<<"Number of comparisons: "<<sortArray(arrP6, arrSize)<<endl;
	printArray(arrP6, arrSize);
	
	//Problem 11
	cout<<" "<<endl;
	cout<<"Problem 11: "<<endl;
	int arrP11[30];
	fillArray(arrP11, 30);
	for(int i = 0; i<30; i++){
		cout<<arrP11[i]<<' ';
	}//for
	cout<<" "<<endl;
	int window = rand()%5 + 3;
	filterArray(arrP11, window, 30);
	for(int i = 0; i<30; i++){
		cout<<arrP11[i]<<' ';
	}//for
	
	//Problem 12
	cout<<" "<<endl;
	cout<<"Problem 12: "<<endl;
	int x = -1;
	int y = -1;
	int z = -1;
	int ***threeDim = NULL;
	createMatrix(*&threeDim, x, y, z);
	printMatrix(*&threeDim, x, y, z);
	
	
	
}

int collatz(int num){
	int count = 0;
	while(num!=1){
		if(num%2 == 0){//checks for even
			count+=1;
			num = num/2;
		}//if
		else{
			count+=1;
			num = (3*num) + 1;
		}//else
	}//while
	return count;
}//collatz

void callCollatz(){
	cout<<"Enter a bound: "<<endl;//gets lower bound
	string input;
	cin >> input;
	int a = atoi(input.c_str());
	cout<<"Enter a bound: "<<endl; //gets upper bound
	string input2;
	cin >> input2;
	int b = atoi(input2.c_str());
	
	int upper;
	int lower;
	if(a>b){
		upper = a;
		lower = b;
	}//if
	else{
		upper = b;
		lower = a;
	}//else
	
	for(int i = 0; i<upper-lower; i++){//calls collatz for all numbers requested
		cout<<"The collatz conjecture for "<< lower+ i<< " is "<< collatz(lower+i)<<endl;
	}//for
}//callCollatz

bool pointerSort(int *a, int *b, int *c){
	if(*a<*b && *b<*c){
		return true;
	}//if
	else{
		if(*a>*c){
			int temp = *c;
			*c = *a;//swaps nums if a larger than c
			*a = temp;
		}//if
		else if(*a>*b){
			int temp = *b;
			*b = *a;//swaps nums if a larger than b
			*a = temp;
		}//else if
		
		if(*b>*c){
			int temp = *b;
			*b = *c;//swaps nums if b larger than c
			*c = temp;
		}//if
		else if(*a>*b){
			int temp = *b;
			*b = *a;//swaps nums if a larger than b
			*a = temp;
		}//else if
		
		return false;
	}//else
}//pointerSort

bool perfectNum(int cur, int sum, int orig){
	if(cur==0){
		return true && (sum==orig);//base case, checks if sum of multiples = original val
	}//if
	else{
		if(orig%cur == 0){
			sum += cur;//adds current value to sum of multiples if multiple
		}//if
		return true && perfectNum(cur-1, sum, orig);//recusive step
	}//else
}//perfectNum

bool refSort(int &a, int &b, int &c){
	if(a<b && b<c){
		return true;
	}//if
	else{
		if(a>c){
			int temp = c;
			c = a;
			a = temp;
		}//if
		else if(a>b){
			int temp = b;
			b = a;
			a = temp;
		}//else if
		
		if(b>c){
			int temp = b;
			b = c;
			c = temp;
		}//if
		else if(a>b){
			int temp = b;
			b = a;
			a = temp;
		}//else if
		
		return false;
	}//else
}//refSort

void fillArray(int arr[], int size){
	for(int i = 0; i<size; i++){
		arr[i] = rand()%101 - 50;//adds random number to position i from -50 - 50
	}//for
}//fillArray

void printArray(int arr[], int size){
	for(int i = 0; i<size; i++){
		cout<<arr[i]<<' ';
	}//for
	cout<<""<<endl;
}//printArray

void reverseArray(int arr[], int size){
	for(int i = 0; i<size/2; i++){
		int temp = arr[i];
		arr[i] = arr[(size - i -1)];//swaps positions based on reciprocal
		arr[(size - i -1)] = temp;
	}//for
}//reverseArray

int minimumArray(int arr[], int size){
	int min = arr[0];
	for(int i = 0; i<size; i++){
		if(arr[i]<min){
			min = arr[i];//if val is lower than current min, sets to min
		}//if
	}//for
	return min;
}//miniumArray

int sumArray(int arr[], int size){
	if(size == 1){
		return arr[0];//base case
	}//if
	else{
		return arr[0] + sumArray(&arr[1], size-1);//recursive step, starts at pos1 after adding pos0
	}//else
}//sumArray

int sortArray(int arr[], int size){
	int count = 0;
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size-i; j++){
			if(arr[i]>arr[j+i]){//checks if is larger than j, only does j+i to ignore sorted vals
				int temp = arr[i];
				arr[i] = arr[j+i];
				arr[j+i] = temp;
			}//if
			count +=1;
		}//for
	}//for
	return count;
}//sortArray

void filterArray(int arr[], int window, int size){
	if(window%2 == 0){
		window+=1;//sets even window to odd
	}//if
	cout<<"window size: "<< window<<endl;
	
	int copy[size];
	for(int i = 0; i<size; i++){
		copy[i] = arr[i];//creates copy to compare to combat dynamic adjusting
	}//for
	
	for(int i = 0; i<size; i++){
		if(i<window/2){
			arr[i] = 0;//sets edge vals to 0
		}//if
		else if(i>=size-window/2){
			arr[i] = 0;//sets edge vals to 0
		}//else if
		else{
			int sum = 0;
			for(int j = 0; j<window; j++){
				if(j<=window/2){
					sum += copy[i-j];//sums vals to left of current	
				}//if
				else{
					sum += copy[i+j - window/2];//sums vals to right including current
				}//else
			}//for
			arr[i] = sum/window;//edits array with new value
		}//else
	}//for
}//filterArray

void createMatrix(int ***&arr, int &x, int &y, int &z){
	x = rand()%5 + 2;//makes x, y, z 2-6 with rand
	y = rand()%5 + 2;
	z = rand()%5 + 2;
	
	arr = new int **[x];//creates rows
	
	for(int i=0; i<x; i++){
		arr[i] = new int *[y];//creates columns
	}//for
	
	for(int i=0; i<x; i++){
		for(int j = 0; j<y; j++){
			arr[i][j] = new int[z];//creates depthness
		}//for
	}//for
	
	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
			for(int k = 0; k<z; k++){
				arr[i][j][k] = i+j+k;//sets values
			}//for
		}//for
	}//for
	
}//createMatrix

void printMatrix(int ***&arr, int x, int y, int z){
	for(int i = 0; i<z; i++){
		for(int j = 0; j<y; j++){
			for(int k = 0; k<x; k++){
				cout<<arr[k][j][i]<<' ';
			}//for
			cout<<""<<endl;
		}//for
		cout<<"--------------------------"<<endl;
	}//for
	
	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
				delete [] arr[i][j];//deletes depth
		}//for
		delete [] arr[i];//deletes columns
	}//for
	delete []arr;//deletes rows
}//printMatrix
