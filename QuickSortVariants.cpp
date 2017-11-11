/*
	Mario Andres Rendon
	SID: 200370018
	Assignment # 6 - CS 340 

	Implement QuickSort, as explained in class, with varying pivot calculation methods and varying cutoffs. You
	may assume that all your input lists contain only integers, are duplicate-free, and are of length at most 100.

	pivot calculation methods: pivot = first list element, pivot = second list element, pivot = element at middle
	position of list, pivot = median-of-three (as explained in class)

	cutoffs: no cutoff, cutoff c = 5, cutoff c = 10, cutoff c = 20 (a cutoff here means an array size such that every
	array of size less than or equal to c will be sorted with Insertion Sort).

	Add a counter to your implementation. Every time a comparison of two list elements is made, the counter is
	increased by one (also in the Insertion Sort routine).
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Array {
public:
	// GENERIC FUNCTIONS
	Array() {
		size_of_arr = 0;
		comparisons = 0;
	}

	void buildArr(string filename) {
		ifstream inData;
		inData.open(filename);
		if (!inData) {
			cout << "ERROR - FILE NOT FOUND!" << endl;
		}

		while (!inData.eof()) {
			inData >> arr[size_of_arr];
			size_of_arr++;
		}
	}

	void swap(int *x, int *y) {
		int temp = *x;
		*x = *y;
		*y = temp;
	};

	void insertionsort(int a[], int left, int right) {
		
		for (int i = 1; i < right; ++i) {
			
			int temp = a[i];
			int j;

			for (j = i; j > 0 && temp < a[j - 1]; --j) {
				a[j] = a[j - 1];
				comparisons++;
			}
			comparisons++;
			a[j] = temp;
		}
	};

	void print() {
		cout <<"The number of comparisons Where: " << comparisons << endl; 
		cout << endl;
		for (int i = 0; i < size_of_arr; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << endl;
	};


	// QUICKSORT FUNCTIONS
	int medianOfThree(int a[], int left, int right) {

		int center = (left + right) / 2;

		if (a[center] < a[left])
			swap(&a[left], &a[center]);
		if (a[right] < a[left])
			swap(&a[left], &a[right]);
		if (a[right] < a[center])
			swap(&a[center], &a[right]);

		swap(&a[center], &a[right - 1]);
		return a[right - 1];
	}

	void quicksort(int a[], int left, int right, int cutOff, int choice) {
		
		if (left + cutOff <= right) {

			int pivot;

			switch (choice)
			{
				case 1: pivot = a[left]; break;
				case 2: pivot = a[left + 1]; break;
				case 3: pivot = a[(left + right) / 2]; break;
				case 4: pivot = medianOfThree(a, left, right); break;
				default: { cout << "INVALID PIVOT, USING MEDIAN OF THREE INSTEAD: \n"; pivot = medianOfThree(a, left, right);  break; }
			}

			

			int i = left;
			int j = right - 1;

			while(i <= j) {
				while (i <= right && a[i] < pivot) { i++; comparisons++; }
				while (j >= left && a[j] >= pivot) { j--; comparisons++; }
				if (i < j)
					swap(&a[i], &a[j]);
				else
					break;
			}

			swap(&a[i], &a[right - 1]);

			quicksort(a, left, i - 1, cutOff, choice);
			quicksort(a, i + 1, right, cutOff, choice);
		}
		else
			insertionsort(a, left, right);
	}



public:
	int size_of_arr;
	int arr[100];
	int comparisons;
};


int main() {

	cout << "Enter array file name: ";
	string file;
	getline(cin, file);
	Array A1;
	A1.buildArr(file);

	cout << "Enter Cutoff for insertionSort: ";
	int cut;
	cin >> cut;

	cout << "Enter one of the choices for pivot: first element = 1; second element = 2; middle element = 3; median-of-three = 4 : ";
	int choice;
	cin >> choice;
	cout << endl;
	A1.quicksort(A1.arr, 0, A1.size_of_arr, cut, choice);
	A1.print();
}